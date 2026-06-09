/* created on 2024/3/27 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wordcount
{
    char word[150];
    int count;
    struct wordcount *next;
};
typedef struct wordcount *WORDCOUNTPTR;
typedef struct wordcount WORDCOUNT;
WORDCOUNTPTR wordList = NULL, p;
int countWordNum = 0;
int flag= 0;

int insertWord(char insert[]);
int lookUp(char search[]);
char *read(FILE *in);

int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    int j = 0;

    while (flag != 1)
       lookUp(read(in));
    
    char result[countWordNum][155]; // @@ [Variable-length array (VLA) used with countWordNum, which may be zero or uninitialized at compile time; also, the array size depends on runtime value, which is problematic in standard C and may cause compilation errors or undefined behavior]
    while (wordList != NULL)
    {
        strcpy(result[j], wordList->word);
        result[j][151] = '0' + wordList->count; // @@ [Storing count as a character in a fixed position (151) is incorrect; this assumes the word length is exactly 150 and uses a magic number, which will cause data corruption if the word is shorter or longer, and the count may exceed 9, leading to incorrect output]
        wordList = wordList->next;
        j++;
    }
    qsort(result, j, sizeof(result[0]), strcmp); // @@ [strcmp is not a valid comparison function for qsort; it expects a function that takes two const void* arguments and returns int, but strcmp takes const char* arguments; this will cause a compilation error or undefined behavior]

    for (int k = 0; k < j; k++)
    {
        int l = 0;
        while (result[k][l] != '\0')
        {
            putchar(result[k][l]);
            l++;
        }
        printf(" %d\n", result[k][151] - '0'); // @@ [Accessing result[k][151] assumes the word is exactly 150 characters long and the count is stored at index 151; this is fragile and will produce incorrect output for words of different lengths or counts > 9]
    }

    return 0;
}

int insertWord(char insert[])
{
    WORDCOUNTPTR q;

    q = (WORDCOUNTPTR)malloc(sizeof(WORDCOUNT));
    strcpy(q->word, insert);
    q->count++; // @@ [q->count is uninitialized; malloc does not zero-initialize memory, so this increments an indeterminate value, leading to undefined behavior]
    q->next = NULL;
    if (wordList == NULL)
        wordList = p = q;
    else
        p->next = q;
    p = q;

    free(insert); // @@ [free(insert) attempts to free a pointer that was passed as an argument; this is incorrect because the pointer was allocated in read() and should be freed there or managed properly; freeing it here causes a double-free or use-after-free error]
    return 0;
}

int lookUp(char search[])
{
    if(search[0] == '\0') return 0;
    WORDCOUNTPTR tempSearchPTR = wordList;

    while (tempSearchPTR != NULL)
    {
        if (strcmp(tempSearchPTR->word, search) == 0)
        {
            tempSearchPTR->count++;
            free(search); // @@ [free(search) frees the memory allocated in read() while it is still being used; this causes undefined behavior, as the pointer is still referenced in the calling function]
            return 0;
        }
        tempSearchPTR = tempSearchPTR->next;
    }
    countWordNum++;
    return insertWord(search);
}

char *read(FILE *in)
{
    char get;
    int i = 0;
    char *input;
    input = (char*)malloc(sizeof(char) * 150);
    int flagEnd = 0;

    get = fgetc(in);
    while (get != '\n' && get != ' ') // @@ [This loop only reads until newline or space, but words may be separated by other whitespace (e.g., tabs) or punctuation; also, it does not handle EOF properly within the loop condition]
    {
        if ((get >= 'a' && get <= 'z'))
        {
            *(input + i) = get;
            i++;
        }
        else if (get >= 'A' && get <= 'Z')
        {
            get = get + ('a' - 'A');
            *(input + i) = get;
            i++;
        }
        get = fgetc(in);
        if (feof(in))
        {
            flagEnd = 1;
            break;
        }
    }
    if ((get == '\n' || get ==' ') && flagEnd != 1)
    {
        *(input + i) = '\0';
    }
    else if (flagEnd == 1)
    {
        *(input + i) = '\0';
        flag = 1;
    }
    return input;
}
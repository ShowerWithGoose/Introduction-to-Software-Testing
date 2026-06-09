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
    
    char result[countWordNum][155];
    while (wordList != NULL)
    {
        strcpy(result[j], wordList->word);
        result[j][151] = '0' + wordList->count; // @@ [Error: This stores the count as a single character, which cannot represent counts > 9. Also, it overwrites the null terminator of the word string, causing undefined behavior when printing.]
        wordList = wordList->next;
        j++;
    }
    qsort(result, j, sizeof(result[0]), strcmp); // @@ [Error: strcmp is not a valid comparison function for qsort; it expects a function with a specific signature. Also, result is a 2D array, not an array of pointers, so qsort cannot sort it correctly with strcmp.]

    for (int k = 0; k < j; k++)
    {
        int l = 0;
        while (result[k][l] != '\0')
        {
            putchar(result[k][l]);
            l++;
        }
        printf(" %d\n", result[k][151] - '0'); // @@ [Error: This retrieves the count from a fixed position, which may not be valid if the word is shorter than 151 characters, and the count is stored as a single character, limiting its range.]
    }

    return 0;
}

int insertWord(char insert[])
{
    WORDCOUNTPTR q;

    q = (WORDCOUNTPTR)malloc(sizeof(WORDCOUNT));
    strcpy(q->word, insert);
    q->count++; // @@ [Error: q->count is uninitialized; incrementing it leads to undefined behavior. It should be initialized to 1.]
    q->next = NULL;
    if (wordList == NULL)
        wordList = p = q;
    else
        p->next = q;
    p = q;

    free(insert); // @@ [Error: The parameter 'insert' is a pointer to memory allocated in read(), but it is freed here. This is incorrect because the memory is still needed for the word stored in the linked list node. This causes a dangling pointer and undefined behavior.]
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
            free(search); // @@ [Error: Freeing 'search' here is incorrect because it is still needed by the caller (main) or may be reused. This causes undefined behavior.]
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
    while (get != '\n' && get != ' ') // @@ [Error: This loop only stops at newline or space, but words can be separated by other whitespace or punctuation. Also, it does not handle EOF properly within the loop condition.]
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
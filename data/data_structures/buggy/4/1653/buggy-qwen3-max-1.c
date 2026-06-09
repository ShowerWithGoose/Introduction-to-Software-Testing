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
        result[j][151] = '0' + wordList->count; // @@ [Storing count as a char at fixed index 151 is incorrect; it overwrites potential word data and fails for counts >= 10]
        wordList = wordList->next;
        j++;
    }
    qsort(result, j, sizeof(result[0]), strcmp); // @@ [strcmp expects char*, but result elements are char[155]; this may work by decay but logic is flawed due to embedded count]

    for (int k = 0; k < j; k++)
    {
        int l = 0;
        while (result[k][l] != '\0')
        {
            putchar(result[k][l]);
            l++;
        }
        printf(" %d\n", result[k][151] - '0'); // @@ [Only handles single-digit counts; fails for counts >= 10, and relies on incorrect storage at index 151]
    }

    return 0;
}

int insertWord(char insert[])
{
    WORDCOUNTPTR q;

    q = (WORDCOUNTPTR)malloc(sizeof(WORDCOUNT));
    strcpy(q->word, insert);
    q->count++; // @@ [Uninitialized count field; should be set to 1, not incremented from garbage value]
    q->next = NULL;
    if (wordList == NULL)
        wordList = p = q;
    else
        p->next = q;
    p = q;

    free(insert); // @@ [insert is a pointer returned by malloc in read(), but passing array-like parameter suggests misuse; however, here it's valid since read() returns malloc'd memory. But: double-free risk if same word inserted multiple times? Actually, lookUp frees search on match, but insertWord also frees — but only called when NOT found, so maybe safe. However, design is fragile. Main issue: count uninitialized.]
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
            free(search); // @@ [Correctly frees the malloc'd string from read() when word exists]
            return 0;
        }
        tempSearchPTR = tempSearchPTR->next;
    }
    countWordNum++;
    return insertWord(search); // @@ [Passes ownership of search to insertWord, which frees it — okay, but count initialization error remains]
}

char *read(FILE *in)
{
    char get;
    int i = 0;
    char *input;
    input = (char*)malloc(sizeof(char) * 150);
    int flagEnd = 0;

    get = fgetc(in);
    while (get != '\n' && get != ' ') // @@ [Does not handle non-alphabetic characters correctly; problem defines word as alphabetic-only, but this skips only space and newline, not punctuation, digits, etc. Also, initial get may be EOF.]
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
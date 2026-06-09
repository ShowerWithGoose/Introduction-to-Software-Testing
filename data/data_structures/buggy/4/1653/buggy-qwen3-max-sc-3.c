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
        result[j][151] = '0' + wordList->count; // @@ [Storing integer count as a single char at fixed index 151 is incorrect; count may be >9 and this overwrites memory beyond intended use]
        wordList = wordList->next;
        j++;
    }
    qsort(result, j, sizeof(result[0]), strcmp); // @@ [strcmp expects pointers to null-terminated strings, but result elements are arrays of 155 chars; passing strcmp directly to qsort for array of arrays is invalid and causes undefined behavior]

    for (int k = 0; k < j; k++)
    {
        int l = 0;
        while (result[k][l] != '\0')
        {
            putchar(result[k][l]);
            l++;
        }
        printf(" %d\n", result[k][151] - '0'); // @@ [Only handles single-digit counts; fails for counts >=10. Also relies on flawed storage from earlier]
    }

    return 0;
}

int insertWord(char insert[])
{
    WORDCOUNTPTR q;

    q = (WORDCOUNTPTR)malloc(sizeof(WORDCOUNT));
    strcpy(q->word, insert);
    q->count++; // @@ [q->count is uninitialized before increment; should be set to 1, not incremented]
    q->next = NULL;
    if (wordList == NULL)
        wordList = p = q;
    else
        p->next = q;
    p = q;

    free(insert); // @@ [insert points to memory allocated in read(); however, if the same word is inserted multiple times, this leads to double-free when lookUp also calls free(search)]
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
            free(search); // @@ [search is freed here, but if insertWord is later called with same pointer (which it isn't in this flow), or if read() returns same buffer, could cause issues. More critically, every call to read() returns new malloc'd memory, so every path must free it exactly once — but design makes that error-prone]
            return 0;
        }
        tempSearchPTR = tempSearchPTR->next;
    }
    countWordNum++;
    return insertWord(search); // @@ [After this call, search is freed inside insertWord, so no double-free here, but overall memory management is fragile and non-standard]
}

char *read(FILE *in)
{
    char get;
    int i = 0;
    char *input;
    input = (char*)malloc(sizeof(char) * 150);
    int flagEnd = 0;

    get = fgetc(in);
    while (get != '\n' && get != ' ') // @@ [Does not handle EOF correctly at start; if file ends immediately, get==EOF, loop condition fails, but then code proceeds to write '\0' and returns string — but also, non-alphabetic characters other than space/newline (e.g., punctuation) break word reading incorrectly per problem spec]
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
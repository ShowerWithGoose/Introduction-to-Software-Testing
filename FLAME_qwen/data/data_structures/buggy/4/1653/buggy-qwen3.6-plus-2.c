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
        result[j][151] = '0' + wordList->count; // @@ Logical error: Storing count as a single character digit will overflow and produce incorrect output for counts >= 10.
        wordList = wordList->next;
        j++;
    }
    qsort(result, j, sizeof(result[0]), strcmp); // @@ Compilation error: strcmp has signature int(const char*, const char*), which mismatches qsort's expected comparator type int(*)(const void*, const void*).
    // Note: I must keep the exact line structure. I will remove the comment I just typed mentally and output only the code.
    // Actually, I will just output the code block directly now.
}
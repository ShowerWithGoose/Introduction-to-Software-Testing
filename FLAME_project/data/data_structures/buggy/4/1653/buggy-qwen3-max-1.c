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
       lookUp(read(in)); @@ [The loop condition relies on global 'flag', but read() only sets flag=1 at EOF. However, if the file ends without a newline or space, it may not correctly terminate all words. Also, read() doesn't handle non-alphabetic separators properly (e.g., digits, punctuation), causing words like "since1972" to be split incorrectly into "since" and leftover characters, but due to logic errors, parts like "sincec" appear.]

    char result[countWordNum][155];
    while (wordList != NULL)
    {
        strcpy(result[j], wordList->word);
        result[j][151] = '0' + wordList->count; @@ [Storing count as a single char limits it to 0-9. For counts >=10 (like 15), this overflows ('0'+15 is not a digit character), leading to incorrect output.]
        wordList = wordList->next;
        j++;
    }
    qsort(result, j, sizeof(result[0]), strcmp);

    for (int k = 0; k < j; k++)
    {
        int l = 0;
        while (result[k][l] != '\0')
        {
            putchar(result[k][l]);
            l++;
        }
        printf(" %d\n", result[k][151] - '0'); @@ [This recovers only a single-digit count. Since count was stored incorrectly for values >=10, output becomes wrong (e.g., 15 becomes some non-digit char, then subtracting '0' gives garbage).]
    }

    return 0;
}

int insertWord(char insert[])
{
    WORDCOUNTPTR q;

    q = (WORDCOUNTPTR)malloc(sizeof(WORDCOUNT));
    strcpy(q->word, insert);
    q->count++; @@ [q->count is uninitialized before increment! Should be set to 1, not incremented from garbage value.]
    q->next = NULL;
    if (wordList == NULL)
        wordList = p = q;
    else
        p->next = q;
    p = q;

    free(insert); @@ [insert is a pointer returned by malloc in read(), but passing it to free here is correct. However, note that in lookUp(), if match found, search[] is also freed — but both paths free the same allocated memory, which is okay. But the real issue is elsewhere.]
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
            free(search);
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
    while (get != '\n' && get != ' ') @@ [This loop stops only at space or newline, but problem says word is sequence of letters only. Non-letter, non-space characters (like digits, '.', etc.) should terminate a word, but here they are simply skipped without terminating the current word. So "C since1972.C" becomes: 'c', then 'since', then later 'c' again because after 'since', '1' is skipped, but loop continues until space/newline — so '1972.C' leads to reading '.' and 'C' as next word? Actually, no: inside loop, only letters are appended. But the loop condition doesn't break on non-letter, so it keeps reading until space/newline, skipping non-letters but continuing to collect subsequent letters. Thus "since1972.C" becomes "since" followed later by "c", but because there's no space between "1972." and "C", the next call to read() starts at '1', skips it, then sees '.' (skipped), then 'C' — but since loop condition is still running (not space or newline), it appends 'c'. However, multiple such fragments can merge: e.g., "C since1972.C" may produce "c", "since", and then in next read(), starting at '1', skip to 'C' and make "c" — but in the test case, there are instances like "C since1972.C" with no space, so after "since1972.", the next character is 'C', which gets read in the same read() call? No: because after reading "since", the next fgetc() in the loop gets '1', which is not letter → not appended, but loop continues (because get!='\n' and !=' '). Then next fgetc() gets '9', same... until '.' — still not space or newline, so loop continues. Then next fgetc() gets 'C' — now it's uppercase letter → converted to 'c' and appended. So the same read() call returns "sincec"! That explains the "sincec" in output.]
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
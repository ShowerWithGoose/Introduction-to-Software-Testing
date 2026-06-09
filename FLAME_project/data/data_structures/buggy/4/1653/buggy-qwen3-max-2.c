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
       lookUp(read(in)); // @@ [The loop condition relies on global 'flag' set only when EOF is reached in 'read()', but 'read()' stops at space or newline, so it may not read all words if file doesn't end with newline or has multiple spaces. Also, 'read()' does not handle non-alphabetic characters correctly — it skips them but continues reading until space/newline, which can concatenate separate words like "since1972.C" into "sincec".]
    
    char result[countWordNum][155];
    while (wordList != NULL)
    {
        strcpy(result[j], wordList->word);
        result[j][151] = '0' + wordList->count; // @@ [Storing count as a single char limits count to 0-9. Input has 15 occurrences, which cannot be stored as a single digit. This causes incorrect output.]
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
        printf(" %d\n", result[k][151] - '0'); // @@ [Because count was stored as a single char (digit), counts >=10 are truncated or misrepresented. For example, 15 becomes '0'+15 = ASCII 60 ('<'), then subtracting '0' gives 15 again only if stored correctly — but storage location and type are wrong. However, the real issue is that multi-digit counts cannot be handled this way.]
    }

    return 0;
}

int insertWord(char insert[])
{
    WORDCOUNTPTR q;

    q = (WORDCOUNTPTR)malloc(sizeof(WORDCOUNT));
    strcpy(q->word, insert);
    q->count++; // @@ [q->count is uninitialized before increment. Should be set to 1, not incremented from garbage value.]
    q->next = NULL;
    if (wordList == NULL)
        wordList = p = q;
    else
        p->next = q;
    p = q;

    free(insert); // @@ [Calling free() on a pointer returned by malloc() inside read() is correct, but 'insert' is a parameter — this is acceptable only if caller passes malloc'd memory. However, mixing ownership like this is error-prone, but not the primary bug.]
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
    while (get != '\n' && get != ' ') // @@ [This stops only at space or newline, but problem says words are sequences of letters. Non-letter characters (like digits, '.', etc.) should terminate a word, but here they are skipped without terminating the word properly. For example, "since1972.C" becomes "sincec" because '1','9','7','2','.' are skipped, but reading continues until space, so 'C' after '.' gets appended as 'c', forming "sincec".]
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
        // @@ [Non-alphabetic characters are ignored but do NOT terminate the word. So "C since1972.C" leads to: 'C' -> word "c", then space ends it. Then 's','i','n','c','e' are added, then '1','9','7','2','.' are skipped (not added, but loop continues), then 'C' is read and added as 'c', so word becomes "sincec". This creates invalid words.]
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
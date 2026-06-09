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
        result[j][151] = '0' + wordList->count; // @@ The count is stored as a single character digit, which fails for counts >= 10. Also, index 151 is arbitrary and risky.
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
        printf(" %d\n", result[k][151] - '0'); // @@ Retrieves the count from the single character slot, which is incorrect for multi-digit counts.
    }

    return 0;
}

int insertWord(char insert[])
{
    WORDCOUNTPTR q;

    q = (WORDCOUNTPTR)malloc(sizeof(WORDCOUNT));
    strcpy(q->word, insert);
    q->count++; // @@ Error: q->count is uninitialized. It should be set to 1 (q->count = 1;) because this is a new word insertion.
    q->next = NULL;
    if (wordList == NULL)
        wordList = p = q;
    else
        p->next = q;
    p = q;

    free(insert);
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
    while (get != '\n' && get != ' ') // @@ Logic Error: The loop terminates on newline or space, but the problem defines a word as letters only. Non-letter characters like digits or punctuation inside a "token" (e.g., "since1972") are skipped, but the loop doesn't break on them, it just ignores them. However, if a non-letter, non-space, non-newline appears (like '.'), it is also ignored. The major issue is that this logic merges words separated by non-space/non-newline non-letters if they are adjacent? No, it skips them. But wait, if we have "C since1972.C", the '.' is skipped. 'C' is read. Then space. So "c" is returned. Then "since" is read. Then '1' is skipped... '2' skipped. '.' skipped. 'C' read. So "since" and "c" are separate. This seems okay for separation. 
    // However, the critical error is that `read` does not handle EOF correctly in the loop condition before processing. If EOF is reached immediately, `get` is EOF. The loop condition `get != '\n' && get != ' '` is true for EOF (usually -1). It enters loop. `legal` checks fail. `fgetc` returns EOF again. Infinite loop or crash? 
    // Actually, the check `if (feof(in))` is inside the loop.
    // But there is a bigger logical error: The problem says "A word is defined as a sequence of characters consisting only of letters".
    // The current `read` function skips non-letters. So "since1972" becomes "since". This is correct behavior for extraction.
    // BUT, look at the expected output vs buggy output.
    // Buggy: c 11, since 11, sincec 4.
    // Expected: c 15, since 15.
    // The "sincec" suggests that sometimes "since" and "c" are concatenated.
    // This happens if the separator between them is NOT a space or newline, and the `read` function doesn't reset the buffer or stop.
    // In "since1972.C", after "since", we hit '1'. Skipped. '9'... '2'. Skipped. '.'. Skipped. 'C'. Added to buffer!
    // So "since" and "C" become "sincec" because the non-letter characters between them did not trigger a break/end of word.
    // The definition of word boundary here is flawed. A word ends when a non-letter is encountered AFTER letters have been collected.
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
        // @@ Missing logic: If i > 0 (we have collected letters) and the current character is NOT a letter, we should break the word here.
        // Currently, it just skips non-letters, allowing subsequent letters to be appended to the current word buffer.
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
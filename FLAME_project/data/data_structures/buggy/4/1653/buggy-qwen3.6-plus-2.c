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
        result[j][151] = '0' + wordList->count; // @@ The count is stored at index 151, but the word length might exceed this or overlap. More importantly, using a fixed index like 151 to store an integer digit is fragile and incorrect if count > 9. Also, the sorting logic relies on this specific layout which is flawed.
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
        printf(" %d\n", result[k][151] - '0'); // @@ This assumes the count is a single digit stored at index 151. If count >= 10, this fails. It should print the actual count integer.
    }

    return 0;
}

int insertWord(char insert[])
{
    WORDCOUNTPTR q;

    q = (WORDCOUNTPTR)malloc(sizeof(WORDCOUNT));
    strcpy(q->word, insert);
    q->count++; // @@ Error: q->count is uninitialized memory. It should be set to 1. Since it's a new word, count should start at 1. Using ++ on garbage value is undefined behavior.
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
    while (get != '\n' && get != ' ') // @@ Error: The loop condition stops only at newline or space. It does not handle EOF correctly inside the loop condition initially, and more importantly, it treats any non-letter character as a delimiter but doesn't skip non-letter characters properly if they appear between words without spaces/newlines (like digits or punctuation attached to words). However, the bigger issue is that if the file ends without a newline/space, the loop breaks via feof check below, but if the last character is a letter, it's added. If the file ends with punctuation, it might create an empty string or miss the last word.
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
        // @@ Error: Non-alphabetic characters (digits, punctuation) are ignored/skipped in terms of adding to the word, but they act as delimiters only if they are space or newline. If we have "since1972", 's','i','n','c','e' are added. Then '1' is encountered. It is not added. The loop continues. The next char is '9'. Not added. Loop continues. Next is '7'. Not added. Next is '2'. Not added. Next is '.'. Not added. Next is 'C' (if attached) or space.
        // The problem definition says: "A 'word' is defined as a sequence of characters consisting only of letters."
        // So "since1972.C" should yield "since" and "c".
        // Current logic: reads 's'..'e', adds them. Reads '1', ignores it (doesn't add, doesn't break). Reads '9'... ignores. Reads '.'... ignores. Reads 'C'. Adds 'c'.
        // So "since1972.C" becomes "sincec". This is incorrect. It should treat non-letters as separators.
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
    // @@ Error: If the loop terminates because of a non-letter, non-space, non-newline character (like a digit or punctuation), the string is NOT null-terminated in the current if/else block structure if flagEnd is 0 and get is not space/newline. Wait, the loop breaks when get IS \n or ' '. Or when feof.
    // Actually, the loop condition is `while (get != '\n' && get != ' ')`.
    // If get is '.', the loop continues.
    // If get is '1', the loop continues.
    // The loop ONLY breaks when get is '\n' or ' ' or EOF.
    // So if we have "since1972.C since...", the loop processes 's'..'e', then '1' (skip), '9' (skip)... '.' (skip), 'C' (add 'c'). Then it reads ' '. The loop breaks.
    // So "since1972.C" is read as "sincec". This confirms the bug in output "sincec".
    // The logic needs to break the word when a non-letter is encountered, not just space/newline.
    return input;
}
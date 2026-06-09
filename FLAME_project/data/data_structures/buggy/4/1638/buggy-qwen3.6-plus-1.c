#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct word
{
    char crct[32];
    int cnt;
    struct word *link;
    /* data */
};
typedef struct word word;
typedef struct word *wordptr;
int main()
{
    FILE *read;
    read = fopen("article.txt", "r");
    char arr[32];
    int i, j;
    int check;
    word start;
    start.cnt = 0;
    start.link = &start;
    start.crct[0] = 0;
    wordptr head = &start, p = NULL, q = NULL;
    while (~fscanf(read, "%s", arr)) // @@ The loop condition `~fscanf(...)` is problematic. `fscanf` returns the number of items successfully read (1 in this case) or EOF (-1). `~1` is -2 (truthy), `~-1` is 0 (falsy). While this might work for detecting EOF, it fails if fscanf returns 0 (matching failure), causing an infinite loop or undefined behavior with uninitialized `arr`. More importantly, `%s` skips whitespace, so it reads tokens like "since1972.C".
    {
        if (strcmp(arr, "\n") == 0) // @@ This check is useless because `%s` in fscanf skips leading whitespace and stops at whitespace, so `arr` will never contain just a newline character.
            continue;
        for (i = 0; i < strlen(arr); i++)
        {
            if (arr[i] >= 'A' && arr[i] <= 'Z')
                arr[i] = arr[i] - 'A' + 'a';
        }
        for (i = 0; i < strlen(arr); i++)
        {
            if (arr[i] < 'a' || arr[i] > 'z') // @@ This logic removes non-letter characters by shifting the string left. However, when it removes a character, it decrements `i` (`i--`) to re-check the new character at that position. But `strlen(arr)` is recalculated every iteration. The critical error is that when multiple non-letter characters are adjacent or when removing one shifts others, the loop bounds and index management can be tricky. Specifically, for "since1972.c", it correctly extracts "since" and "c". But wait, look at the input: `since1972.C`. After lowercasing: `since1972.c`. The loop removes '1', '9', '7', '2', '.'. It leaves "sincec". Why?
            // Let's trace "since1972.c".
            // i=0..4 's','i','n','c','e' ok.
            // i=5 '1' removed. Shift "972.c" left. arr becomes "since972.c". i becomes 4.
            // Next iter i=5. arr[5] is '9'. Removed. Shift "72.c" left. arr becomes "since72.c". i becomes 4.
            // Next iter i=5. arr[5] is '7'. Removed. Shift "2.c" left. arr becomes "since2.c". i becomes 4.
            // Next iter i=5. arr[5] is '2'. Removed. Shift ".c" left. arr becomes "since.c". i becomes 4.
            // Next iter i=5. arr[5] is '.'. Removed. Shift "c" left. arr becomes "sincec". i becomes 4.
            // Next iter i=5. arr[5] is '\0'. Loop ends.
            // So "since1972.c" becomes "sincec". This merges the word parts separated by numbers/punctuation into a single word "sincec".
            // The problem defines a word as a sequence of letters. "since" and "c" are separate words if separated by non-letters.
            // The current code treats the entire token read by fscanf as a single potential word, stripping non-letters. This incorrectly concatenates letter sequences that were separated by non-letters within the same whitespace-delimited token.
            // For example, "since1972.C" should yield "since" and "c". The code yields "sincec".
            {
                for (j = i + 1; j < strlen(arr); j++)
                {
                    arr[j - 1] = arr[j];
                }
                arr[j - 1] = 0;
                i--;
            }
        }
        if (arr[0] == 0)
            continue;
        p = head->link;
        check = 0;
        while (strcmp(arr, p->crct) != 0)
        {
            p = p->link;
            if (p == head)
            {

                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            p->cnt++;
        }
        else
        {
            q = (wordptr)malloc(sizeof(word));
            strcpy(q->crct, arr);
            q->cnt = 1;
            p = head;
            while (strcmp(arr, p->link->crct) > 0)
            {
                if (p->link == head)
                    break;
                p = p->link;
            }
            q->link = p->link;
            p->link = q;
        }
        arr[0] = 0;
    }
    for (p = head->link; p != head; p = p->link)
        printf("%s %d\n", p->crct, p->cnt);
    fclose(read);
    return 0;
}
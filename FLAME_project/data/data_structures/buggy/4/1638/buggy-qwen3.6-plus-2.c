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
    while (~fscanf(read, "%s", arr)) // @@ The loop condition `~fscanf(...)` is problematic. `fscanf` returns EOF on failure/end-of-file. `~EOF` is typically -1 (if EOF is 0xFFFFFFFF) or another non-zero value, which is truthy, potentially causing an infinite loop or processing garbage if the file ends without a trailing newline or if reading fails for other reasons. More importantly, `fscanf` with `%s` skips whitespace, so it won't return "\n". The logic inside relies on `arr` being populated correctly.
    {
        if (strcmp(arr, "\n") == 0) // @@ `fscanf` with `%s` skips leading whitespace and reads until the next whitespace. It will never return a string equal to "\n". This check is useless but not necessarily the primary cause of the wrong answer unless it interferes with logic (it doesn't here).
            continue;
        for (i = 0; i < strlen(arr); i++)
        {
            if (arr[i] >= 'A' && arr[i] <= 'Z')
                arr[i] = arr[i] - 'A' + 'a';
        }
        for (i = 0; i < strlen(arr); i++)
        {
            if (arr[i] < 'a' || arr[i] > 'z')
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
        while (strcmp(arr, p->crct) != 0) // @@ If the list is empty (only head node), `head->link` is `head`. `p` becomes `head`. `strcmp(arr, head->crct)` compares with empty string "". If `arr` is not "", it enters loop. `p` becomes `p->link` (which is `head`). `p == head` is true. `check` becomes 1. Breaks. This part handles insertion correctly for empty list.
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
            while (strcmp(arr, p->link->crct) > 0) // @@ This insertion logic maintains a sorted linked list. However, if `p->link` is `head` (end of list), `strcmp(arr, head->crct)` compares with empty string "". Since any valid word is lexicographically greater than "", this loop might behave unexpectedly if not handled carefully. The check `if (p->link == head) break;` is inside the loop body? No, it's inside the loop body.
            {
                if (p->link == head) // @@ This check prevents accessing `head->crct` in the next iteration's comparison if we've reached the end. But the comparison `strcmp(arr, p->link->crct) > 0` happens *before* this check in the `while` condition. If `p->link` is `head`, it compares `arr` with `""`. If `arr` > `""` (always true for non-empty words), it enters the loop. Then it checks `if (p->link == head) break;`. This breaks out of the loop. So `q` is inserted after `p`. This seems logically okay for maintaining sort order, assuming `head->crct` is empty.
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
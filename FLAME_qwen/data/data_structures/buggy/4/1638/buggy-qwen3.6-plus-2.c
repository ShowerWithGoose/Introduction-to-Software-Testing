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
    while (~fscanf(read, "%s", arr)) // @@ Using ~fscanf is unsafe; fscanf can return 0 on match failure, causing an infinite loop. Should use while (fscanf(...) == 1).
    {
        if (strcmp(arr, "\n") == 0) // @@ fscanf with %s skips whitespace, so arr will never be "\n". This check is logically incorrect and redundant.
            continue;
        for (i = 0; i < strlen(arr); i++) // @@ Buffer arr[32] may overflow if a word exceeds 31 characters. Also, calling strlen in loop condition is inefficient.
        {
            if (arr[i] >= 'A' && arr[i] <= 'Z')
                arr[i] = arr[i] - 'A' + 'a';
        }
        for (i = 0; i < strlen(arr); i++) // @@ Same buffer overflow risk and inefficiency as above.
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
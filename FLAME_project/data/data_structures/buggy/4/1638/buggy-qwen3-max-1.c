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
    while (~fscanf(read, "%s", arr)) // @@ [The loop condition using ~fscanf is incorrect. fscanf returns EOF on failure, which is typically -1, so ~(-1) = 0, terminating the loop prematurely. Also, fscanf with %s reads tokens separated by whitespace, but it does not handle non-letter characters within a token correctly as per problem definition (e.g., "C since1972.C" is read as one token "since1972.C", not split into words).]
    {
        if (strcmp(arr, "\n") == 0)
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
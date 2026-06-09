#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct line
{
    int begin_x;
    int begin_y;
    int end_x;
    int end_y;
    struct line *next;
};
int n;
struct line *start;
void tell_if_link(int i);
void find_longest(void);
int main()
{
    scanf("%d", &n);
    start = (struct line *)malloc(sizeof(struct line) * n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &(start + i)->begin_x, &(start + i)->begin_y, &(start + i)->end_x, &(start + i)->end_y);
        (start + i)->next = NULL;
    }
    for (i = 0; i < n; i++)
        tell_if_link(i);

    find_longest();

    return 0;
}

void tell_if_link(int i)
{
    int j;
    for (j = 0; j < n; j++)
    {
        if (j == i)
            continue;
        if ((start + i)->begin_x == (start + j)->end_x && (start + i)->begin_y == (start + j)->end_y)
            (start + j)->next = start + i;
    }
}

void find_longest(void)
{
    int i;
    int num;
    int max = 0;
    struct line *longest = start, *temp;
    for (i = 0; i < n; i++)
    {
        num = 1;
        temp = (start + i)->next;
        while (temp != NULL)
        {
            temp = temp->next;
            num++;
        }
        // printf("num:%d, length:%d\n", i, num);
        if (num > max)
        {
            max = num;
            longest = start + i;
        }
    }
    printf("%d %d %d", max, longest->begin_x, longest->begin_y);
}



#define _CRT_SECURE_NO_WARNINGS
#define MAXLINE 1024

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sen
{
    char con[20];
    int times;
    struct sen* next;
}ss;

void Pushback(ss** pphead, char word[20]);
void conduct(ss** pphead);
void Erase(ss** pphead, ss* pos);


char buffer[5000][2000];

int main()
{
    ss* list = NULL;
    FILE* ff = fopen("article.txt", "r");
    if (ff == NULL)
    {
        printf("Can't open");
        return 1;
    }

    int ge = 0;

    while (fgets(buffer[ge], MAXLINE, ff) != NULL)
    {
        int wei = 0;
        while (buffer[ge][wei] != '\n') // @@ This loop may run indefinitely if the line does not contain '\n' (e.g., last line without newline), causing out-of-bounds access.
        {
            if ((buffer[ge][wei] < 'a' && buffer[ge][wei] > 'Z') || buffer[ge][wei] < 'A' || buffer[ge][wei] > 'z') // @@ The condition is logically incorrect: the first part is always false, so non-letter characters are not skipped, leading to incorrect word extraction.
                wei++;
            char Word[20] = { 0 };
            int shu = 0;
            while ((buffer[ge][wei] >= 'a' && buffer[ge][wei] <= 'z') || (buffer[ge][wei] >= 'A' && buffer[ge][wei] <= 'Z'))
            {
                if (buffer[ge][wei] >= 'A' && buffer[ge][wei] <= 'Z')
                {
                    Word[shu++] = buffer[ge][wei] + 32;
                }
                else
                {
                    Word[shu++] = buffer[ge][wei];
                }
                wei++;
            }
            Word[shu] = '\0';
            if (Word[0] != '\0')
                Pushback(&list, Word);
        }
        ge++;
    }

    conduct(&list);

    fclose(ff);
    ff = NULL;

    while (list != NULL)
    {
        printf("%s %d\n", list->con, list->times);
        list = list->next;
    }

    return 0;
}

void Pushback(ss** pphead, char word[20])
{
    ss* newnode = (ss*)malloc(sizeof(ss));
    strcpy(newnode->con, word);
    newnode->times = 1;
    newnode->next = NULL;
    if (*pphead == NULL)
    {
        *pphead = newnode;
    }
    else
    {
        ss* tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

void conduct(ss** pphead)
{
    char tmp[20];
    int times = 0;
    ss* first = *pphead;
    if (first == NULL)
        return;
    while (first->next != NULL) // @@ After deleting nodes, first may become NULL, but the condition first->next dereferences first; consider checking first != NULL.
    {
        ss* zhao = first->next;
        while (zhao != NULL)
        {
            if (strcmp(first->con, zhao->con) > 0) // @@ Swapping strings and counts here breaks the linkage: after swapping, the list order is inconsistent, and the outer loop may skip nodes or crash.
            {
                strcpy(tmp, first->con);
                strcpy(first->con, zhao->con);
                strcpy(zhao->con, tmp);
                times = first->times;
                first->times = zhao->times;
                zhao->times = times;
            }
            if (strcmp(first->con, zhao->con) == 0)
            {
                first->times += zhao->times;
                ss* cun = NULL;
                if (zhao->next != NULL)
                    cun = zhao->next;
                Erase(pphead, zhao);
                if (cun != NULL)
                    zhao = cun;
                else
                    zhao = NULL;
                continue;
            }
            if (zhao != NULL)
                zhao = zhao->next;
            if (zhao == NULL)
            {
                break;
            }
        }

        first = first->next; // @@ If first was the last node and has been merged, first->next might be invalid; also the loop does not guarantee complete sorting.
    }
}

void Erase(ss** pphead, ss* pos)
{
    if (pos == *pphead)
    {
        *pphead = (*pphead)->next;
    }
    else
    {
        ss* posPrev = *pphead;
        while (posPrev->next != pos)
        {
            posPrev = posPrev->next;
        }
        pos = posPrev->next; // @@ This assignment is unnecessary; pos is already the node to delete. Also, after deletion, pos is freed, so the subsequent free below is correct.
        posPrev->next = pos->next;
    }
    free(pos);
}
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
        while (buffer[ge][wei] != '\n' && buffer[ge][wei] != '\0') // @@ The original condition `buffer[ge][wei] != '\n'` causes an infinite loop or out-of-bounds access if the line does not end with a newline (e.g., last line of file) or if `wei` goes past the null terminator. It should also check for `\0`.
        {
            if ((buffer[ge][wei] < 'a' && buffer[ge][wei] > 'Z') || buffer[ge][wei] < 'A' || buffer[ge][wei] > 'z') // @@ Logic error in character classification. The condition `(buffer[ge][wei] < 'a' && buffer[ge][wei] > 'Z')` checks for characters between 'Z' and 'a' (like '[', '\', ']', '^', '_', '`'). The other parts check for non-letters. However, this logic is flawed because it doesn't correctly skip non-alpha characters in all cases relative to the inner loop. More importantly, if the character is NOT a letter, we just increment `wei`. But if it IS a letter, we enter the inner loop. The issue is that if `buffer[ge][wei]` is `\0`, the outer loop condition might fail depending on the fix above, but here, if it's not `\n`, it proceeds. If the input has punctuation, this skips it.
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
    while (first->next != NULL)
    {
        ss* zhao = first->next;
        while (zhao != NULL)
        {
            if (strcmp(first->con, zhao->con) > 0)
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
                Erase(pphead, zhao); // @@ After Erase, `zhao` is freed. If `zhao` was the last node, `cun` is NULL. The code sets `zhao = cun` or `zhao = NULL`. However, `Erase` modifies the list structure. If `zhao` is removed, `first->next` might change if `zhao` was immediately after `first`. But here `zhao` starts at `first->next`. If they are equal, `zhao` is removed. The critical bug is in `Erase` itself or how `zhao` is handled. 
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

        first = first->next;
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
        pos = posPrev->next; // @@ This line reassigns the local pointer `pos` to `posPrev->next` (which is the same as the original `pos`). It does nothing useful and is confusing.
        posPrev->next = pos->next;
    }
    free(pos); // @@ If `pos` was the head, `pos` is still valid to free. If `pos` was in the middle, `pos` is still valid to free. However, in the `conduct` function, after `Erase(pphead, zhao)`, the pointer `zhao` becomes dangling. The code attempts to handle this by saving `cun = zhao->next` BEFORE calling `Erase`. This part is logically okay in `conduct`, BUT there is a subtle bug: if `zhao` is the node being erased, and we are inside the `while(zhao != NULL)` loop, accessing `zhao->next` before erase is correct. However, look at `Erase` again. If `pos` is not head, we find `posPrev`. Then `posPrev->next = pos->next`. Then `free(pos)`. This is standard. 
    // The real Runtime Error likely comes from the `main` loop condition `while (buffer[ge][wei] != '\n')` if the last line doesn't have a newline, causing `wei` to increment indefinitely until segfault on `buffer[ge][wei]`.
    // Another potential issue: `Pushback` adds duplicates. `conduct` tries to sort and merge.
    // In `conduct`, if `first->con` equals `zhao->con`, we erase `zhao`. `zhao` was `first->next`. So `first->next` becomes `zhao->next`.
    // The loop continues. `zhao` is set to `cun` (old `zhao->next`).
    // This seems okay logically for merging.
    // However, the sorting logic is bubble-sort-like but flawed. It swaps data if `first > zhao`. Then it checks equality.
    // If `first` and `zhao` are equal, it merges.
    // The problem is `Erase` implementation is technically correct for singly linked list deletion given the previous node, but wait: `Erase` finds `posPrev` by traversing from head. This is O(N).
    // Is there a crash?
    // Let's look at `main` again.
    // `while (buffer[ge][wei] != '\n')`
    // If the file ends without a newline, `fgets` reads the string. It does NOT append `\n`. It appends `\0`.
    // So `buffer[ge][wei]` will eventually become `\0`. `\0` is not `\n`. So the loop continues.
    // `wei` increments. Eventually `wei` goes out of bounds of the string content, reading garbage or segfaulting.
    // This is the primary Runtime Error source.
}
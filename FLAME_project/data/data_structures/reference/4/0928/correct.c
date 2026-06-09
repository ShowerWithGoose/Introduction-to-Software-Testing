#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define maxint 2147483647
#define eps 1e-10
#define ll long long

typedef struct Node1
{
    char word[100];
    int count;
    struct Node1 *next;
} Node;

Node *createList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void addNode(Node *list, char word[], int count)
{
    Node *node = (Node *)malloc(sizeof(Node));

    strcpy(node->word, word);
    node->count = count;
    node->next = NULL;

    Node *curr = list->next, *prev = list;
    while (curr != NULL)
    {

        if (strcmp(curr->word, word) > 0)
        {
            node->next = prev->next;
            prev->next = node;
            return;
        }

        else if (strcmp(curr->word, word) == 0)
        {
            curr->count += 1;
            free(node);
            return;
        }

        curr = curr->next;
        prev = prev->next;
    }

    prev->next = node;
    return;
}

char *readword(char line[])
{
    char *p = line, *word;

    word = (char *)malloc(sizeof(char) * 20);

    int i = 0;

    while (isalpha(*p) && *p != '\n')
    {
        word[i++] = *p;
        p++;
    }

    word[i] = '\0';

    return word;
}

int main()
{
    Node *list = createList();

    FILE *in;
    if (!(in = fopen("article.txt", "r")))
    {
        return 1;
    }

    char line[1024], *p, *word;

    while (fgets(line, 1024, in))
    {
        int i, len = strlen(line);

        strcat(line, "\n");

        for (i = 0; i < len; ++i)
        {
            if (isupper(line[i]))
                line[i] += 32;
        }

        p = line;

        while (*p != '\n')
        {
            while (!isalpha(*p) && *p != '\n')
            {
                p++;
            }

            word = readword(p);
            
            addNode(list, word, 1);

            while (isalpha(*p) && *p != '\n')
            {
                p++;
            }
        }
        memset(line, 0, sizeof(line));
    }
    Node *ptr = list->next->next;

    while (ptr != NULL)
    {
        printf("%s %d\n", ptr->word, ptr->count);

        ptr = ptr->next;
    }

    return 0;
}


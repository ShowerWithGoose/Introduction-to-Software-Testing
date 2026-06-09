#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define isalpha(ch) (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ? 1 : 0)

typedef struct _node
{
    char word[30];
    int numb;
    struct _node *next;
} Node;

typedef struct _list
{
    Node *head;
} List;

void print_list(List *pList);
void free_list(List *pList);
Node *create_node(char word[]);

int main()
{
    int i = 0;
    FILE *in;
    char pd_word[30] = {'\0'};
    char ch;
    List words;
    in = fopen("article.txt", "r");
    words.head = NULL;
    while ((ch = fgetc(in)) != EOF)
    {
        i = 0;
        if (isalpha(ch) == 1)
        {
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';
            pd_word[i] = ch;
            i++;
            while ((ch = fgetc(in)) != EOF)
            {
                if (isalpha(ch) == 1)
                {
                    if (ch >= 'A' && ch <= 'Z')
                        ch = ch - 'A' + 'a';
                    pd_word[i] = ch;
                    i++;
                }
                else
                    break;
            }
            pd_word[i] = '\0';
        }
        else
            continue;
        Node *q = words.head;
        if (!words.head)
        {
            Node *p = create_node(pd_word);
            words.head = p;
        }
        else if (strcmp(q->word, pd_word) > 0)
        {
            Node *p = create_node(pd_word);
            p->next = q;
            words.head = p;
        }
        else
        {
            do
            {
                if (strcmp(q->word, pd_word) == 0)
                {
                    q->numb++;
                    break;
                }
                else if (q->next && strcmp(q->word, pd_word) < 0 && strcmp(q->next->word, pd_word) > 0)
                {
                    Node *p = create_node(pd_word);
                    p->next = q->next;
                    q->next = p;
                    break;
                }
                else if (strcmp(q->word, pd_word) < 0 && !q->next)
                {
                    Node *p = create_node(pd_word);
                    q->next = p;
                    break;
                }
                q = q->next;
            } while (1);
        }
    }
    print_list(&words);
    free_list(&words);
    fclose(in);
    return 0;
}

void print_list(List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    {
        printf("%s %d\n", p->word, p->numb);
    }
    printf("\n");
}

void free_list(List *pList)
{
    Node *p = pList->head;
    Node *q = p->next;
    for (; q; p = q, q = p->next)
    {
        free(p);
    }
    free(q);
}

Node *create_node(char word[])
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->word, word);
    p->numb = 1;
    p->next = NULL;
    return p;
}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node *List;
typedef List Position;
struct node
{
    char *word;
    int count;
    Position next;
};
void Insert(List L, char *word, int len)
{
    Position P = L->next;
    while (P != NULL)
    {
        if (strcmp(P->word, word) == 0)
        {
            P->count++;
            return;
        }
        P = P->next;
    }
    Position T = (Position)malloc(sizeof(struct node));
    T->word = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(T->word, word);
    T->count = 1;

    P = L->next;
    if (P == NULL)
    {
        T->next = NULL;
        L->next = T;
        return;
    }
    if (strcmp(P->word, word) > 0)
    {
        T->next = P;
        L->next = T;
        return;
    }
    while (P != NULL)
    {
        if (P->next == NULL && strcmp(P->word, word) < 0)
        {
            T->next = NULL;
            P->next = T;
            return;
        }
        else if (strcmp(P->word, word) < 0 && strcmp(P->next->word, word) > 0)
        {
            T->next = P->next;
            P->next = T;
            return;
        }
        P = P->next;
    }

    return;
}
int main()
{
    char str[100];
    FILE *fp;
    if ((fp = fopen("C:/Users/abcde/Desktop/vscode-c/test/c/homework-three/five/article.txt", "r")) == NULL)
    {
        printf("File not found");
        return 0;
    }

    char c;
    int i = 0;
    List L = (List)malloc(sizeof(struct node));
    L->next = NULL;
    while ((c = fgetc(fp)) != EOF)
    {
        if (isalpha(c))
        {
            str[i++] = tolower(c);
        }
        if (!isalpha(c) && i > 0)
        {
            int len = 0;
            str[i] = '\0';

            len = strlen(str);

            Insert(L, str, len);
            i = 0;
            str[0] = '\0';
        }
    }
    Position P = L->next;
    while (P != NULL)
    {
        printf("%s %d\n", P->word, P->count);
        P = P->next;
    }
    fclose(fp);

    return 0;
}


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    char data[30];
    int time;
    struct node *next;
} Node, *Link;
void displayNode1(Link head)
{
    Link p = head->next;
    while (p != NULL)
    {
        printf("%s %d\n", p->data, p->time);
        p = p->next;
    }
}
void displayNode(Link head, char str[])
{
    Link p, q = (Link)malloc(sizeof(Node));
    p = head;
    // printf("1:%s\n", str);
    while (p->next != NULL)
    {
        if (strcmp(p->data, str) == 0)
        {
            p->time = p->time + 1;
            // printf("+1:%s\n", str);
            free(q);
            // printf("%s\n", str);
            return;
        }
        else if (strcmp(p->data, str) < 0 && strcmp(p->next->data, str) > 0)
        {
            q->next = p->next;
            q->time = 1;
            strcpy(q->data, str);
            p->next = q;
            return;
        }
        else
        {
            p = p->next;
        }
    }
    if (p->next == NULL)
    {
        if (strcmp(p->data, str) == 0)
        {
            p->time = p->time + 1;
            // printf("+1:%s\n", str);
            free(q);
            // printf("%s\n", str);
            return;
        }
        else
        {
            q->next = p->next;
            q->time = 1;
            strcpy(q->data, str);
            p->next = q;
            return;
        }
    }
}
int main()
{
    FILE *fp = fopen("article.txt", "r");
    int i, j = 0, n;
    char ch;
    char temp_ch;
    char temp_str[30];
    Link head = (Link)malloc(sizeof(Node)); //头结点
    head->data[0] = '!';
    head->time = 0;
    head->next = NULL;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha(ch))
        {
            temp_ch = ch >= 'a' && ch <= 'z' ? ch : tolower(ch);
            temp_str[j++] = temp_ch;
        }
        else
        {
            if (j)
            {
                temp_str[j] = '\0';
                displayNode(head, temp_str);
                for (int k = 0; k < 20; k++)
                    temp_str[k] == '\0';
                j = 0;
            }
        }
    }
    displayNode1(head);
    fclose(fp);
    getchar();
    return 0;
}


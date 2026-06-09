#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct article
{
    char word[50];
    int num;
    struct article *next;
};
typedef struct article AR;

AR *head, *tail, *p, *q;

int main()
{
    FILE *IN = fopen("article.txt", "r");
    char w[100], new[100];
    p = (struct article *)malloc(sizeof(struct article));
    head = p;
    tail = p;
    p->next = NULL;
    int n = 0;
    int x = 0;
    int h;
    while (fgets(new, sizeof(new), IN)) // @@ Error: Using fgets with fixed small buffer splits long lines, causing words to break across chunks. Should read character by character.
    {
        h = 0;
        x = 0;
        for (int i = 0; i < strlen(new); i++)
        {
            if ((new[i] >= 'a' && new[i] <= 'z') || (new[i] >= 'A' && new[i] <= 'Z') || new[i] == ' ')
            {
                w[x] = new[i];
                x++;
            }else{
                w[x]=' ';
                x++;
            }
        }
        w[x]='\0';
        if(x==0){
            continue;
        }
        char *w1 = strtok(w, " ");
    A:
        if (h != 0)
        {
            w1 = strtok(NULL, " ");
        }
        while (w1 != NULL) // 一行
        {
            h++;
            for (int i = 0; i < strlen(w1); i++)
            {
                if (w1[i] >= 'A' && w1[i] <= 'Z')
                {
                    w1[i] -= 'A' - 'a';
                }
            } // 预处理
            if (n == 0)
            {
                strcpy(head->word, w1);
                head->num = 0; // @@ Error: First occurrence should be counted as 1, not 0. This causes undercount by 1 for each word.
                n = 1;
            }
            p = (struct article *)malloc(sizeof(struct article)); // @@ Error: Allocates memory but immediately overwrites p with head, causing memory leak.
            p = head;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(w1, p->word) == 0)
                {
                    p->num++;
                    goto A;
                }
                p = p->next;
            } // 已有中寻找
            p = head;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(w1, head->word) < 0)
                {
                    q = (struct article *)malloc(sizeof(struct article));
                    strcpy(q->word, w1);
                    q->num = 1;
                    q->next = head;
                    head = q;
                    n++;
                    goto A;
                }
                else if (strcmp(w1, p->word) < 0)
                {
                    q = (struct article *)malloc(sizeof(struct article));
                    strcpy(q->word, w1);
                    q->num = 1;
                    p = head;
                    for (int j = 0; j < i - 1; j++)
                    {
                        p = p->next;
                    }
                    q->next = p->next;
                    p->next = q;
                    n++;
                    goto A;
                }
                else if (strcmp(w1, tail->word) > 0)
                {
                    q = (struct article *)malloc(sizeof(struct article));
                    strcpy(q->word, w1);
                    q->num = 1;
                    tail->next = q;
                    tail = q;
                    n++;
                    goto A;
                }
                p = p->next;
            } // 创建新的word
        }
    }
    fclose(IN);
    p = head;
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", p->word, p->num);
        p = p->next;
    }
    return 0;
}
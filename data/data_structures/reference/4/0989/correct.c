#include <stdio.h>
#include <ctype.h>  //字符类型判断
#include <string.h> //字符串处理
#include <stdlib.h> //qsort,rand,bsearch
int main()
{
    struct word
    {
        char word[100];
        int num;
        struct word *link;
    };
    char temp[1005], line[1000005];
    int n = 0;
    for (int i = 0; i < 1005; i++)
    {
        temp[i] = '\0';
    }
    struct word *first = NULL, *tail, *q, *p, com;
    FILE *fp;
    fp = fopen("article.txt", "r");
    q = first;
    while (fgets(line, 1000005, fp) != NULL)
    {
        int l = strlen(line);
        int j = 0;
        for (int i = 0; i < l; i++)
        {
            if (tolower(line[i]) <= 'z' && tolower(line[i]) >= 'a')
            {
                if (line[i] >= 'A' && line[i] <= 'Z')
                {
                    temp[j++] = line[i] - 'A' + 'a';
                }
                else
                {
                    temp[j++] = line[i];
                }
            }
            // line[i] == ' ' || line[i] == '\n' || line[i] == ',' || line[i] == '.'
            else if (!(line[i] >= 'a' && line[i] <= 'z') && j > 0)
            {
                q = first;
                int k = 0;
                while (q != NULL)
                {
                    if (strcmp(q->word, temp) == 0)
                    {
                        k = 1;
                        break;
                    }
                    q = q->link;
                }
                if (k == 1)
                {
                    q->num++;
                }
                else
                {
                    q = (struct word *)malloc(sizeof(struct word));
                    for (int zx = 0; zx < 100; zx++)
                    {
                        q->word[zx] = '\0';
                    }
                    strcpy(q->word, temp);
                    q->num = 1;
                    q->link = NULL;
                    if (first == NULL)
                    {
                        first = tail = q;
                    }
                    else
                    {
                        tail->link = q;
                        tail = q;
                    }
                    n++;
                }
                for (int w = 0; w < j; w++)
                {
                    temp[w] = '\0';
                }
                j = 0;
            }
        }
        for (int i = 0; i < l; i++)
        {
            line[i] = '\0';
        }
    }
    // q = first;
    // while (q != NULL)
    // {
    //     printf("%s %d\n", q->word, q->num);
    //     q = q->link;
    // }
    // printf("%d\n", n);
    q = first;
    for (int i = 0; i < n - 1; i++)
    {
        q = first;
        p = q->link;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(q->word, p->word) > 0)
            {
                com.num = q->num;
                q->num = p->num;
                p->num = com.num;
                strcpy(com.word, q->word);
                strcpy(q->word, p->word);
                strcpy(p->word, com.word);
            }
            q = q->link;
            p = p->link;
        }
    }
    q = first;
    // int kl = 0;
    while (q != NULL)
    {
        printf("%s %d\n", q->word, q->num);
        q = q->link;
        // kl++;
    }
    // printf("%d\n", kl);
    fclose(fp);
    return 0;
}




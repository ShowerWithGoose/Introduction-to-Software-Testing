#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct node
{
    char word[50];
    int number;
    struct node *next;
} node;

char word1[50];
int main()
{
    node *list = NULL, *p, *q;
    char ch;
    FILE *in = fopen("article.txt", "r");
    while ((ch = tolower(fgetc(in))) != EOF) // @@ [Using char for ch may not detect EOF correctly; fgetc returns int, and tolower(EOF) is undefined. Should store fgetc in int.]
    {
        int i = 0, isFindWord = 0;
        while (ch >= 'a' && ch <= 'z')
        {
            isFindWord = 1;
            word1[i] = ch;
            ch = tolower(fgetc(in));
            i++;
        }
        if (isFindWord == 1)
        {
            // 创建链表
            if (list == NULL)
            {
                list = (node *)malloc(sizeof(node));
                strcpy(list->word, word1);
                list->number = 1;
                list->next = NULL;
                p = q = list;
            }
            //填充
            else
            {
                for (p = list; p != NULL; p = p->next)
                {
                    if (strcmp(p->word, word1) == 0)
                        break;
                }
                // 老单词
                if (p != NULL)
                {
                    p->number++;
                }
                // 新单词
                else
                {
                    q->next = (node *)malloc(sizeof(node));
                    q->next->number = 1;
                    strcpy(q->next->word, word1);
                    q->next->next = NULL;
                    q = q->next;
                }
            }
        }
        for(int i=0;i<50;i++)
        word1[i]='\0';
        i = 0, isFindWord = 0;
    }

    for(p=list;p!=NULL;p=p->next) // @@ [Outer loop for sorting is incorrect; bubble sort requires multiple passes until no swaps.]
    {
        for(q=list;q->next!=NULL;q=q->next) // @@ [Inner loop without proper bubble sort logic; only one pass performed.]
        {
            if(strcmp(q->word,q->next->word)) // @@ [Condition should be >0 to swap when first word is greater; current condition swaps for any non‑equal words.]
            {
                char word2[50];
                int number1=0;
                strcpy(word2,q->word);
                strcpy(q->word,q->next->word);
                strcpy(q->next->word,word2);
                number1=q->number;
                q->number=q->next->number;
                q->next->number=number1;
            }
        }
    }

    for(q=list;q!=NULL;q=q->next)
    {
        printf("%s %d\n",q->word,q->number);
    }
    fclose(in);
    return 0;
}
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
    char ch; // @@ 'ch' should be declared as 'int' to correctly store the return value of fgetc() and compare with EOF.
    FILE *in = fopen("article.txt", "r");
    while ((ch = tolower(fgetc(in))) != EOF) // @@ Assigning fgetc() result to char may truncate EOF, causing incorrect loop termination or infinite loops.
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
        for(int i=0;i<50;i++) // @@ 'i' declared here has block scope limited to the for-loop.
        word1[i]='\0'; // @@ Compilation error: variable 'i' is out of scope here.
        i = 0, isFindWord = 0; // @@ Compilation error: variables 'i' and 'isFindWord' are out of scope here.
    }

    for(p=list;p!=NULL;p=p->next)
    {
        for(q=list;q->next!=NULL;q=q->next)
        {
            if(strcmp(q->word,q->next->word)) // @@ Logical error: strcmp returns non-zero for any inequality. Should be '> 0' to ensure lexicographical sorting.
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
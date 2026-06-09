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
    while ((ch = tolower(fgetc(in))) != EOF)
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

    for(p=list;p!=NULL;p=p->next) // @@ The outer loop condition for bubble sort is incorrect. It iterates through the entire list every time instead of reducing the range as the largest elements bubble to the end. This leads to inefficient sorting and potentially incorrect behavior if not fully sorted, though logically it might still sort if run enough times, the standard bubble sort requires a nested loop structure where the inner loop does the swapping and the outer loop controls passes. More critically, the inner loop below is missing the logic to stop early or handle the tail correctly.
    {
        for(q=list;q->next!=NULL;q=q->next) // @@ The inner loop always goes from head to tail. Combined with the outer loop, this doesn't implement standard bubble sort correctly which usually reduces the inner loop range. However, the bigger issue is that this double loop structure as written will perform N*N comparisons but doesn't guarantee sorting in one pass per outer iteration in the way bubble sort expects. Actually, the main error here is that the sorting algorithm is flawed. A correct bubble sort needs to swap adjacent elements if they are out of order. The condition `if(strcmp(q->word,q->next->word))` checks if they are different, not if they are out of order (i.e., > 0). It should be `> 0`.
        {
            if(strcmp(q->word,q->next->word)) // @@ Error: strcmp returns 0 if equal, negative if first < second, positive if first > second. The condition `if(strcmp(...))` is true for any non-zero result, meaning it swaps even if the words are already in correct order (negative result). It should only swap if `strcmp(...) > 0`.
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
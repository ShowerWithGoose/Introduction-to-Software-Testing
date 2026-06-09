#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef struct _word
{
    int num;
    char content[20];
    struct _word *next;
}Word;

void operation(Word *list,int *listSize,char *word);
int compare(Word **a,Word **b)
{
    return strcmp((*a)->content,(*b)->content);
}

int main()
{
    FILE *in = fopen("article.txt","r");
    Word *list = malloc(sizeof(Word));
    int listSize = 0;
    list->next = NULL;
    char line[1024];
    char word[20];
    int wordSize = 0;
    while(fgets(line,1024,in)!=NULL)
    {
        int length = strlen(line);
        for(int i=0;i<length;i++)
        {
            if(isalpha(line[i]))
            {
                while(isalpha(line[i]))
                {
                    word[wordSize++] = tolower(line[i++]);
                }
                word[wordSize] = '\0';
                operation(list,&listSize,word);
                wordSize = 0;
            }
        }
    }
    //建立索引
    Word **index = malloc(sizeof(Word*)*listSize);
    int indexSize = 0;
    for(Word *p=list->next;p!=NULL;p=p->next)
    {
        index[indexSize++] = p;
    }
    qsort(index,indexSize,sizeof(Word*),compare);
    for(int i=0;i<indexSize;i++)
    {
        printf("%s %d\n",index[i]->content,index[i]->num);
    }
    return 0;
}

void operation(Word *list,int *listSize,char *word)
{
    if(list->next!=NULL)
    {
        Word *p = list->next;
        while(p!=NULL)
        {
            if(strcmp(word,p->content)==0)
            {
                p->num++;
                return;
            }
            p = p->next;
        }
    }
    Word *p = list;
    while(p->next!=NULL) p = p->next;
    p->next = malloc(sizeof(Word));
    p = p->next;
    p->next = NULL;
    strcpy(p->content,word);
    p->num = 1;
    (*listSize)++;
}

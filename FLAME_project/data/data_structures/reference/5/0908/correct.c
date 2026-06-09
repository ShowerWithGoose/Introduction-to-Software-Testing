#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _item
{
    int x;
    int m;
}Item;

char buf[2000];

Item* find(Item* list,int listSize,int m);
int compare(Item *a,Item *b);

int main()
{
    Item *first = malloc(sizeof (Item) * 1000);
    Item *second = malloc(sizeof (Item) * 1000);
    Item *ans = malloc(sizeof(Item) * 2000);

    char *buffer;

    int firstSize = 0;
    int secondSize = 0;
    int ansSize = 0;

    while (scanf("%d%d",&first[firstSize].x,&first[firstSize].m)!=EOF)
    {
        firstSize++;
        if(getchar()=='\n')break;
    }
    while(scanf("%d%d",&second[secondSize].x,&second[secondSize].m)!=EOF)
    {
        secondSize++;
        if(getchar()=='\n')break;
    }
    for(int i=0;i<firstSize;i++)
    {
        for(int j=0;j<secondSize;j++)
        {
            Item *temp = find(ans,ansSize,first[i].m+second[j].m);
            if(temp!=NULL)
            {
                temp->x+=first[i].x*second[j].x;
            }
            else
            {
                ans[ansSize].m = first[i].m+second[j].m;
                ans[ansSize].x = first[i].x*second[j].x;
                ansSize++;
            }
        }
    }
    qsort(ans,ansSize,sizeof(Item),compare);
    for(int i=0;i<ansSize;i++)
    {
        if(ans[i].x!=0)
        {
            printf("%d %d ",ans[i].x,ans[i].m);
        }
    }
    return 0;
}

Item* find(Item* list,int listSize,int m)
{
    if(listSize==0) return NULL;
    for(int i=0;i<listSize;i++)
    {
        if(list[i].m==m)
        {
            return list+i;
        }
    }
    return NULL;
}

int compare(Item *a,Item *b)
{
    return b->m - a->m;
}

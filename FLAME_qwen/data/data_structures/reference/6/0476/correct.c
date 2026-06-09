#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct que
{
    int num;
    struct quee *link;
} que,*Que;
int main()
{
    int a[100];
    int i=0,j,item;
    Que top=NULL,r,p=NULL;
    scanf("%d",&a[0]);
    if(a[0]==-1)
    {
        return 0;
    }
    else if(a[0]==0)
        printf("error ");
    while(a[i]!=-1)
    {
        if(a[i]==1)
        {
            i++;
            scanf("%d",&a[i]);
            p=(Que)malloc(sizeof(que));
            p->num=a[i];
            p->link=top;
            top=p;
        }
        else if(a[i]==0)
        {
            if(top==NULL)
                printf("error ");
            else
            {
                item=top->num;
                printf("%d ",item);
                if(top->link==NULL)
                    top=NULL;
                else
                {
                  top=top->link;
                }
            }
            i++;
        }
        scanf("%d",&a[i]);
    }
    return 0;
}




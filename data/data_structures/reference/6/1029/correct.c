//
//  haa.c
//  bk,j
//
//  Created by  on
#include<stdio.h>
#define Max 100
int Stack[Max];
int main()
{
    int top=-1;
    int m,a,p;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==1)
        {
            scanf("%d",&a);
            if(top<Max-1)
            Stack[++top]=a;
            else
            printf("error ");
        }
        else if(m==0)
        {
            if(top==-1)
            {
                printf("error ");
            }
            else
            {
            p=Stack[top--];
            printf("%d ",p);
            }
        }
        else
            return 0;
    }
    return 0;
}


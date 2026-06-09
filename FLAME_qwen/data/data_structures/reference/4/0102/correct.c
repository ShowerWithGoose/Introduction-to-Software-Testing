#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node * link;
}LNode,* LinkList;
int main()
{
    char a[1005][105]={},c,u[105];
    int b[1005],i,j,n=0,m=0,t=0,num=1;
    freopen("article.txt","r",stdin);
    while ((c=getchar())!=EOF)
    {
        
        
            if (isalpha(c))
            {
                t=1;
                if (isupper(c))
                {
                    a[n][m++]=tolower(c);
                }
                else a[n][m++]=c;
            }
            else
            {
                if (t==0) continue;
                else
                {
                    m=0;n++;t=0;
                }
            }
        
    }
    if (m>0) n++;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (strcmp(a[j],a[j+1])>0)
            {
                strcpy(u,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],u);
            }
        }
    }
    /*for (i=0;i<n;i++)
    {
        printf("%s\n",a[i]);
    }*/
    t=0;
    for (i=0;i<n;i++)
    {
        strcpy(u,a[i]);
        if (strcmp(a[i],a[i+1])==0)
        {
            num++;
        }
        else
        {
            printf("%s %d\n",u,num);
            num=1;
        }
    }
    return 0;
}


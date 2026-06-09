#include<stdio.h>
int a[100],top=-1;
int main()
{
    int ord;
    while(scanf("%d",&ord))
        switch(ord)
        {
        case 1:
            if(top!=99)
            {
                scanf("%d",&a[++top]);
            }
            break;
        case 0:
            if(top!=-1)
            {
                printf("%d ",a[top]);
                a[top--]=0;
            }
            else printf("error ");
            break;
        case -1:
            return 0;
        }
    return 0;
}


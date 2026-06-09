#include <stdio.h>
#define MAXSIZE 100

int main()
{
    int a[MAXSIZE]={0};
    int top=-1;
    int cond;
    int temp;
    while(1)
    {
        scanf("%d",&cond);
        switch (cond)
        {
        case 1:
            scanf("%d",&temp);
            if(top==MAXSIZE-1)
                printf("error ");
            else
                a[++top]=temp;
            break;
        case 0:
            if(top==-1)
                printf("error ");
            else    
                printf("%d ",a[top--]);
            break;
        case -1:
            return 0;
        default:
            printf("error ");
            break;
        }
    }

}

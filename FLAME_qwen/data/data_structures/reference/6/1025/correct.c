#include<stdio.h>
int main()
{int stack[101],top=-1;
int c,n;
while(1)
    {
        scanf("%d",&c);
        if(c==-1)
            break;
        else if(c==1)
            scanf("%d",&stack[++top]);
        else
        {
            if(top==-1)
                printf("error ");
            else
                printf("%d ",stack[top--]);
        }
    }
return 0;
}

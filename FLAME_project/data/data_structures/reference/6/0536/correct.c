#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top=-1;
int main()
{
    int op,x,y;
    while(scanf("%d",&op)!=EOF){
        if(op==1){
            scanf("%d",&x);
            if(top==99)
                printf("error ");
            else
                stack[++top]=x;
        }
        if(op==0){
            if(top==-1)
                printf("error ");
            else{
                y=stack[top--];
                printf("%d ",y);
            }
        }
        if(op==-1)
            return 0;
    }
}


#include <stdio.h>

int main()
{
    int top = -1,m,n,op;
    int stack[110] = {0};

    while(1){
        scanf("%d",&op);
        if(op == 1){
            scanf("%d",&m);
            if(top == 99){
                printf("error ");
                continue;
            }
            else
                stack[++top] = m;
        }
        else if(op == 0){
            if(top == -1){
                printf("error ");
                continue;
            }
            else
                printf("%d ",stack[top--]);
        }
        else{
            break;
        }
    }

    return 0;
}


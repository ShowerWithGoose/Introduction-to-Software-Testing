#include <stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];

int main(){
    int op,n,top=-1;
    scanf("%d",&op);
    while (op!=-1)
    {
        if(op==1){
            scanf("%d",&n);
            stack[++top]=n;
        }
        else{
            if(top!=-1){
                printf("%d ",stack[top]);
                top--;
            }
            else
                printf("error ");
        }
        scanf("%d",&op);
    }
    return 0;
}




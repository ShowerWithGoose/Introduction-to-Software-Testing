#include<stdio.h>
int Stack[100];
int top=-1;
int main()
{
    int op;
    while(~scanf("%d",&op)){
        if(op==-1){
            return 0;
        }else if(op==1){
            int num;
            scanf("%d",&num);
            Stack[++top]=num;
        }else if(op==0){
            if(top<0){
                printf("error ");
            }else{
                printf("%d ",Stack[top--]);
            }
        }
    }
}

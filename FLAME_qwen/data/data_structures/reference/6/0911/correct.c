#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int s[100]; // stack
int top = -1;
int is_empty(){
    return (top == -1);
}
int is_full(){
    return (top == 99);
}
int main()
{
    int op, num;
    while(scanf("%d",&op)!=EOF){
        if(op == -1)
            break;
        else if(op == 1){
            scanf("%d",&num);
            if(is_full()){
                printf("error ");
            }
            else{
                s[++top] = num;
            }
        }
        else if(op == 0){
            if(is_empty()){
                printf("error ");
            }
            else{
                num = s[top];
                s[top] = 0;
                top -= 1;
                printf("%d ",num);
            }
        }
    }
    system("pause");
    return 0;
}

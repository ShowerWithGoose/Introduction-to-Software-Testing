#define MAXSIZE 100

#include <stdio.h>
#include <string.h>

int stack[MAXSIZE], top = -1;

int main(){
    int op, val;
    while(scanf("%d", &op) != EOF){
        getchar();
        if(op == 1){
            scanf("%d", &val);
            getchar();
            stack[++top] = val;
        }else if(op == 0){
            if(top < 0){
                printf("error ");
                continue;
            }
            printf("%d ", stack[top--]);
        }else{
            break;
        }
    }
    return 0;
}


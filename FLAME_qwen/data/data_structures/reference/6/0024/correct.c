#include<stdio.h>
#include<string.h>
#define base 1
#define top 101

int main(){
    int stack[105];
    int op = 0, num = 0, numgas = 0, topPin = 1;
    while(1){
        scanf("%d", &op);
        if(op == 1){
            if(topPin == top){          //栈满no pop
                scanf("%d", &numgas);
                printf("error ");
            }
            else{
                scanf("%d", &num);
                stack[topPin++] = num;
            }
        }
        else if(op == 0){
            if(topPin == base){
                printf("error ");
            }
            else{
                printf("%d ", stack[--topPin]);
            }

        }
        else if(op == -1)
            break;
    }


}

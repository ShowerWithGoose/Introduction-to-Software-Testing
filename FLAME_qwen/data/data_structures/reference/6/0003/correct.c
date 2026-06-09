#include <stdio.h>

int STACK[100];
int TOP = -1;
int op,num;

int main(){
    while(1){
        scanf("%d",&op);
        if (op == 1){
            scanf("%d",&num);
            if (TOP==99) printf("error ");
            else STACK[++TOP] = num;
        }
        else if (op == 0){
            if (TOP == -1)printf("error ");
            else{
                printf("%d ",STACK[TOP]);
                STACK[TOP--] = 0;
            }
        }
        else break;
    }
    return 0;
}

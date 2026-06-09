#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int A[10000];

int main(){

    int l = 0;
    int op,temp;
    while(1){
        scanf("%d",&op);
        if(op == 1){
            if(l == 100){
                printf("error ");
                scanf("%d",&temp);
            }else{
                scanf("%d",&A[l ++]);
            }
        }else if(op == 0){
            if(l == 0){
                printf("error ");
            }else{
                printf("%d ",A[-- l]);
            }
        }else if(op == -1){
            break;
        }
    }
}

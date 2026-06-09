//
// Created by  on 2022-03-31.
// DS4-1 栈操作
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MSIZE 101
int main(){
    int stk[MSIZE] = {0};
    int size = 0;
    int op;
    while(scanf("%d",&op)){
        int val;
        switch (op) {
            case -1:
                exit(0);
            case 0:
                if(size>0){
                    printf("%d ",stk[--size]);
                }else{
                    printf("error ");
                }
                break;
            case 1:
                scanf("%d",&val);
                if(size<100){
                    stk[size++]=val;
                }else{
                    printf("error ");
                }
        }
    }
}


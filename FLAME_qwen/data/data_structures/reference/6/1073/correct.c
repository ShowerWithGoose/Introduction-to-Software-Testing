#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zhan[100];

int push(int ind, int val){
    if(ind == 99){
        printf("error ");
        return ind;
    }
    zhan[ind++] = val;
    return ind;
}

int pop(int ind){
    if(ind==0){
        printf("error ");
        return ind;
    }
    printf("%d " , zhan[--ind]);
    return ind;
}

int main(){
    int ind = 0 , val , flag;
    while(1){
        scanf("%d" , &flag);
        switch(flag){
            case 1: scanf("%d" , &val);
            ind = push(ind , val); break;
            case 0: ind = pop(ind); break;
            case -1: return 0;
        }
    }
}




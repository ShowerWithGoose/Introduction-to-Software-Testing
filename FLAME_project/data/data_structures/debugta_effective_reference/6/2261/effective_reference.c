//
//  main.c
//  栈基本操作
//
//  Created by  on 2022/4/14.
//

#include <stdio.h>
#define MAXSIZE 101
struct zhan{
    int num[MAXSIZE];
    int pointer;
}stem;
int digit=0, follow;
int isempty(struct zhan *s){
    return s->pointer == -1;
}
int isfull(struct zhan *s){
    return s->pointer == MAXSIZE;
}
int pushzhan(struct zhan *s, int digit){
    if(isfull(s)){
        printf("error ");
        return 0;
    }
    s->pointer++;
    s->num[s->pointer]=digit;
    return 1;
}
int quitzhan(struct zhan *s, int digit){
    if(s->pointer==-1){
        printf("error ");
        return 0;
    }
    digit = s->num[s->pointer];
    s->pointer--;
    printf("%d ", digit);
    return 1;
}
int main() {
    int op;
    stem.pointer=-1;
    while(1){
        scanf("%d", &op);
        if(op==-1)
            break;
        else if(op==0)
            quitzhan(&stem,digit);
        else if(op==1){
            scanf("%d", &follow);
            pushzhan(&stem,follow);
        }
    }
    printf("\n");
    return 0;
}


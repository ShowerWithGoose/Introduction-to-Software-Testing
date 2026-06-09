#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct lnode{
    int con;
    struct lnode *next;
}lnode , *linklist;

void push(linklist a , int b){
    linklist c;
    c = (linklist)malloc(sizeof(lnode));
    c->con = b;
    c->next = a->next;
    a->next = c;
}

void pop(linklist a){
    printf("%d " , a->next->con);
    a->next = a->next->next;
}

int main(){
    linklist l;//头指针
    l = (linklist)malloc(sizeof(lnode));
    l->next = NULL;
    int n , hold , len = 0;
    while(1){
        int flag = 0;
        scanf("%d" , &n);
        switch(n){
            case 1:
                if(len == 100){
                    printf("error ");
                    break;
                }
                scanf("%d" , &hold);
                push(l, hold);
                len++;
                break;
            case 0:
                if(len == 0){
                    printf("error ");
                    break;
                }
                pop(l);
                len--;
                break;
            case -1:
                flag = 1;
                break;
        }
        if(flag == 1)   break;
    }
    return 0;
}
//1 3 1 5 1 7 0 0 1 8 0 1 12 1 13 0 0 0 0 1 90 1 89 0 -1


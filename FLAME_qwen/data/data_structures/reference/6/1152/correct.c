#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long

typedef struct node1{
    int num;
    struct node1 *l;
}list;

typedef struct node2{
    int num;
    struct node1 *top;
}stack;

void push_s(stack *s, int num){
    list *temp = (list*)malloc(sizeof(list));
    temp->num = num;
    temp->l = s->top;
    s->top = temp;  
    s->num += 1;
    return;
}

int top_s(stack *s){
    return s->top->num;
}

int size_s(stack *s){
    return s->num;
}

void init_s(stack *s){
    s->top = NULL;
    s->num = 0;
    return;
}

void pop_s(stack *s){
    list *temp = s->top;
    s->top = temp->l;
    s->num -= 1;
    free(temp);
    return;
}

int main(){
//    freopen("r.txt","r",stdin);
//    freopen("w.txt","w",stdout);
    int max = 100;
    int op;
    int num;
    stack *it = (stack*)malloc(sizeof(stack));
    init_s(it);
    while(scanf("%d",&op)){
//        if(op == -1) break;
        switch(op){
            case 1:
                scanf("%d",&num);
                if(size_s(it) >= max){
                    printf("error ");
                    break;
                }else{
                    push_s(it,num);
                    break;
                }
            case 0:
                if(size_s(it) == 0){
                    printf("error ");
                    break;
                }else{
                    printf("%d ",top_s(it));
                    pop_s(it);
                    break;
                }
            case -1:
                return 0;
        }
    }
    return 0;
}

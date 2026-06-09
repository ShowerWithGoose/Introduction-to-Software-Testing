#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int val;
    struct stack * next;
};
int lenth = 0;

void push(struct stack**head,int ival){
    if(lenth == 100){
        printf("error ");return;
    }

    struct stack*tmp = malloc(sizeof(struct stack));
    tmp -> val = ival;tmp->next = *head;
    (*head) = tmp;
    lenth++;
}

int pop(struct stack**head){
    if(lenth == 0){
        printf("error ");return 0;
    }

    struct stack*tmp = (*head);
    (*head) = (*head) -> next;
    int ret = tmp ->val;
    free(tmp);lenth--;
    return ret;

}


int main(){
    struct stack * stack = NULL;
    int op,q;
    while(scanf("%d",&op)){
        if(op == 1){
            scanf("%d",&q);
            push(&stack,q);
        }
        else if(op == 0){
            int m = pop(&stack);
            if(m != 0)
            printf("%d ",m);
        }
        else if(op == -1){
            break;
        }

    }
    return 0;


}

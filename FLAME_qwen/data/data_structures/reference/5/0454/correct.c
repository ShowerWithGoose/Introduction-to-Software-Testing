#include <stdio.h>
#include <stdlib.h>

struct Node{
    long long index;
    long long num;
    struct Node*next;
};
typedef struct Node node;
typedef node* Ptrnode;

Ptrnode insert(long long iIndex,long long iNum,Ptrnode l){
    Ptrnode q = malloc(sizeof(node));
    q ->index = iIndex;q->num = iNum;
    q->next = l->next;
    l->next = q;
    return l;
}

Ptrnode order(long long iIndex,long long iNum,Ptrnode list){
    int flag = 1;
    Ptrnode q = list;
    while(q ->next){
        if(iIndex < (q->next->index))
            q = q->next;
        else if(iIndex > (q ->next->index)){
            Ptrnode tmp;
            tmp = malloc(sizeof(node));
            tmp->index = iIndex;tmp->num =iNum;
            tmp ->next = q->next;
            q ->next = tmp;
            flag = 0;
            break;
        }
        else{
            
            q->next->num   += iNum;
            flag = 0;
            break;           
        }
        
    }

        if(flag){
            Ptrnode tail = malloc(sizeof(node));
            tail->index = iIndex;tail->num = iNum;tail->next =NULL;
            q ->next = tail;
        }

    return list;    
}

int main(){
    node *a = malloc(sizeof(node));
    node *b = malloc(sizeof(node));
    a ->next =NULL;b->next =NULL;

    int flag;
    long long iIndex,iNum,last;
    flag = 0;
    last = 2147483648;
    
    while(scanf("%lld%lld",&iNum,&iIndex) != EOF){
        if(iIndex >= last)
        flag = 1;

        last = iIndex;

        if(flag == 0)
        a =insert(iIndex,iNum,a);
        else
        b =insert(iIndex,iNum,b);
    }
    
    node *ans = malloc(sizeof(node));
    ans->next =NULL;    
    node*q = a->next;
    while(q){
        long long rIndex,rNum;
        Ptrnode tmp = b->next;
        while(tmp){
            rIndex = q->index + tmp->index;
            rNum = q->num * tmp->num;
            ans = order(rIndex,rNum,ans);
            tmp = tmp ->next;
        }
        q=q->next;
    }

    while(ans->next){
        printf("%lld %lld ",ans->next->num,ans->next->index);
        ans = ans->next;
    }

    while(ans){
        Ptrnode q = ans;
        ans = ans->next;
        free(q);
    }
    while(a){
        Ptrnode q = a;
        a = a->next;
        free(q);
    }
    while(b){
        Ptrnode q = b;
        b = b->next;
        free(q);
    }

    return 0;

}

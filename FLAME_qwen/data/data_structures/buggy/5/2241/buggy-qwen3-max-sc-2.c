#include <stdio.h>
#include<stdlib.h>
struct mul{
    int coe ; 
    int pow ; 
    struct mul *next;
}; 
struct mul *head =NULL ,*p = NULL,*q = NULL,*ans = NULL,*r = NULL,*k = NULL;
//ans 是答案链表，r,k 用于答案链表；
int main(){
    int a,n;
    char c;
//创建一个链表存放第一个多项式
    do { 
    scanf("%d%d%c", &a, &n, &c);
    if( head == NULL) 
        head = p = (struct mul *)malloc(sizeof(struct mul));
    else {
        p->next = (struct mul *)malloc(sizeof(struct mul));
        p = p->next;
    }
    p->coe = a; p->pow = n; p->next = NULL;
    } while(c != '\n');
    
//    p = head;
//    while(p!= NULL){
//        printf("%d %d ",p->coe,p->pow);
//        p = p ->next;
//    }
//    printf("\n\n\n");
    
    p = head;
    do{
        scanf("%d%d%c",&a,&n,&c);
        do{
            q = (struct mul*)malloc(sizeof(struct mul));
            q->coe =a * (p ->coe);
            q->pow =n + (p ->pow);
            q->next = NULL;
//            printf("%d %d \n",q->coe ,q->pow);
            if(ans == NULL)        //ans是一个空表
                {
                ans = q;
                p = p->next;
                continue;
                }
            for(r = ans; r != NULL && q->pow < r->pow; k = r, r = r->next) ;
            //for用来确定位置
            if(r == NULL){
                k ->next = q; @@ [k is uninitialized when ans has only one node and q->pow is less than that node's pow, leading to undefined behavior]
            }
            else if(q->pow == r->pow){
                r ->coe += k-> next ->coe; @@ [k is uninitialized when r == ans (i.e., at the head), so k->next is invalid; should add q->coe to r->coe directly]
            }
            //在头节点之前
            else if(r == ans){
                q->next = ans;
                ans = q;
            }
            else{
                k->next = q;
                q->next = r;
            }
            
            p = p->next;
        }while(p!= NULL);             //与上面每一个数字相乘
        p = head;                    //循环结束让p归位
    }while(c != '\n');
    
    while(ans!= NULL){
        if(ans ->coe != 0){
            printf("%d %d ",ans->coe,ans->pow);
        }
        ans = ans ->next;
    }
    return 0;    
}
/*
10 80000 2 6000 7 300 5 10 18 0
3 6000 5 20 8 10 6 0

*/
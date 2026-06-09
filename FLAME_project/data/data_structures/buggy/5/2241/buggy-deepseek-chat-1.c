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
                p = p->next; // @@ [Error: When ans is NULL, after setting ans = q, p is advanced to the next node, but then the loop continues without inserting the first term into ans properly. Additionally, the 'continue' skips the rest of the loop, but p has already been moved, causing the first term of the first polynomial to be skipped in subsequent iterations of the inner loop. The correct approach is to set ans = q and then continue without moving p, so that the inner loop processes all terms of the first polynomial correctly.]
                continue;
                }
            for(r = ans; r != NULL && q->pow < r->pow; k = r, r = r->next) ;
            //for用来确定位置
            if(r == NULL){
                k ->next = q;
            }
            else if(q->pow == r->pow){
                r ->coe += k-> next ->coe; // @@ [Error: This line incorrectly adds the coefficient of the node after k (which is r) to r->coe, but it should add q->coe to r->coe. The correct operation is r->coe += q->coe. Additionally, this does not free the memory of q, causing a memory leak, but the main issue is the incorrect coefficient addition.]
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
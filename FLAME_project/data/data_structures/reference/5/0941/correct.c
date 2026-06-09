#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    int a;
    int n;
    struct Node *next;
};
int main(){
    int a,n;
    char c;
    struct Node *ptr,*q,*first,*ptr2,*q2,*first2,*tem;
    scanf("%d%d",&a,&n);
    first = q = ptr = (struct Node*)malloc(sizeof(struct Node));//储存Ax
    q->a = a;
    q->n = n;
    c = getchar();
    while(c != '\n'){
        scanf("%d%d",&a,&n);
        ptr->next = (struct Node*)malloc(sizeof(struct Node));
        ptr = ptr->next;
        ptr->a = a;
        ptr->n = n;
        c = getchar();
    }
    ptr2 = q2 = first2 = (struct Node*)malloc(sizeof(struct Node));//储存结果
    scanf("%d%d",&a,&n);
    //printf("%d %d\n",a,n);
    q = first;
    while(1){
        ptr2->a = q->a * a;
        ptr2->n = q->n + n;
        ptr2->next = (struct Node*)malloc(sizeof(struct Node));
        if(q == ptr){
            break;
        }
        ptr2 = ptr2->next;
        q = q->next;
    }
    while(scanf("%d%d",&a,&n) != EOF){
        //printf("%d %d\n",a,n);
        q = first,q2 = first2;
        while(1){
            tem = (struct Node*)malloc(sizeof(struct Node));
            tem->a = q->a * a;
            tem->n = q->n + n;
            while(tem->n < q2->next->n && q2 != ptr2){
                q2 = q2->next;
                if(q2 == ptr2) break;
            }
            if(q2 == ptr2){
                ptr2->next = tem;
                ptr2 = ptr2->next;
            }
            else if(tem->n == q2->next->n){
                q2->next->a += tem->a;
            }
            else if(tem->n > q2->next->n){
                tem->next = q2->next;
                q2->next = tem;
            }
            if(q == ptr){
                break;
            }
            q = q->next;
        }
    }
    q2 = first2;
    while(q2 != ptr2){
        printf("%d %d ",q2->a,q2->n);
        q2 = q2->next;
    }
    printf("%d %d ",q2->a,q2->n);
    system("pause");
    return 0;
}

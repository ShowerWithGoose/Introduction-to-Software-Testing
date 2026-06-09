#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coe;
    int pow;
    struct Node *next;
};
int destroyList (struct Node * list);
int main() 
{
    int a,n;
    char c;
    struct Node *head1,*head2,*head3,*p,*p2,*p3,*q,*m;
    head1=p=NULL;
    do {  //创建一个链表存放第一个多项式
        scanf("%d%d%c", &a, &n, &c);
        q =  (struct Node *)malloc(sizeof(struct Node));
        q->coe = a; q->pow = n; q->next = NULL;
        if( head1 == NULL) 
             head1 = p = q;
       else {
            p->next = q;
            p = p->next;
       }
    } while ( c != '\n');
    head2=p=NULL;
    do {  //创建一个链表存放第一个多项式
        scanf("%d%d%c", &a, &n, &c);
        q =  (struct Node *)malloc(sizeof(struct Node));
        q->coe = a; q->pow = n; q->next = NULL;
        if( head2 == NULL) 
             head2 = p = q;
       else {
            p->next = q;
            p = p->next;
       }
    } while ( c != '\n');
    head3=p3=NULL;
    m=NULL;
    for(p=head1; p != NULL; p=p->next)
    for(p2=head2; p2 != NULL; p2=p2->next){
        a=p->coe * p2->coe ;
        n=p->pow + p2->pow ;
        q =  (struct Node *)malloc(sizeof(struct Node));
        q->coe = a; q->pow = n; q->next = NULL;
        if(head3==NULL)
        head3=p3=q;
        for(p3=head3; p3!=NULL; m=p3,p3=p3->next) {
            if(q->pow > p3->pow) { 
                 if(p3==head3) { q->next = head3; 
                 head3 = q; 
                 break; }//插入到头节点前
                 else { q->next = p3;
                  m->next = q; 
                  break;} //将q插入到p前
            }
            else if(q->pow == p3->pow)  { p3->coe += q->coe; 
            break;}//指数相等，系数相加
         }
         if(p3== NULL)  
         m->next = q; // @@ [当head3不为空且q的指数小于所有已有节点时，m可能未正确更新，导致插入位置错误；且此处未处理q与已有节点指数相等的情况，但已在循环中处理。主要问题在于当q的指数小于所有节点时，循环结束后p3为NULL，但m可能指向最后一个节点，此时应追加到末尾，但若m未初始化（如head3只有一个节点且q指数更小），则m可能为NULL，导致段错误或错误插入。]
    }
    for(p3=head3;p3!=NULL;p3=p3->next )
    printf("%d %d ",p3->coe ,p3->pow );
    destroyList(head1);
    destroyList(head2);
    destroyList(head3);
    return 0;
}
int destroyList (struct Node * list){
    if(NULL==list){
        printf("list==NULL\n");
        return -1;
    }
    struct Node *p,*q;
    for(p=list; p!=NULL; ){
        q=p;
        p=p->next ;
        free(q);
    }
    return 0;

}
#include <stdio.h>
#include <stdlib.h>
int cheng1(){
    int a0;
    scanf("%d", &a0);
    return a0;
}
int cheng2(){
    int n0;
    scanf("%d", &n0);
    return n0;
}
char cheng3(){
    char c0;
    scanf("%d", &c0); // @@ [Incorrect format specifier: using %d to read a char variable causes undefined behavior and likely compilation warning/error due to type mismatch]
    return c0;
}
typedef struct  Node { //一个多项式节点结构
    int coe; //系数
    int pow; //幂
    struct Node *next;
}Node,*Nodeptr;

int main()
{
    int a,n,a2,n2;
    char c;
    Node *head1,*head2 = NULL,*p1,*p2,*q1,*q2,*p0 = NULL;
    head1 = p1 = NULL;
    do {  //创建一个链表存放第一个多项式
        a = cheng1();
        n = cheng2();
        c = cheng3();
        q1 =  (Nodeptr)malloc(sizeof(Node));
        q1->coe = a; q1->pow = n; q1->next = NULL;
        if( head1 == NULL)
            head1 = p1 = q1;
        else {
            p1->next = q1;
            p1 = p1->next;
        }
    } while ( c != '\n');
    
    
    do { //将第二个多项式的每个项插入到第一个多项式链表中
        a = cheng1();
        n = cheng2();
        c = cheng3();
        for(p1=head1; p1!=NULL; p1=p1->next) {
            
            //将第二个多项式的每个项与第一个多项式的每个项相乘（系数相乘，指数相加）
            a2=a*p1->coe;
            n2=n+p1->pow;
            
            //然后插入第三个链表的相应位置/排序
            q2 = (struct Node *)malloc(sizeof(struct Node));
            q2->coe = a2; q2->pow = n2; q2->next = NULL;
            
            if( head2 == NULL)
                head2 = p2 = q2;//第一次是空链表
            else{
            for(p2=head2; p2!=NULL; p0=p2,p2=p2->next) {
                if(q2->pow > p2->pow) {
                    if(p2==head2) { q2->next = head2; head2 = q2; break; }//插入到头节点前
                    else { q2->next = p2; p0->next = q2; break;} //将q插入到p前
                }
                else if(q2->pow == p2->pow)  { p2->coe += q2->coe; break;}//指数相等，系数相加
            }
            if(p2== NULL)  p0->next = q2;   //将q插入到尾节点后    
            }
        }
    } while ( c != '\n');
    
    for(p2=head2; p2!=NULL; p2=p2->next)
    printf("%d %d ", p2->coe,p2->pow);
    printf("\n");
    return 0;
}
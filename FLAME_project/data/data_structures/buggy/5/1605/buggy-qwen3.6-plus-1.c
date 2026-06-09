#include<stdio.h>
#include<stdlib.h>
struct ppe {
    long long int m;
    long long int n;
};
struct ppe data;
struct node {
    struct ppe data;
    struct node* link ;
};
typedef struct node *nodeptr;
typedef struct node zu;
struct ppe mon[1000];
int i=1,j;
int main() {
    long long    int a,u;
    char c,f;
    nodeptr p,q,head,e,r,first;
    head=p=NULL;
    do {
        scanf("%lld%lld",&a,&u);
        c=getchar();
        q=(nodeptr)malloc(sizeof(zu));
        q->data.m=a;
        q->data.n=u;
        q->link=NULL;
        if(head==NULL)
            head=p=q;
        else {
            p->link=q;
            p=p->link;
        }

    } while(c!='\n');
    do {
        scanf("%lld%lld",&a,&u);
        f=getchar();
        for(p=head; p!=NULL; p=p->link) {
            long long int xx,yy;
            xx=(p->data.m)*a;
            yy=(p->data.n)+u;
            mon[i].m=xx;
            mon[i].n=yy;
            i++;
        }//把链表相乘的结果读入到mon中
    } while(f!='\n');//读入两个链表

    int num=i-1;
    long long int rr,nn;
    for(i=1; i<=num; i++) {
        for(int j=i+1; j<=num; j++) {
            if(mon[j].n>mon[i].n) {
                rr=mon[j].m;
                nn=mon[j].n;
                mon[j].m=mon[i].m;
                mon[j].n=mon[i].n;
                mon[i].m=rr;
                mon[i].n=nn;
            }
        }
    }//排序
    for(i=1; i<=num; i++) {int sign=0;
        for( j=i+1; j<=num; j++) {
            if(mon[i].n!=mon[j].n) break;
            else {
                mon[i].m=mon[i].m+mon[j].m;
                mon[j].m=0;sign=1;
            }
        }if(sign==1) i=j-1; // @@ [The loop increment `i++` will execute after the body. If we set `i=j`, the next iteration starts at `j+1`, skipping the term at `j` which might be the start of a new group or just incorrectly advancing. More importantly, if `j` broke out because `mon[i].n != mon[j].n`, `j` points to the first different exponent. We want the outer loop to continue from `j`. However, standard for-loop logic: if we set `i = j - 1`, then `i++` makes it `j`. If we set `i = j`, `i++` makes it `j + 1`, skipping index `j`. The term at `j` is the first one with a *different* exponent, so it should be processed in the next iteration. Thus, we should set `i` such that after increment it becomes `j`. So `i` should be `j-1`. Wait, let's trace. Inner loop finds consecutive same exponents starting at `i`. It stops when `mon[j].n != mon[i].n` or end. If it merged some terms, `sign=1`. The next unique exponent is at `j`. The outer loop will do `i++`. So we need `i` to become `j-1` so that `i++` makes it `j`. The original code had `i=j`, which would make next `i` equal to `j+1`, skipping the term at `j`. This causes the loss of terms or incorrect processing, leading to Wrong Answer.]
    }//整合
    for(i=1; i<=num; i++) {
        if(mon[i].m!=0) {
            printf("%lld %lld ",mon[i].m,mon[i].n);
        }
    }
    return 0;
}
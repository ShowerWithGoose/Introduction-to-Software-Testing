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
        }if(sign==1) i=j; // @@ [Error: When sign==1, i is set to j, but after the loop increments i, it skips the next index. This causes incorrect merging of terms with the same exponent, leading to missing or wrong coefficients in the output. For example, when merging exponents 7, the code skips index 8 and fails to combine all terms correctly.]
    }//整合
    for(i=1; i<=num; i++) {
        if(mon[i].m!=0) {
            printf("%lld %lld ",mon[i].m,mon[i].n);
        }
    }
    return 0;
}
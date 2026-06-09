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
        }if(sign==1) i=j-1; // @@ [The loop increment `i++` will execute after the body. If we set `i=j`, the next iteration starts at `j+1`, skipping the term at `j` which might be the start of a new group or just incorrectly advancing. More importantly, when merging terms, if `mon[i]` absorbs `mon[j]`, `mon[j]` becomes 0. The outer loop continues. The logic `i=j-1` ensures that after `i++` in the for loop, `i` becomes `j`, effectively moving to the next unprocessed term. However, the standard way to skip merged terms is usually handled by checking if `mon[i].m != 0` later or adjusting indices carefully. Let's look closer. If `sign==1`, it means we merged terms from `i+1` up to `j-1` into `i`. The term at `j` has a different exponent (break condition). So the next term to process as a "base" for merging should be `j`. Since the for loop does `i++`, setting `i = j - 1` results in `i` becoming `j` in the next step. Setting `i=j` would result in `i` becoming `j+1`, skipping the term at `j` entirely if it wasn't merged, or if it was the break condition. Wait, the break happens when `mon[i].n != mon[j].n`. So `j` is the first term with a *different* exponent. We want to process `j` next. So `i` should become `j-1` so that `i++` makes it `j`. The original code `i=j` makes `i` become `j+1`, skipping the term at index `j`. This causes the term at `j` (which has a unique exponent relative to the previous group) to be skipped in the outer loop's role as a "merger base", although it will still be printed if non-zero. However, if there were subsequent terms equal to `j`'s exponent, they wouldn't be merged into `j` because `j` was skipped as a base. In this specific case, the error is likely that terms are not being merged correctly if there are more than 2 terms with the same exponent, or simply skipping a valid term. Let's re-read the merge logic. It merges `j` into `i`. If `sign` is 1, it means at least one merge happened. The loop breaks when `mon[j].n != mon[i].n`. So `mon[1..j-1]` have same exponent. `mon[j]` has different. We want next `i` to be `j`. So `i` should be set to `j-1`. Original: `i=j`. Error: Skips index `j`.]
    }//整合
    for(i=1; i<=num; i++) {
        if(mon[i].m!=0) {
            printf("%lld %lld ",mon[i].m,mon[i].n);
        }
    }
    return 0;
}
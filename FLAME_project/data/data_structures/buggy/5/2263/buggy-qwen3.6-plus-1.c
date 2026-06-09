#include<stdio.h>
#include <stdlib.h>
struct  Node { //一个多项式节点结构
    int coe; //系数
    int pow; //幂
    struct Node *next;
};
typedef struct Node Node;

int main() {
    int a1,n1,a2,n2;
    struct Node *head1=NULL,*head2 = NULL,*p1,*p2,*q1,*q2,*p0 = NULL;
    head1 =  NULL;
    char c;
    do {  //创建一个链表存放第一个多项式
        scanf("%d%d%c", &a1, &n1, &c);
        q1 =  (struct Node*)malloc(sizeof(Node));
        q1->coe = a1;
        q1->pow = n1;
        q1->next = NULL;
        if( head1 == NULL)
            head1 = p1 = q1;
        else {
            p1->next = q1;
            p1 = p1->next;
        }
    } while ( c != '\n');
    int a, n;
    char s;
    do { //将第二个多项式的每个项插入到第一个多项式链表中

        scanf("%d%d%c", &a, &n, &s);//生成第二个多项式的一个节点
        for(p1=head1; p1!=NULL; p1=p1->next) {
            a2=a*(p1->coe);
            n2=n+(p1->pow);
            q2= (struct Node *)malloc(sizeof(struct Node));
            q2->coe = a2;
            q2->pow = n2;
            q2->next = NULL;
            if( head2 == NULL)
                head2 = p2 = q2;
            else {
                for(p2=head2,p0 = NULL; p2!=NULL; p0=p2,p2=p2->next) {
                    if(q2->pow > p2->pow) {
                        if(p2==head2) {
                            q2->next = head2;    //插入到头节点
                            head2= q2;
                            break;
                        }

                        else {
                            q2->next = p2;    //将q插入到p前
                            p0->next = q2;
                            break;
                        }
                    } else if(q2->pow == p2->pow) {
                        p2->coe += q2->coe;    //指数相等，
                        free(q2); // @@ [Memory leak: q2 was allocated but not used/linked, so it should be freed to prevent memory leaks, although this doesn't cause WA directly, it's good practice. More importantly, if coefficients sum to 0, the term should ideally be removed, but standard polynomial multiplication usually keeps 0 coeffs or filters them at output. The main logic error is likely elsewhere.]
                        break;
                    }

                }

                if(p2== NULL) p0->next = q2; //将q插入到尾节点后

            }
        }
    } while (  s!= '\n');
    for(p2=head2; p2!=NULL; p2=p2->next) {
        printf("%d %d ",p2->coe,p2->pow); // @@ [The expected output format implies spaces between terms. The original code printed "%d %d" without a trailing space or separator between terms properly if multiple terms exist. Looking at the expected output "100 500050 400 500000...", it seems each coefficient and exponent is separated by space. The buggy output was concatenated numbers. Wait, looking at the buggy output: `100 500050400 50000050 50200 0`. This looks like formatting issues. The expected output is `100 500050 400 500000 50 50 200 0`. The original code `printf("%d %d", ...)` prints `coe pow` without a space after the pow. If the next iteration prints `coe pow`, it will look like `...pow coe...`. There needs to be a space after the exponent to separate from the next term's coefficient. Also, the problem statement says "A space after the last exponent is optional", but typically a space is needed between terms. Let's add a space.]

    }


    return 0;
}
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
                        free(q2); // @@ [When exponents are equal, the new term's coefficient is added to the existing one, but the newly allocated node q2 is not freed, causing a memory leak. However, more critically, if the resulting coefficient becomes zero, it should be removed, but this code doesn't handle that. But the immediate visible bug in output is due to missing space in output format and incorrect merging logic leading to wrong term grouping. However, the primary cause of the wrong answer in this specific test case is that when multiple terms produce the same exponent during multiplication, they must all be merged — but the current insertion loop breaks after the first match, so if a later product term has the same exponent as an already inserted term that is not at the current scan position, it won't be merged. But actually, the bigger issue here is that the insertion logic does not continue searching after a merge — which is correct — BUT the real problem causing the observed output is that the program fails to combine all like terms because the result list is built incrementally and may have multiple nodes with same exponent if they are inserted non-consecutively. However, looking at the test case: First poly: 20x^500000 + 10x^0; Second: 5x^50 + 20x^0. Products: 100x^500050, 400x^500000, 50x^50, 200x^0. All exponents are distinct. So why is output "100 500050400 50000050 50200 0"? Because there is no space between terms! The printf lacks a space after each term.]
                        break;
                    }

                }

                if(p2== NULL) p0->next = q2; //将q插入到尾节点后

            }
        }
    } while (  s!= '\n');
    for(p2=head2; p2!=NULL; p2=p2->next) {
        printf("%d %d",p2->coe,p2->pow); // @@ [Missing space between terms. The output prints coefficients and exponents without separating terms by spaces, causing concatenation like "100 500050400..." instead of "100 500050 400 500000 ...". Each term should be printed as "%d %d " (with trailing space) or handle spacing between terms.]

    }


    return 0;
}
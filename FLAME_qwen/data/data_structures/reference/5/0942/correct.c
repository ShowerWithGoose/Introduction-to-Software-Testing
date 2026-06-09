#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int a;
	int x;
	struct node *link;
} ;
typedef struct node *Nodeptr;
typedef struct node Node;

Nodeptr add(Nodeptr ans, Nodeptr q) {
	Nodeptr p = NULL;

	if (ans == NULL) {
		ans = q;
		// printf("here1");
	} else {
		p = ans;
		if (q->x > p->x) {
			ans = q;
			q->link = p;
			printf("here2");
		} else {
			while (p != NULL) {
				if (p->x == q->x) {
					break;
				}
				if (p->link->x < q->x) {
					break;
				}
				p = p->link;
				printf("here3");

			}
			printf("q= %d p=%d \n", q->x, p->x);
			if (p->x == q->x) {
				p->a += q->a;
			} else {
				q->link = p->link;
				p->link = q;
			}
		}
	}
	return ans;
}

int main() {
	int a1, x1;
	char c;
	Nodeptr list1 = NULL;
	Nodeptr p = NULL;
	Nodeptr q = NULL;
	Nodeptr ans = NULL;
	do {
		scanf("%d%d%c", &a1, &x1, &c);
		q = (Nodeptr)malloc(sizeof(Node));
		q->a = a1;
		q->x = x1;
		q->link = NULL;
		if (list1 == NULL) {
			list1 = q;
			p = q;
		} else {
			p->link = q;
			p = p->link;
		}
	} while (c != '\n');
	// printf("%d",p->x);
	// 可以考虑将第二个多项式的一项与
	// 第一个多项式相乘
	// 然后将用一个ans存储答案;
	do {
		scanf("%d%d%c", &a1, &x1, &c);
		Nodeptr r = list1;
		while (r != NULL) {
			q = (Nodeptr)malloc(sizeof(Node));
			q->a = a1 * (r->a);
			q->x = x1 + (r->x);
			q->link = NULL;
			Nodeptr m = NULL;
			// if (ans == NULL) {
			// 	printf("NULL q=%d\n", q->x);
			// } else {
			// 	printf("come q=%d\n", q->x);
			// }
			if (ans == NULL) {
				ans = q;
				// printf("here1");
			} else {
				m = ans;
				if (q->x > m->x) {
					ans = q;
					q->link = m;
					// printf("here2");
				} else {
					// printf("fuck%d   q=%d \n", m->x,q->x);
					while (m != NULL) {
						if (m->x == q->x) {
							// printf("fuck1");
							break;
						}
						if(m->link==NULL){
							// printf("fuck3");
							break;
						}
						if (m->link->x < q->x) {
							// printf("fuck2");
							break;
						}
						m = m->link;
						// printf("here3");
					}
					// printf("q= %d p=%d \n",q->x,p->x);
					if (m->x == q->x) {
						m->a += q->a;
					} else {
						q->link = m->link;
						m->link = q;
					}
				}
			}
			// printf("%d %d ", q->a, q->x);
			r = r->link;
		}
	} while (c != '\n');
	// 加法如下
	// do{
	//     scanf("%d%d%c",&a1,&x1,&c);
	//     q=(Nodeptr)malloc(sizeof(Node));
	//     q->a=a1;
	//     q->x=x1;
	//     q->link=NULL;
	//     p=list1;
	//     if(x1>p->x){
	//         list1=q;
	//         q->link=p;
	//     }else {
	//         while(p!=NULL){
	//             if(p->x==x1){
	//                 break;
	//             }
	//             if(p->link->x<x1){
	//                 break;
	//             }
	//             p=p->link;
	//         }
	//         // printf("%d",p->x);
	//         if(p->x==x1){
	//             p->a+=a1;
	//         }else{
	//             q->link=p->link;
	//             p->link=q;
	//         }
	//     }
	// }while(c!='\n');


	p = ans;
	while (p != NULL) {
		printf("%d %d ", p->a, p->x);
		p = p->link;
	}
	return 0;
}

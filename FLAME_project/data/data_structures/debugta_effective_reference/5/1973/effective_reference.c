#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct a{
	long long xs;
	long long zs;
	struct a* next;
}node, *link;
int main(){
	long long xi, zhi, multix, multiz;
	int flag = 0;//用于标定当前读入的是表达式a还是表达式b
	link i, j, firsta = NULL, first = NULL, p = NULL, q = NULL, f = NULL, last = NULL;
	while (scanf("%lld%lld", &xi, &zhi) != EOF){
		f = (link)malloc(sizeof(node));
		f->xs = xi; f->zs = zhi, f->next = NULL;
		if (firsta == NULL){//说明一个也没有输入
			firsta = p = q = last = f;
		}
		else{
			if (f->zs < last->zs && flag == 0){//说明此时仍然是第一次输入
				p = last = f;
				p->next = NULL;
				q->next = p;
				q = p;
			}
			else{
				flag = 1;//说明进入了第二次
				for (i = firsta; i != NULL; i = i->next){
					multix = i->xs * xi; multiz = i->zs + zhi;
					if (first == NULL){//说明结果表达式是空的
						p = (link)malloc(sizeof(node));
						p->xs = multix; p->zs = multiz; p->next = NULL;
						first = last = p;
					}
					else{
						if (first->zs < multiz){//说明应该插在首节点前面
							p->next = first;
							first = p;
						}
						else{
							for (j = first; j != NULL && j->zs > multiz; j = j->next){
								q = j;
							}
							if (j == NULL || j->zs != multiz){
								p = (link)malloc(sizeof(node));
								p->xs = multix; p->zs = multiz;
								p->next = q->next;
								q->next = p;
							}
							else   j->xs += multix;
						}
					}
				}
			}
		}
	}
	for (i = first; i != NULL; i = i->next){
		if (i->xs != 0) printf("%lld %lld ", i->xs, i->zs);
	}
	return 0;
}



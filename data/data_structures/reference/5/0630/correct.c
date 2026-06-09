#include<stdio.h>
#include<stdlib.h>

struct dxs {
	int coe;
	int pow;
	struct dxs *link;
};

int main() {
	int a, n, n1=0, xs[1000], zs[1000];  //定义数组存放第一个多项式的系数和指数
	char c;
	struct dxs *list = NULL, *p = NULL, *q, *r;
	do {
		scanf("%d%d%c", &a, &n, &c);
		xs[n1] = a;
		zs[n1] = n;
		n1 ++;//确定第一个多项式有几项
	} while(c != '\n');
	scanf("%d%d%c", &a, &n, &c);//读入第二个多项式的第一项
	if(c == '\n') {
		for(int i = 0; i < n1; i ++) 
            printf("%d %d ",a * xs[i], n + zs[i]);
	} else {
		for(int i = 0; i < n1; i ++) { //以第二个多项式的第一项与第一个多项式的乘积建立链表
			q = (struct dxs *)malloc(sizeof(struct dxs));
			q->coe = a * xs[i];
			q->pow = n + zs[i];
			q->link = NULL;
			if(list == NULL)
                list = p = q;
			else {
				p->link = q;
				p = p->link;
			}
		}
		do { //继续读取第二个多项式的剩余项
			scanf("%d%d%c", &a, &n, &c);
			for(int i = 0; i < n1; i ++) { //读入第二个多项式的项时，与第一个多项式的每一项相乘
				q = (struct dxs *)malloc(sizeof(struct dxs));
				q->coe = a * xs[i];
				q->pow = n + zs[i];
				q->link = NULL;
				for(p = list; p != NULL; r = p, p = p->link) { //确定插入位置
					if(q->pow > p->pow) {
						if(p == list) {
							q->link = list;
							list = q;
							break;
						} else {
							q->link = p;
							r->link = q;
							break;
						}
					} else if(q->pow == p->pow) {
						p->coe += q->coe;
						break;
					}
				}
				if(p == NULL)
                    r->link = q;
			}
		} while(c != '\n');
		for(p = list; p != NULL; p = p->link) 
            printf("%d %d ", p->coe, p->pow);
	}
    return 0;
}


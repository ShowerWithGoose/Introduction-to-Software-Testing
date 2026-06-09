#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int x;
	int y;
	struct node* next;
}node;
int hdi;
int tmp;
node head[1000];//头节点的数组
node* judge(int x, int y);
int cnt(int i);
int main()
{
	int n;
	int tx1, ty1, tx2, ty2;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d%d%d%d", &tx1, &ty1, &tx2, &ty2);
		node* a1 = judge(tx1, ty1);
		node* a2 = judge(tx2, ty2);
		if (a1==NULL){
			if (a2==NULL){
				head[hdi].x = tx1;
				head[hdi].y = ty1;
				node* r = (node*)malloc(sizeof(node));
				head[hdi].next = r;				
				r->x = tx2;
				r->y = ty2;
				r->next = NULL;
				hdi++;
			}
			else{
				node* r = (node*)malloc(sizeof(node));
				r->x = a2->x;
				r->y = a2->y;
				r->next = a2->next;
				a2->x=tx1;
				a2->y=ty1;
				a2->next=r;
			}
		}
		if (a1!=NULL){
			if (a2!=NULL){
				a1->next=a2;
				
			}else {
				node* r = (node*)malloc(sizeof(node));
				a1->next = r;
				r->next = NULL;
				r->x = tx2;
				r->y = ty2;
			}
		}
	}
	int maxn = cnt(0);
	int maxi = 0;
	for (int i=0; i<hdi; i++){
		if (cnt(i)>maxn) {
			maxn = cnt(i);
			maxi = i;
		}
	}	
	printf("%d %d %d", maxn, head[maxi].x, head[maxi].y);
}

node* judge(int x, int y)
{
	
	for (int i=0; i<hdi; i++){
		node *p = &head[i];
		while(p!=NULL){
			if (p->x==x&&p->y==y) {
				tmp = i;
				return p;
			}
			p = p->next;
		}
	}
	return NULL;
}

int cnt(int i)
{
	int ni = -1;
	for (node* a = &head[i]; a!=NULL; a = a->next){
		ni++;
	}
	return ni;
}

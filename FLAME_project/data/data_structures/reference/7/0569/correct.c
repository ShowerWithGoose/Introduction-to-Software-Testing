#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *llink;
	struct node *rlink;
}BT[10000];
int bi;

struct node *insert(int n, struct node *p){
	if(p==NULL||bi==0){
		p=&BT[bi++];
		p->num=n;
		return p;
	}
	if(p->num<=n)
		p->rlink=insert(n, p->rlink);
	else
		p->llink=insert(n, p->llink);
	return p;
}
void search(struct node *p, int h){
	if(p==NULL)
		return ;
	if(p->llink==NULL&&p->rlink==NULL)
		printf("%d %d\n",p->num, h);
	else{
		search(p->llink, h+1);
		search(p->rlink, h+1);
	}
	return ;
}

int main()
{
	int n,k;
	scanf("%d",&n);
	while(n-->0){
		scanf("%d", &k);
		insert(k, &BT[0]);
	}
	search(&BT[0],1);
	return 0;
}









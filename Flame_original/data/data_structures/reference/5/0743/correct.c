#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define MaxTo(a,b) (a)=(a)>(b)?(a):(b)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define ull unsigned long long
#define FO2(N,M) for(int i=0;i<N;i++)for(int j=0;j<M;j++)
#define swap(type,a,b) {type t=a;a=b;b=t;}
typedef struct _node{
	int a,n;
	struct _node *Next;
}node;
node *Ans;
node *NIL;
int NA,NB;
int a[0x114514][2],b[0x114514][2];
void GetIn(node *r){//将r插入新链表中，以插入排序的方式
	node *p_pre=Ans;
	node *p=Ans->Next;
	while(p!=NIL&&p->n>r->n) {p_pre=p;p=p->Next;}
	if(p->n==r->n) {p->a+=r->a;return;}
	p_pre->Next=r;
	r->Next=p;
}
int main()
{
	NIL=malloc(sizeof(node));NIL->Next=NIL;NIL->n=-2147483648;NIL->a=0;//定义空指针
	Ans=malloc(sizeof(node));Ans->Next=NIL;
	while(1){scanf("%d%d",&a[NA][0],&a[NA][1]);NA++;if(getchar()!=' ') break;}
	while(1){scanf("%d%d",&b[NB][0],&b[NB][1]);NB++;if(getchar()!=' ') break;}
	FOR(i,0,NA)
	FOR(j,0,NB){
		node *r=malloc(sizeof(node));
		r->Next=NIL;
		r->a=a[i][0]*b[j][0];
		r->n=a[i][1]+b[j][1];
		GetIn(r);
	}
	for(node *p=Ans->Next;p!=NIL;p=p->Next)
	if(p->a!=0) printf("%d %d ",p->a,p->n);
	return 0;
}



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
typedef struct node{
	int knode;
	int nnode;
	struct node* link;
} Node ,*Nodeptr;
int  a[500][2],b[500][2],t[2];
Nodeptr update(Nodeptr ,int t[]);
void print(Nodeptr);
int main(int argc, char *argv[]) {
	int i,j,k,la,lb;
	char ch;
	Nodeptr list=NULL;
	
	for(i=0;ch!='\n';i++)scanf("%d%d%c",&a[i][0],&a[i][1],&ch);
	la=i;
	ch=0;
	for(i=0;ch!='\n';i++)scanf("%d%d%c",&b[i][0],&b[i][1],&ch);
	lb=i;
	for(i=0;i<la;i++){
		for(j=0;j<lb;j++){
			t[0]=a[i][0]*b[j][0];
			t[1]=a[i][1]+b[j][1];
			list=update(list,t);
		}
	}
	
	print(list);
	
	
	
	
	
		return 0;
}
Nodeptr update(Nodeptr list,int t[]){
	Nodeptr p=NULL,q=NULL,r=NULL;
	r=(Nodeptr)malloc(sizeof(Node));
	r->knode=t[0];
	r->nnode=t[1];
	r->link=NULL;
	
	if(list==NULL)return r;
	for(p=q=list;q!=NULL&&t[1]<q->nnode;p=q,q=q->link);
	if(q!=NULL&&t[1]==q->nnode){
		q->knode=q->knode+t[0];
		free(r);
	}
	else {
		if(q==list){
			r->link=list;
			return r;
		}
		else{
		r->link=q;
		p->link=r;
		}
	}
	return list;
}

void print(Nodeptr list){
	Nodeptr q;
	for(q=list;q!=NULL;q=q->link)printf("%d %d ",q->knode,q->nnode);
}




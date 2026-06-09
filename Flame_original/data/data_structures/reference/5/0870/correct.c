#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int co;
	int exp;
	struct node* link;
}nod,*star;
star init(){
	star temp=(star)malloc(sizeof(nod));
	temp->link=NULL;
	return temp;
}
void insert(star head,int x,int y){
	star temp=(star)malloc(sizeof(nod));
	temp->co=x;
	temp->exp=y;
	star p;p=head;
	while(p->link!=NULL)p=p->link;
	p->link=temp;
	temp->link=NULL;
}
void fre(star head){
	star p=head,temp;
	while(p!=NULL)
	{
		temp=p->link;
		free(p);
		p=temp;
	}
}
star find(star h,int ep){
	star p=h->link;
	while(p!=NULL)
	{
		if((p->exp)==ep)return p;
		p=p->link;
	}
	return NULL;
}
void sert(star h,int x,int y){
	star pp=h->link;
	if(pp==NULL)insert(h,x,y);
	while(pp!=NULL)
	{
		star p1=pp->link;
		if(pp->exp>y&&p1==NULL)
		{
			star q=(star)malloc(sizeof(nod));
			q->co=x;q->exp=y;
			q->link=p1;
			pp->link=q;
			return;
		}
		if(pp->exp>y&&p1->exp<y)
		{
			star qq=(star)malloc(sizeof(nod));
			qq->co=x;qq->exp=y;
			qq->link=p1;
			pp->link=qq;
		}
		
		if(pp==(h->link)&&(pp->exp)<y)
		{
			star t=(star)malloc(sizeof(nod));
			t->co=x;t->exp=y;
			h->link=t;
			t->link=pp;
		}
		pp=pp->link;
	}
}
void mult(star h,star p,star q){
	int x1=p->co,x2=q->co;
	int y1=p->exp,y2=q->exp;
	int x=x1*x2,y=y1+y2;
	star yt=find(h,y);
	if(yt==NULL)
		sert(h,x,y);
	else (yt->co)+=x;
}
int main()
{
	int pak[100][5];
	int i=1,j=1,k;
	char c;
	while(c!='\n')
	{scanf("%d%d%c",&pak[i][1],&pak[i][2],&c);i++;}
	c='1';
	while(c!='\n')
	{scanf("%d%d%c",&pak[j][3],&pak[j][4],&c);j++;}
	star h1=init();
	star h2=init();
	for(k=1;k<i;k++)
		insert(h1,pak[k][1],pak[k][2]);
	for(k=1;k<j;k++)
		insert(h2,pak[k][3],pak[k][4]);
	star h=init();
	star p=h1->link,q=h2->link;
	while(p!=NULL)
	{
		while(q!=NULL)
		{
			mult(h,p,q);
			q=q->link;
		}
		p=p->link;
		q=h2->link;
	}
	star wi=h->link;
	while(wi!=NULL)
	{
		printf("%d %d ",wi->co,wi->exp);
		wi=wi->link;
	}
	fre(h1);fre(h2);fre(h);
	return 0;
}


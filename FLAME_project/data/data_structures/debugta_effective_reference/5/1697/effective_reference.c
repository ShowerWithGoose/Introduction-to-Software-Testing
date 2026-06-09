#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
struct xiang{
	int xishu;
	int zhishu;
}; 
typedef struct xiang xiang;
typedef struct xiang* xptr;
struct note{
	xiang x;
	struct note* link;
};
typedef struct note* noteptr;
typedef struct note note;
xiang a[1000],b[1000];
char line[1000];
int weishu(int n)
{
	int i=1;
	while(n>9){
		i++;
		n/=10;
	}
	return i;
}
int read(xptr s)
{
	char *p=line;
	int i=0;
	gets(line);
	while(sscanf(p,"%d %d",&s[i].xishu,&s[i].zhishu),s[i].xishu+s[i].zhishu!=0){
		p+=(weishu(s[i].xishu)+weishu(s[i].zhishu)+2);
		i++;
	} 
	memset(line,0,sizeof(line));
	return i;
}
int main()
{
	noteptr p,q,r,list=NULL;
	int i,j,len1,len2,xs,zs;
	len1=read(a);
	len2=read(b);
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			xs=a[i].xishu*b[j].xishu;
			zs=a[i].zhishu+b[j].zhishu;
			p=(noteptr)malloc(sizeof(note));
			p->x.xishu=xs;
			p->x.zhishu=zs;
			p->link=NULL;
			if(list==NULL){
				list=p;
			}
			else{
				q=NULL;
				r=list;
				while(r!=NULL&&r->x.zhishu>p->x.zhishu){
					q=r;
					r=r->link;
				}
				if(r==NULL){
					q->link=p;
					p->link=NULL;
				}
				else if(r->x.zhishu==p->x.zhishu){
					r->x.xishu+=p->x.xishu;
					free(p);
				}
				else{
					q->link=p;
					p->link=r;
				}
			}
			xs=0;
			zs=0;
		}
	}
	for(r=list;r!=NULL;r=r->link){
		printf("%d %d ",r->x.xishu,r->x.zhishu);
	}
	return 0;
}


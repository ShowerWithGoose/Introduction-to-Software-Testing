#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int x1,y1;
	int x2,y2;
	struct node *link;
}LNode,*LinkList;

LinkList CREAT(int x1,int y1,int x2,int y2);
LinkList FIND(int x1,int y1,int x2,int y2,LinkList list,int x);
LinkList ADD(int x1,int y1,int x2,int y2,LinkList p);

LinkList line[101];
int isCreat=0;
int Length[101]={0};
int LineNum=0;

int main(){
	int n,i,j;
	int x1,y1,x2,y2;
	int maxi=1;
	LinkList p;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		isCreat=0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(j=1;j<=LineNum;j++){
			if((p=FIND(x1,y1,x2,y2,line[j],j))!=NULL)
				isCreat=1;
		}
		if(!isCreat)
			CREAT(x1,y1,x2,y2);
	}
	for(i=1;i<=LineNum;i++){
		p=line[i];
		Length[i]++;
		while(p->link!=NULL){
			p=p->link;
			Length[i]++;	
		}
		if(Length[i]>Length[maxi]){
			maxi=i;
		}
	}
	printf("%d %d %d",Length[maxi],line[maxi]->x1,line[maxi]->y1);
	return 0;
}

LinkList CREAT(int x1,int y1,int x2,int y2){
	LineNum++;
	LinkList p,r,list=NULL;
	list=(LinkList)malloc(sizeof(LinkList));
	list->link=NULL;
	line[LineNum]=list;
	list->x1=x1;
	list->y1=y1;
	list->x2=x2;
	list->y2=y2;
}

LinkList FIND(int x1,int y1,int x2,int y2,LinkList list,int x){
	LinkList p,r,flag=NULL;
	int i;
	if(x2==list->x1&&y2==list->y1){//连接在最前面
		if(isCreat){
			for(i=1;i<=LineNum;i++){
				r=line[i];
				while(r->link!=NULL)
					r=r->link;
				if(r->x1==x1&&r->y1==y1)
					break;
			}
			r->link=list;
		}else{
			p=(LinkList)malloc(sizeof(LinkList));
			p->link=list;
			line[x]=p;
			p->x1=x1;
			p->y1=y1;
			p->x2=x2;
			p->y2=y2;
		}	
		flag=p;
	}
	p=list;
	while(p->link!=NULL)
		p=p->link;
	if(x1==p->x2&&y1==p->y2){//连接在最后面
		if(isCreat){
			for(i=1;i<=LineNum;i++)
				if(line[i]->x1==x1&&line[i]->y1==y1)
					break;
			r=line[i];
			p->link=r;
		}else{
			r=(LinkList)malloc(sizeof(LinkList));
			r->link=NULL;
			r->x1=x1;
			r->y1=y1;
			r->x2=x2;
			r->y2=y2;
			p->link=r;
		}
		flag=r;
	}
	return flag;
}







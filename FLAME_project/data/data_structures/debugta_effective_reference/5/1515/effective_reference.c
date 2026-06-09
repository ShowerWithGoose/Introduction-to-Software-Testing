#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define MAX(x,y) (x>y)?x:y
#define MIN(x,y) (x<y)?x:y

typedef struct node{
	int num;
	int power;
	struct node * next;
}lNode,*linkList;

int main()
{
	int a[100][2]={{0},{0}},b[100][2]={{0},{0}};
	int len1=0,len2=0;
	char c;
	while(1){
		scanf("%d%d%c",&a[len1][0],&a[len1][1],&c);
		len1++;
		if(c=='\n')break;
	}
	while(1){
		scanf("%d%d%c",&b[len2][0],&b[len2][1],&c);
		len2++;
		if(c=='\n')break;
	}
	linkList p,ans,end;
	p=(linkList)malloc(sizeof(lNode));
	p->num=a[0][0]*b[0][0];
	p->power=a[0][1]+b[0][1];
	p->next=NULL;
	ans=p;
	end=p;
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			if(i==0&&j==0)continue;
			p=(linkList)malloc(sizeof(lNode));
			end->next=p;
			p->next=NULL;
			p->num=a[i][0]*b[j][0];
			p->power=a[i][1]+b[j][1];
			end=p;
		}
	}
	int tmp;
	for(int i=0;i<len1*len2+100;i++){
		p=ans;
		while(p->next!=NULL){
			if(p->power<(p->next)->power){
				tmp=p->num;
				p->num=p->next->num;
				p->next->num=tmp;
				tmp=p->power;
				p->power=p->next->power;
				p->next->power=tmp;
			}
			p=p->next;
		}
	}
	//p=start;//问题在这里哦
	//linkList tmpp;
	//while(p->next!=NULL&&p!=NULL){
	//	if(p->power==p->next->power){
	//		p->num=p->num+p->next->num;
	//		tmpp=p->next;
	//		p->next=p->next->next;
	//		free(tmpp);
	//	}
	//	p=p->next;
	//}//
	linkList res=ans;
	p=ans->next;
	while(p!=NULL){
		if(res->power==p->power){
			res->num+=p->num;
			res->next=p->next;
			free(p);
			p=res->next;
			continue;
		}
		res=p;
		p=p->next;
	}
	p=ans;
	while(p!=NULL){
		if(p->num==0)continue;
		printf("%d %d ",p->num,p->power);
		p=p->next;
	}
	p=ans;
	while(p!=NULL){
		res=p;
		p=p->next;
		free(res);
	}
	return 0;
}





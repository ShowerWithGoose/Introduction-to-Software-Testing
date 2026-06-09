#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define arynum(x) (sizeof(x)/sizeof(x[0]))
#define uint unsigned int
#define uchar unsigned char

struct func{
	int num;
	int ans;
	struct func *next;
}tst,*lista,*listb,*listc;

char s[50000],t[50000];

struct func *createList(int n){
	int i;
	struct func *p,*list;
	list=p=(struct func*)malloc(sizeof(*p));
	for(i=0;i<n-1;i++){
		p->next=(struct func*)malloc(sizeof(*p));
		p=p->next;
	}
	p->next=list;
	return list;
} 

int main(){
	int max=-1,maxans,rmax; 
	int i,j=0,k=0,na=0,nb=0,nc=0;
	struct func *p,*pa,*pb,*pc,*pmax,*prmax=NULL,*prmax1=NULL,*prmax2=NULL;
	
	gets(s);
	lista=p=(struct func*)malloc(sizeof(tst));
	for(i=0,j=0,k=0;s[i]!='\0';){
		while(s[i+j]!=' '&&s[i+j]!='\0')	j++;
		sscanf(&s[i],"%d",&p->ans );
		for(k=j+1;s[i+k]!=' '&&s[i+k]!='\0';k++);
		sscanf(&s[i+j],"%d",&p->num );
		i+=k+1;	j=0;	k=0;	na++;
		if(s[i]!='\0'){
			p->next =(struct func*)malloc(sizeof(tst));
			p=p->next ;
		}
		else p->next =lista;
	}
	gets(t);
	listb=p=(struct func*)malloc(sizeof(tst));
	for(i=0,j=0,k=0;t[i]!='\0'&&t[i+1]!='\0';){
		while(t[i+j]!=' '&&t[i+j]!='\0')	j++;
		sscanf(&t[i],"%d",&p->ans );
		for(k=j+1;t[i+k]!=' '&&t[i+k]!='\0';k++);
		sscanf(&t[i+j],"%d",&p->num );
		i+=k+1;	j=0;	k=0;	nb++;
		if(t[i]!='\0'&&t[i+1]!='\0'){
			p->next =(struct func*)malloc(sizeof(tst));
			p=p->next ;
		}
		else p->next =listb;
	}
	nc=na*nb;
	listc=createList(nc);
	
	pa=lista; pb=listb; pc=listc;
	for(i=1;i<=na;i++){
		for(j=1;j<=nb;j++){
			pc->ans =pa->ans * pb->ans ;
			pc->num = pa->num + pb->num ;
			pc=pc->next;
			pb=pb->next;	
		}
		pa=pa->next ;
	}
	
	pc=listc;
	for(i=0;i<nc;i++){
		ld:if(pc->num >max){
			prmax=NULL;
			prmax1=NULL;
			prmax2=NULL;
			pmax=pc;
			max=pc->num ;
			maxans=pc->ans ;
			for(j=0;j<nc+1;j++){
				if(pc->num <max){
					pc=pc->next ;
				}
				else if(pc->num >max){
					goto ld;
				}
				else if(pc->num ==max&&pc!=pmax){
					maxans+=pc->ans;
					rmax=max;
					if(prmax==NULL)	prmax=pc;
					else if(prmax1==NULL)	prmax1=pc;
					else prmax2=pc;
					pc=pc->next ;		
				}
				else pc=pc->next ;
			}
			printf("%d %d ",maxans,max);
			pmax->num =-2;
			if(prmax!=NULL&&rmax==max){
				prmax->num=-2;
				prmax=NULL;
				i++;
			}
				if(prmax1!=NULL&&rmax==max){
				prmax1->num=-2;
				prmax1=NULL;
				i++;	
			}
				if(prmax2!=NULL&&rmax==max){
				prmax2->num=-2;
				prmax2=NULL;
				i++;
			}
			max=-1;	 
		}
		else{
			pc=pc->next;
			goto ld;	
		} 	
	}
	
	return 0;
} 












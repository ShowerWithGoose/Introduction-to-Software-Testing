#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct item{
	int coef;
	int index;
	struct item * link;//
}elem[200]; 



int compare(const void *a,const void *b)
{
	struct item* p=(struct item*)a;
	struct item* q=(struct item*)b;
	int answer=0;
	answer=p->index-q->index;
	return -answer;//
	
	
}

int digit(int x)//Î»Êý 
{
	int i,j;
	int answer=1;
	while(1){
		if(x/10!=0)
			answer++;
		else break;
		
		x/=10;
	
	}
	return answer;
}


int main()
{	int a,b;
	struct item *list1=NULL,*r,*p,*list2=NULL;
	int s_len;
	char t;
	
	while(scanf("%d %d%c",&a,&b,&t)!=EOF){
		p=malloc(sizeof(struct item));
		p->coef=a;
		p->index=b;
		p->link=NULL;
		if(list1==NULL)
			list1=p;
		else r->link=p;
		r=p;
		if(t=='\n') break;
		}
		
	while(scanf("%d %d%c",&a,&b,&t)!=EOF){
		p=malloc(sizeof(struct item));
		p->coef=a;
		p->index=b;
		p->link=NULL;
		if(list2==NULL)
			list2=p;
		else r->link=p;
		r=p;
		if(t=='\n') break;
		}
	
	int len1=1,len2=1;
		
	p=list1;
	while(p->link!=NULL){
		len1++;
		p=p->link;
	}
	p=list2;
	while(p->link!=NULL){
		len2++;
		p=p->link;
	}
	
	int i,j,k,n=len1*len2;
	struct item *p1=list1,*p2=list2;
	
	for(i=0;i<len1;i++){
		
		for(j=0;j<len2;j++){
			elem[j+len2*i].coef=(p1->coef)*(p2->coef);
			elem[j+len2*i].index=p1->index+p2->index;
			p2=p2->link;
		}
		p1=p1->link;
		p2=list2;
	}
	
	qsort(elem,n,sizeof(struct item),compare);
	
	for(i=0;i<n-1;i++){
		while(i<n-1){
			if(elem[i].index!=elem[i+1].index) break;
			else{
				elem[i].coef+=elem[i+1].coef;
				for(j=i+1;j<n-1;j++)
					elem[j]=elem[j+1];
				n--;
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(elem[i].coef!=0)
			printf("%d %d ",elem[i].coef,elem[i].index);
	}
	
	return 0;}
	
	
	
	
	
		
		
		
		
	
	


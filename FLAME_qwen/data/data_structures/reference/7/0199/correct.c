#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct _tree{
	int high;
	int data;
	struct _tree *lt;
	struct _tree *rt;
}Tree;
void surround (struct _tree *k){
if(k!=NULL){
	if(k->lt==NULL&&k->rt==NULL){
		printf("%d %d\n",k->data,k->high);
	}
	surround(k->lt);
	surround(k->rt);
}
return ;
}
int main(){
Tree *list=NULL,*r,*p;
//int topleft=-1,topright=-1;
int n;
int number;
scanf("%d",&n);
scanf("%d",&number);
p=(Tree*)malloc(sizeof(Tree));
p->high=1;
p->data=number;
list=p;
p->lt=NULL;
p->rt=NULL;
int i=1;
int m=1;
int flag=0;
while(i<n){
	scanf("%d",&number);
	flag=0;
	p=list;
		while(flag==0){
		if(number<p->data){
			if(p->lt==NULL){
				r=p;
				p=(Tree*)malloc(sizeof(Tree));
				p->high=r->high+1;
                p->data=number;
                p->lt=NULL;
                p->rt=NULL;
                r->lt=p;
                flag=1;
			}else{
				r=p;
				p=p->lt;
			}
		}else{
			if(p->rt==NULL){
				r=p;
				p=(Tree*)malloc(sizeof(Tree));
				p->high=r->high+1;
                p->data=number;
                p->lt=NULL;
                p->rt=NULL;
                r->rt=p;
                flag=1;
			}else{
				r=p;
				p=p->rt;
			}	
		}	
			
		}
	i++;	
}
surround(list);
	return 0;
}






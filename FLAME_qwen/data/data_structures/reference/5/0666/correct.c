#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int co;
	int pow;
	struct node* link;
}*list1,*list2,*r,*p,*x,*y;
int i,j,a,n;
char c;

int main(){
    do {
	    scanf("%d%d%c",&a,&n,&c);
		r=(struct node*)malloc(sizeof(struct node));
		r->co=a;
		r->pow=n;
		r->link=NULL;
		if(list1==NULL)
		list1=p=r;
		else{
			p->link=r;
			p=p->link;
		}
	}while(c!='\n');
		do{
		scanf("%d%d%c",&a,&n,&c);
		for(p=list1;p!=NULL;p=p->link){
			r=(struct node*)malloc(sizeof(struct node));
			r->co=a*p->co; 
			r->pow=n+p->pow;
		    r->link=NULL;
			if(list2==NULL)
			list2=x=r;
			else{
			    for(x=list2;x!=NULL;y=x,x=x->link){//y是x的前驱节点 
					if(r->pow>x->pow){
						if(x==list2){r->link=list2;list2=r;break;}
						else{r->link=x;y->link=r;break;} 
					}
					else if(r->pow==x->pow){x->co+=r->co;break;}
				}
               if(x==NULL) y->link=r;		
			}
				
		} 
	}while(c!='\n');
	
	for(x=list2;x!=NULL;x=x->link)
		printf("%d %d ",x->co,x->pow);
	
	
	return 0;
}


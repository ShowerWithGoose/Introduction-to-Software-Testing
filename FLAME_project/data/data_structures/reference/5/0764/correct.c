#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int ratio;
	int index;
	struct node *link;
}lnode, *linklist;
int main(){
	int a[100],b[100],c[100],d[100],i=0,j=0;  //ÊäÈë²¿·Ö 
	char ch=' ';
	while(ch!='\n'){
		scanf("%d%d%c",&a[i],&b[i],&ch);
		i++;
    }
 	ch=' ';
    while(ch!='\n'){
     	scanf("%d%d%c",&c[j],&d[j],&ch);
     	j++;
 	}
	
	linklist first,p,q,r;
	first=(linklist)malloc(sizeof(lnode));
	first->link=NULL; 
	
    for(int m=0;m<i;m++){
     	for(int n=0;n<j;n++){
      		p=first->link;
      		q=(linklist)malloc(sizeof(lnode));
      		q->ratio=a[m]*c[n];
     		q->index=b[m]+d[n];
      		q->link=NULL;
      		
      		if(first->link==NULL||first->link->index<q->index){
      			first->link=q;
       			q->link=p;
   			}else{
    			while(p!=NULL&&q->index<p->index){
    			r=p;
     			p=p->link;

    			}
   				if(p!=NULL&&p->index==q->index){
     				p->ratio+=q->ratio;
    			}else{
     				r->link=q;
     				q->link=p;

    			}
   			}
   		}
 	}
    p=first->link;
    while(p!=NULL){
     	printf("%d %d ",p->ratio,p->index);
     	p=p->link;
 	}
 return 0;
}


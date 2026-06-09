#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct multi{
	struct multi* link;
	int coe;
	int pow;
};
typedef struct multi mt;
typedef struct multi* mtptr;

int getlen(mtptr list){
	mtptr p;
	int n=0;
	for (p=list;p!=NULL;p=p->link) n++;
	return n;
}      

/*mtptr insert(mtptr list,mtptr r){
	int m=r->pow;
	mtptr p,q;
	for (p=list;p!=NULL&&m<p->pow;q=p,p=p->link){        //单链表需要q来标记p前面的结点 
			; 
	}
	if (m==p->pow) {
		p->coe+=r->coe;
		return list;
	}
	else {
		if (p==list) { 
			r->link=p;
			list=r;  
			return list;
		} 
		else {
			q->link=r;
			r->link=p;
			return list;
		}
	}
}*/

void clearnode(mtptr list){
	int i,n;
	n=getlen(list);
	mtptr p,q;
	q=list;
	for (i=0;i<n;i++){
		p=q->link;
		free(q);
		q=p;
	}	
}    
              
int main(){
	int ca[50],pa[50],cb[50],pb[50],i=1,j,lena,lenb,len,k=1,m;
	mtptr ptr[200],list,p,q,r;
	char c;
	do{
		scanf("%d%d%c",&ca[i],&pa[i],&c);
		i++;
	}while(c!='\n');
	lena=i-1;
	i=1;
	c='\0';
	do{
		scanf("%d%d%c",&cb[i],&pb[i],&c);
		i++;
	}
	while(c!='\n');
	lenb=i-1;
	for (i=1;i<=lena;i++){
		for (j=1;j<=lenb;j++){
			r=(mtptr)malloc(sizeof(mt));
			r->coe=ca[i]*cb[j];
			r->pow=pa[i]+pb[j];
			r->link=NULL;
			ptr[k++]=r;
		}
	}
	len=k-1;
	list=ptr[1];
	for (i=2;i<=len;i++){
		r=ptr[i];
		m=r->pow;
		for (p=list;p!=NULL&&m<p->pow;q=p,p=p->link){        
			; 
	}
		if (p!=NULL&&m==p->pow) {
		p->coe+=r->coe;
	}
		else {
		if (p==list) { 
			r->link=p;
			list=r;  
		} 
		else {
			q->link=r;
			r->link=p;
		}
	}
}
	for (p=list;p!=NULL;p=p->link){
		printf("%d %d ",p->coe,p->pow);
	}
	printf("\b");
	clearnode(list);
	return 0;
}


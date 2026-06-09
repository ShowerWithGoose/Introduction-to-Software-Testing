#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int coef;
	int exp;
	struct node *link;
}Lnode,*LinkList;
void bubblesort(Lnode[]);
int main(){
	int a1,x1;//第一个多项式的系数和指数
	int a2,x2;//第二个多项式的系数和指数 
	int i=0,cnt=0,j;
	char c;
	LinkList head1=NULL,q,tail1;//第一个多项式的链表
	LinkList head2=NULL,p,tail2;//第二个多项式的链表 
	LinkList head3=NULL,r,tail3;//多项式乘法得到的多项式链表 
	Lnode store[10000],a;
	while(scanf("%d%d%c",&a1,&x1,&c)!=EOF){
		q=(LinkList)malloc(sizeof(Lnode));
		q->coef  =a1;
		q->exp   =x1;
		q->link  =NULL;
		if(head1==NULL){
			head1=tail1=q;
		}
		else{
			tail1->link =q;
			tail1=q ;
		}
		if(c=='\n') break;
		if(q->exp ==0) break;
		
	}
	
	while(scanf("%d%d%c",&a2,&x2,&c)!=EOF){
		p=(LinkList)malloc(sizeof(Lnode));
		p->coef  =a2;
		p->exp   =x2;
		p->link  =NULL;
		if(head2==NULL){
			head2=tail2=p;
		}
		else{
			tail2->link =p;
			tail2=p ;
		}
		if(c=='\n') break;
		if(p->exp ==0) break;
	}
	
	q=head1;
	p=head2;
	
	while(q !=NULL){
		while(p !=NULL){
			r=(LinkList)malloc(sizeof(Lnode));
		    r->coef  =p->coef *q->coef ;
		    r->exp   =p->exp +q->exp ;
		    r->link  =NULL;
	     	if(head3==NULL){
			    head3=tail3=r;
		    }
		    else{
			    tail3->link =r;
			    tail3=tail3->link ; 
		    }
		    p=p->link ;
		}
		p=head2;
		q=q->link ;
	}//计算全部系数和指数 
	
	r=head3;
	while(r!=NULL){
		store[cnt].coef =r->coef ;
		store[cnt].exp =r->exp ;
		cnt++;
		r=r->link ;
	}
	cnt--;
	for(i=0;i<cnt;i++){
		    for(j=0;j<cnt-i;j++){
			    if(store[j].exp <store[j+1].exp ){
			       a=store[j];
			       store[j]=store[j+1];
			       store[j+1]=a;
			    }
		    }//冒泡排序 
        }
    
    for(i=0;i<cnt;i++){
    	for(j=i+1;j<=cnt;j++){
    		if(store[i].exp ==store[j].exp ){
    			store[i].coef =store[i].coef +store[j].coef ;
    			store[j].coef =0;
			}
		}
	}

	for(i=0;i<=cnt;i++){
		if(store[i].coef !=0)
		printf("%d %d ",store[i].coef ,store[i].exp );
	}
return 0;
}




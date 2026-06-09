#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	int p;
	int q;
}Da;
struct number{
	Da data;
	struct number *link;
};
typedef struct number *Node;
typedef struct number No;
Node createList(int n,int a[],int b[]){
	Node p,q,list=NULL;
	int i;
	for(i=0;i<n;i++){
		q=(Node)malloc(sizeof(No));
		q->data.p=a[i];
		q->data.q=b[i];
		q->link=NULL;
		if(list==NULL)
			list=p=q;
		else{
			p->link=q;
			p=q;
		}
	}
	return list;
}
Node createList1(int n,int a[],int b[]){
	Node p,q,list=NULL;
	int i;
	for(i=0;i<n;i++){
		q=(Node)malloc(sizeof(No));
		q->data.p=a[i];
		q->data.q=b[i];
		q->link=NULL;
		if(list==NULL)
			list=p=q;
		else{
			p->link=q;
			p=q;
		}
	}
	return list;
}
void sortbyx(Da array[],int n);
void dele(Da array[],int n);
int main(){
	int a[50]={0},b[50]={0},i=0,j=0,k=0,len,count,nu=1,sw=0,c=0,a0[50]={0},b0[50]={0};
	char x[1000]={0};
	gets(x);
	len=strlen(x);
	sw=0;
	for(i=0,k=0;i<len;i++){
		if(x[i]==' '&&sw==0){
			nu=1;
			for(j=i-1;x[j]!=' '&&j>=0;j--){
				a[k]+=(x[j]-'0')*nu;
				nu*=10;
			}
			sw=1;
			c++;
		}
		else if(x[i]==' '&&sw==1){
			nu=1;
			for(j=i-1;x[j]!=' '&&j>=0;j--){
				b[k]+=(x[j]-'0')*nu;
				nu*=10;
			}
			sw=0;
			k++;
		}
		else if(i==len-1&&sw==0){
			nu=1;
			for(j=i;x[j]!=' '&&j>=0;j--){
				a[k]+=(x[j]-'0')*nu;
				nu*=10;
			}
			sw=1;
			c++;
		}
		else if(i==len-1&&sw==1){
			nu=1;
			for(j=i;x[j]!=' '&&j>=0;j--){
				b[k]+=(x[j]-'0')*nu;
				nu*=10;
			}
			sw=0;
			k++;
		}
	}
	Node m,n,on0,on1;
	m=createList(c,a,b);
	c=0;
	for(i=0;i<len;i++){
		x[i]='0';
		a[i]=0;
		b[i]=0;
	}
	gets(x);
	len=strlen(x);
	sw=0;
	for(i=0,k=0;i<len;i++){
		if(x[i]==' '&&sw==0){
			nu=1;
			for(j=i-1;x[j]!=' '&&j>=0;j--){
				a[k]+=(x[j]-'0')*nu;
				nu*=10;
			}
			sw=1;
			c++;
		}
		else if(x[i]==' '&&sw==1){
			nu=1;
			for(j=i-1;x[j]!=' '&&j>=0;j--){
				b[k]+=(x[j]-'0')*nu;
				nu*=10;
			}
			sw=0;
			k++;
		}
		else if(i==len-1&&sw==0){
			nu=1;
			for(j=i;x[j]!=' '&&j>=0;j--){
				a[k]+=(x[j]-'0')*nu;
				nu*=10;
			}
			sw=1;
			c++;
		}
		else if(i==len-1&&sw==1){
			nu=1;
			for(j=i;x[j]!=' '&&j>=0;j--){
				b[k]+=(x[j]-'0')*nu;
				nu*=10;
			}
			sw=0;
			k++;
		}
	}
	n=createList1(c,a,b);
	i=0;
	for(on1=n;on1!=NULL;on1=on1->link){
		for(on0=m;on0!=NULL;on0=on0->link){
			a0[i]=on0->data.p*on1->data.p;
			b0[i]=on0->data.q+on1->data.q;
			i++;
	}
	}
	len=i;
	c=1;
	Da ff[50]={0};
	for(j=0;j<i;j++){
		ff[j].p=a0[j];
		ff[j].q=b0[j];
	}
	sortbyx(ff,i);
	dele(ff,i);
	for(i=0;i<len;i++){
		if(ff[i].p!=0)
		printf("%d %d ",ff[i].p,ff[i].q);
	}
	return 0;
	
}
void sortbyx(Da array[],int n){
	int i,j;
	Da tmp;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(array[i].q<array[j].q){
				tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}
		}
	}
}
void dele(Da array[],int n){
	int i,j,k=0,count,len=n;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(array[j].q==array[i].q){
			array[i].p+=array[j].p;
			array[j].p=0;
		}
		else break;
		}
	}
}




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct node{
	int coef;
	int exp;
}LNode;
LNode a[1000],b[1000],c[1000];
int cmp(const void*p1,const void*p2);
int main(){
	int i,j,k=0;
	int m=0,n=0;
	char ch;
	//输入 
	do{
		scanf("%d%d%c",&a[m].coef,&a[m].exp,&ch);
		m++;
	}while(ch!='\n');
	do{
		scanf("%d%d%c",&b[n].coef,&b[n].exp,&ch);
		n++;
	}while(ch!='\n');	
	//相乘 
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			c[k].coef = a[i].coef * b[j].coef;
			c[k].exp = a[i].exp + b[j].exp;
			k++;
		}
	}
	for(i=0;i<k;i++){
		for(j=1;i+j<k;j++){
			if(c[i].exp == c[i+j].exp &&c[i].exp!=0){
				c[i].coef+=c[i+j].coef;
				c[i+j].coef = 0;
			}
		}
	}
	qsort(c,k,sizeof(LNode),cmp);
	for(i=0;i<k;i++){
		if(c[i].coef==0)//去重项不输出
		    continue;
		else
			printf("%d %d ",c[i].coef,c[i].exp);
	}
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	struct node *a=(struct node*)p1;
	struct node *b=(struct node*)p2;
	return b->exp-a->exp;
}



#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 10000
typedef struct ex{
	int co;//xi
	int po;//mi
}a[M],b[M],c[M],d[M];
int com(const void *a,const void *b){
	struct ex *c=(struct ex *)a;
	struct ex *d=(struct ex *)b;
	return d->po - c->po ;
}
int main(){
	struct ex a[M],b[M],c[M],d[M];
	int i=0,j=0;
	char ch='2'; 
	while(ch!='\n') 
	{
		scanf("%d%d%c",&a[i].co,&a[i].po,&ch);
		i++;
	  }  
	  ch='2';
	while(ch!='\n')
	{
		scanf(" %d%d%c",&b[j].co,&b[j].po,&ch);
		j++;
	   }   
	int la=i,lb=j;
	int k=0;
	for(i=0;i<la;i++){
		for(j=0;j<lb;j++){
		 c[k].co=a[i].co *b[j].co ;
		 c[k].po=a[i].po +b[j].po ;
		 d[k].co=d[k].po=0;
		 k++;
		}
	}
	int lc=k;
	j=0;k=0;
	qsort(c,lc,sizeof(c[0]),com);
	for(i=0;i<lc;i++){
		for(j=i;c[i].po==c[j].po;j++){
			d[k].po=c[i].po;
			d[k].co+=c[j].co; 
		}
		i+=j-i-1;
		k++;
	}
	int ld=k;
	for(i=0;i<ld;i++){
		printf("%d %d ",d[i].co,d[i].po);
	}
	
	return 0;
}


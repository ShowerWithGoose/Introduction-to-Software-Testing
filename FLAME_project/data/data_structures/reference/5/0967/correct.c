#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct xy{
	int  xs,zs;
} x;
int cmp(const void *a,const void *b){
	x *p,*q;
	p=(x*)a;q=(x *)b;
	return p->zs<q->zs;
}
int main()
{
	char buf[200000]="";
	x n1[10000]={},n2[10000]={},sum[10000];
	int i=0,l1=0,j,l2=0,q=0,hash[10000]={};
	gets(buf);q=0;
	while(i<strlen(buf)){
		while(buf[i]!=' '&&i<strlen(buf)){
			n1[q].xs=10*n1[q].xs+buf[i]-'0';
			i++;
		}
		i++;
		while(buf[i]!=' '&&i<strlen(buf)){
			n1[q].zs=10*n1[q].zs+buf[i]-'0';
			i++;
		}
		q++;
		i++;
	}
	l1=q;
	q=0;
	memset(buf,'\0',sizeof(buf));
	gets(buf);q=0;i=0;
	while(i<strlen(buf)){
		while(buf[i]!=' '&&i<strlen(buf)){
			n2[q].xs=10*n2[q].xs+buf[i]-'0';
			i++;
		}
		i++;
		while(buf[i]!=' '&&i<strlen(buf)){
			n2[q].zs=10*n2[q].zs+buf[i]-'0';
			i++;
		}
		q++;
		i++;
	}
	l2=q;
	i=j=0;
	q=0;
	for(i=0;i<l1;i++){
		for(j=0;j<l2;j++){
			sum[q].xs=n1[i].xs*n2[j].xs;
			sum[q].zs=n1[i].zs+n2[j].zs;
			q++;
		}
	}
	qsort(sum,q,sizeof(sum[0]),cmp);
	for(i=0;i<q;i++){
		for(j=i+1;j<q;j++){
			if(hash[j]==0){
				if(sum[i].zs==sum[j].zs){
					sum[i].xs+=sum[j].xs;
					hash[j]++;
				}
			}
		}
	}
	for(i=0;i<q;i++){
			if(hash[i]==0){
			printf("%d %d ",sum[i].xs,sum[i].zs);
		}
	}
	return 0;
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int coe;
	int pow;
} xiang;
int main(){
	int a,n,i=0,j=0,k=0,l=0,m,s,t,cnt;
	xiang x0,x1[1000],x2[1000],x3[1000];
	char c;
	xiang *head=NULL,*p,*q,*r;
	do{
		scanf("%d%d%c",&a,&n,&c);
		x1[i].coe=a;x1[i].pow=n;
		i++;	
	}
	while(c!='\n');
	do{
		scanf("%d%d%c",&a,&n,&c);		
		x2[j].coe=a;x2[j].pow=n;
		j++;
	}
	while(c!='\n');
	for(s=0;s<i;s++){
		for(t=0;t<j;t++){
			x3[k].coe=x1[s].coe*x2[t].coe;
			x3[k].pow=x1[s].pow+x2[t].pow;
			k++;
		}
	}
	do{
		i=0;
		l=0;
		while(l<k){
			m=x3[l].pow-x3[l+1].pow;
			if(m<0){
				x0=x3[l];
				x3[l]=x3[l+1];
				x3[l+1]=x0;
				l++;
			}
			if(m==0){
				x3[l].coe+=x3[l+1].coe;
				for(j=l+1;j<k;j++) x3[j]=x3[j+1];
				k--;
			}
			if(m>0){
				l++;
				i++;
			}
		}
	}
	while(i!=k);
	if(x3[k].coe==0) k--;
	for(l=0;l<=k;l++) printf("%d %d ",x3[l].coe,x3[l].pow);
	return 0;
}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ll long long
typedef struct num{
	int a;
	long long n; 
}z;
int cmp(const void *a, const void *b) {
	z *p = (z *)a, *q = (z *)b;
	if(p->n <q->n) {
		return 1;
	} else
		return -1;
}
z in1[50],in2[50],ans[5000];
int check(int x,int y){
	int i=0,j=0;
	while(x/10>0){
		x/=10;
		i++;
	}
	while(y/10>0){
		y/=10;
		j++;
	}
	return i+j+4;
}
int main()
{
	int i=0,j=1;
	char s1[500];
	char s2[500];
	gets(s1);
	gets(s2);
	char *p1,*p2;
	p1=s1;
	p2=s2;
	 
	while(~sscanf(p1,"%d%d",&in1[i].a,&in1[i].n)&&in1[i].a!=0){
		p1+=check(in1[i].a,in1[i].n);
		i++;	
	}
	
	while(~sscanf(p2,"%d%d",&in2[j].a,&in2[j].n)&&in2[j].a!=0){
		p2+=check(in2[j].a,in2[j].n);
		j++;
	}
	
	int h=0; 
	for(int k=0;k<i;k++){
		for(int t=0;t<j;t++){
			ans[h].a=in1[k].a*in2[t].a;
			ans[h].n=in1[k].n+in2[t].n;
			h++;
		}
	}
	qsort(ans,i*j,sizeof(z),cmp);
	for(int k=0;k<i*j;k++){
		if(ans[k].n==ans[k+1].n){
			ans[k+1].a+=ans[k].a;
			ans[k].a=0;
		}
	}
	for(int k=0;k<i*j+1;k++){
		if(ans[k].a!=0){
			printf("%d %lld ",ans[k].a,ans[k].n);
		}
	}
	return 0;
} 



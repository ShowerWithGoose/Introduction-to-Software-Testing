#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
#define max 1000
struct Node{
	int coe;
	int pow;
}p[max],q[max],result[max];
int cmp(const void *a ,const void *b) 
{ 
return (*(struct Node *)a).pow > (*(struct Node *)b).pow?-1:1; 
} 

int main(){
	int i,j,k=0,m,x=0,y=0;
	int link[max]={};
	for(i=0;;i++){
	scanf("%d%d",&p[i].coe,&p[i].pow);
	x++;
	if(getchar()=='\n')
	break;
	}
	for(i=0;;i++){
	scanf("%d%d",&q[i].coe,&q[i].pow);
	y++;
	if(getchar()=='\n')
	break;
	}
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			result[k].coe=p[i].coe*q[j].coe;
			result[k].pow=p[i].pow+q[j].pow;
			k++;
		}
	}
	m=k;
	for(i=0;i<k;i++){
		for(j=i+1;j<k;j++){
			if(result[j].pow==result[i].pow){
				result[i].coe+=result[j].coe;
				result[j].coe=0;
				result[j].pow=0;
				m--;
			}
		}
	}
	qsort(result,k,sizeof(struct Node),cmp);
	for(i=0;result[i].coe!=0;i++){
		printf("%d %d ",result[i].coe,result[i].pow);
	}
}



#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int all[9999999][12],normal[12];
int cnt=0;int n;

void swop(int *i,int *j){
	int tem=*i;*i=*j;*j=tem;
}

void f(int i,int n)//表示当前考虑到第i个数和后面的交换 
{
	int j;
	if(i==n-1){
		for(j=0;j<n;j++){
			all[cnt][j]=normal[j];
		}
		cnt++;
	}
	for(j=i;j<n;j++){
		swop(&normal[j],&normal[i]);
		f(i+1,n);
		swop(&normal[j],&normal[i]);
	}
}

int cmp(const void *p1,const void *p2){
	int i=0;
	while(i<n-1)
	{
		if(((int*)p1)[i]!=((int*)p2)[i]){
			if(((int*)p1)[i]>((int*)p2)[i])return 1;
			else return -1;
		}
		else i++;	
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)normal[i]=i+1;
	f(0,n);
//	for(int i=0;i<cnt;i++){
//		for(int j=0;j<n;j++)printf("%d ",all[i][j]);
//		printf("\n"); 
//	}
//	return 0;
	qsort(all,cnt,sizeof(int)*12,cmp);
	for(int i=0;i<cnt;i++){
		for(int j=0;j<n;j++)printf("%d ",all[i][j]);
		printf("\n"); 
	}
	return 0;
}





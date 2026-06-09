#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b)
{
	return *(int*)b - *(int*)a;
}

int main(){
	int num1[105]={0},index1[105]={0},num2[105]={0},index2[105]={0};
	int i1,i2;
	char s1,s2; 
	for(i1=0;s1!='\n';i1++){
		scanf("%d%d",&num1[i1],&index1[i1]);
		s1=getchar();
	}
	for(i2=0;s2!='\n';i2++){
		scanf("%d%d",&num2[i2],&index2[i2]);
		s2=getchar();
	}//循环时输入回车停止输入  
	
	int fin[10086][2]/*第一位为指数;第二位为底数*/,i,j,k=0;
	memset(fin,0,sizeof(fin));
	for(i=0;i<i1;i++){
		for(j=0;j<i2;j++,k++){
			fin[k][1]=num1[i]*num2[j];
			fin[k][0]=index1[i]+index2[j];
		}
	}
	qsort(fin,k,8,cmpfunc);//按指数从大到小排列 
	
	for(i=0;i<=k;i++){
	 	if(fin[i][0]==fin[i+1][0]){
	 		fin[i+1][1]=fin[i][1]+fin[i+1][1];
	 		fin[i][1]=0;
		}
	}//相同项数相加 
	
	for(i=0;i<=k+1;i++){
		if(fin[i][1]!=0){
			printf("%d %d ",fin[i][1],fin[i][0]);
		}
	}
	return 0;
} 


#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h> 
int main(){
	int i=1,j=1,len,a[105],b[105]={0},flag=0;//1后面不为1，-1，0 
	scanf("%d",&a[1]);
	while(a[i]!=-1){//从i=1开始 
		if(a[i]==1){//进栈
			scanf("%d",&b[j]);
			j++;
		}
		else if(a[i]==0){//出栈
		 	if(j==1)//空栈 
		 		printf("error ");//错误 
			else{
				printf("%d ",b[j-1]);	
				b[j-1]=0;// 
		 		j--;				
			}	 
		}	
		i++;
		len=i-1;
		scanf("%d",&a[i]);
	}	
	return 0;
} 


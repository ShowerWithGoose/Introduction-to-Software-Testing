#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100]={0},b[100]={0},i=0,j=0,n,m,n1,flag=0;
 for(i=0;;i++){
   	scanf("%d",&n);
   if(n!=-1){	
	a[i]=n;
   	n1=i;}
   	else{break;
	   }
}
   for(i=0;i<=n1;i++){
   	if(a[i]==1){
   		b[j]=a[i+1];
   		j++;
   		flag++;
	   }
	if(a[i]==0){
		flag--;
		if(flag<0){
			printf("error ");
			j=0;flag=0;
		}
		else{
			printf("%d ",b[flag]);
			j=flag;
		}
	}
   }
	return 0;
}


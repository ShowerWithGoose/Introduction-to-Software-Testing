#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int x;
int mix(int p,int a[],int n){ 
    int i=0;
    for(i=0;i<n;i++){
    	if(a[i]>p) x=i;
    	else{
	        x=i-1;break;
		}
	}
	return x;
}
int cmp(const void *a,const void *b){
	int *c=(int *)a;
	int *d=(int *)b;
	return *d-*c;
}
int main(){
	int n,i=0,p=0,tmp,t=0,flag=1,j=0;
	int a[11]={0},b[11]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[n-1-i]=i+1;
	}
	if(n==1) printf("1\n");
	else{
	for(i=0;i<n-1;i++){
		for(j=0;j<n&&flag==1;j++)
		printf("%d ",a[n-1-j]);
		p=a[i]-a[i+1];
		if(p>0){
			 qsort(a,i+1,sizeof(a[0]),cmp);
			 t=mix(a[i+1],a,i+1);
			 tmp=a[i+1];a[i+1]=a[t];a[t]=tmp; 
			 i=-1;flag=1;
			 printf("\n");
		}
		else flag=0;
	}
	}
	return 0;
} 


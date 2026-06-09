#include<stdio.h>
int a[1001],t,m=0,l;
int main(){
	while(scanf("%d",&t)!=EOF)
	{
		if(t==1){
			if(m>=99){
				printf("error ");
			}
			else{
				scanf("%d",&l);
				a[m]=l;
				m++;
			}
		}
		if(t==0){
			if(m<=0){
				printf("error ");
			}
			else{
				printf("%d ",a[m-1]);
				m--;
			}
		}
		if(t==-1)
		break;
	}
} 


#include<stdio.h> 
int main()
{
	int a=2,b[100],n=0;
	while(a!=-1){
		scanf("%d",&a);
		if(a==1){
			if(n>99){
				printf("error ");
			}
			else{
			  scanf("%d",&b[n]);
			  n++;
			}
		}
		else if(a==0){
			if(n<1){
				printf("error ");
			}
			else{
			  printf("%d ",b[n-1]);
			  b[n-1]=0;
			  n--;
			}	
		}
	}
	return 0;
}


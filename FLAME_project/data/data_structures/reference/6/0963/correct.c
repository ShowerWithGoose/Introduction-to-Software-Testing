#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int a[100]; 
int main(){
	int n,i=0;
	while(1){
		scanf("%d",&n);
		if(n==-1)
		break;
		else if(n==1)
		{
		scanf("%d",&a[i]);
		i++;
		}
		else{
			if(i-1<0) 
			printf("error ");
			else
			{
				printf("%d ",a[i-1]);
				i--;
			}
		}
	}
	return 0;
}



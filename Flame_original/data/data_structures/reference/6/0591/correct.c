#include<stdio.h>
int stack[100],i,sign,number;
int main()
{
	i=-1;
	while(1){
		scanf("%d",&sign);
		if(sign==-1) break;
		else if(sign==1){
			scanf("%d",&number);
			if(i>=100) printf("error ");
			else{
				i++;stack[i]=number;	
			}
		}
		else if(sign==0){
			if(i<0) printf("error ");
			else{
				printf("%d ",stack[i]);
				i--;
			}
		}
	}
	return 0;
}




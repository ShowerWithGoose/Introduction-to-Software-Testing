#include <stdio.h>
int main()
{
	int num[500]={},beg=0,end=0,n;
	while(scanf("%d",&n)!=EOF){
		if(n==0){
			if(end==beg){
				printf("error ");
			}else{
				printf("%d ",num[end-1]);
				end--;
			}
		}else{
			if(n==1){
				scanf("%d ",&num[end]);
				end++;
			}else{
			if(n==-1){
				break;
			}
		}
		}
	}
	return 0;
} 


#include<stdio.h>
int main(){
	int s[100],i=0,n;
	while(1){
		scanf("%d",&n);
		if(n==-1)
			break;
		else if(n==0){
			if(i==0)
				printf("error ");
			else{
				printf("%d ",s[--i]);
			}
		}
		else if(n==1){
			if(i==99)
				printf("error ");
			else{
				scanf("%d",&n);
				s[i++]=n;
			}
		}
	}
	return 0;
}


#include<stdio.h>
int main()
{
	int a[101]={};
	int c,top=0,i=0;
	scanf("%d",&c);
	while(c!=-1){
		if(c==1){
			if(top==100){
				printf("error ");
				scanf("%d",&i);
				scanf("%d",&c);
				continue;
			}
			scanf("%d",&a[top]);
			top++;
		}
		else{
			if(top==0){
				printf("error ");
				scanf("%d",&c);
				continue;	
			} 
			printf("%d ",a[top-1]);
			top--;			
		}
		scanf("%d",&c);
	}
	return 0;
}




#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int main()
{
	int num[110]={0};
	int top=-1;
	int op,a;
	
	while(1){
		scanf("%d",&op);
		if(op==-1)
			break;
		if(op==0){
			if(top==-1)
				printf("error ");
			else{
				printf("%d ",num[top]);
				num[top]=0;
				top--;
			}
			continue;
		}
		scanf("%d",&a);
		if(op==1){
			if(top==99)
				printf("error");
			else
				num[++top]=a;
		}
	}

	return 0;
}



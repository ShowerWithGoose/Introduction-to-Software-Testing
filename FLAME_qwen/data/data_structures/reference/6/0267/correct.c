#include<stdio.h>
int main()
{
	int s[100];
	int top=-1;
	int a,b;
	while(scanf("%d",&a)!=EOF){
		if(a==1){
			scanf("%d",&b);
			if(top==100)
				printf("error ");
			else
				s[++top]=b;
		}
		if(a==0){
			if(top==-1)
				printf("error ");
			else
				printf("%d ",s[top--]);
		}
	}
	return 0;
}


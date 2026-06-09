#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int num[105];
char s[200];
int top;

int main()
{
	int op,t;
	scanf("%d",&op);
	while(op!=-1){
		if(op==1){
			if(top==100){
				printf("error ");
			}
			else{
				scanf("%d",&t);
				top++;
				num[top] = t;
			}
		}
		else if(op==0){
			if(top==0){
				printf("error ");
			}
			else{
				printf("%d ",num[top]);
				top--;
			}
		}
		scanf("%d",&op);
	}
	return 0;
}


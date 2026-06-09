#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct stack{
	int top;
	int data[1000];
};
struct stack f;
int main()
{
	f.top=0;
int n,num;
int i=0,j=0,k=0;
while(scanf("%d",&n)!=EOF){
	if(n==1){
		scanf("%d",&num);
		if(f.top==100){
			printf("error ");
		}
		else{
			f.data[f.top]=num;
			i++;
			f.top++;
		}
	}
	else if(n==0){
		if(f.top==0||f.top==-1){
			printf("error ");
		}
		else{
			printf("%d ",f.data[f.top-1]);
			f.top--;
		}
	}
	else if(n==-1){
		break;
	}
}

return 0;
}






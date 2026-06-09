#include<stdio.h>
typedef struct{
	int  a[100];
	int top;
}zhan;
zhan b;
int main()
{
	b.top =-1;
	int k,n;
	while(scanf("%d",&k)!=EOF){
	if(k==1){
		scanf("%d",&n);
		if(b.top==99)
		printf("error ");
		else
		{
			b.a [++b.top]=n;
		}
	}
	else if(k==0){
		if(b.top==-1)
		printf("error ");
		else{
			printf("%d ",b.a [b.top ]);
			b.top--;
		
		}
	}
	else if(k==-1)
	break;	
	}
	return 0;
}
 


#include <stdio.h>
int main(){
	int x,n,top=-1,a[100];
	while(~scanf("%d",&x)){
		switch(x){
			case 1:
				scanf("%d",&n);
				if(top==99)
				    printf("error ");
				else
				    a[++top]=n;
				break;
			case 0:
				if(top==-1)
				    printf("error ");
				else
				   printf("%d ",a[top--]);
				break;
			default:
				return 0;
		}
	}
} 


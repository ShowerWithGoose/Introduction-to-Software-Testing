#include <stdio.h>
int s[100];
int top=-1;
int main()
{
	int n,a;
	while(~(scanf("%d",&n))){
		if(n==1){
			scanf("%d",&a);
			if(top==99){
				printf("error ");
			}else{
				s[++top]=a;
			}
		}else{
			if(top==-1){
				printf("error ");
			}else{
				printf("%d ",s[top]);
				top--;
			}
		}
	}
	return 0;
}

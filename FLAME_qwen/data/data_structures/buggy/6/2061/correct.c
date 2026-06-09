#include <stdio.h>
#define max 100
int s[max];
int top=-1;
int main()
{
	int n,a;
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			scanf("%d",&a);
			if(top==99){
				printf("error ");
			}else{
				s[++top]=a;
			}
		}else if(n==0){
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

#include<stdio.h>
int main(){
	int sk[105];
	int top=-1; 
	int c;
	scanf("%d",&c);
	while(c!=-1){
		if(c==1&&top<100) {
			int a;
			scanf("%d",&a);
			sk[++top]=a;
		}
		if(c==0)
			if(top>=0) printf("%d ",sk[top--]);
			else printf("error ");
		scanf("%d",&c);
	}
	return 0;
}


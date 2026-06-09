#include <stdio.h>
int main(){
	int a[300]={0};
	int i=0;int n=0;int flag=0;
	while(scanf("%d",&n)!=EOF){
		if(n==-1)break;
		else if(n==1){
			flag=1;
		}
		else if(n==0){
			if(i>0){printf("%d ",a[i-1]);
			i--;
			}
			else {
				printf("error ");
			}
		}
		else{
			if(flag==1){
				flag=0;
				a[i]=n;
				i++;
			}
		}
	}
	return 0;
}


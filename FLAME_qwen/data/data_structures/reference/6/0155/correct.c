#include<stdio.h>
int main(){
	int n,m,a[100],top=-1;
	while(1){
	    scanf("%d",&n);
	    if(n==1){
	   	    scanf("%d",&m);
	   	    if(top==99){
	   	   	    printf("error ");
			}else{
				top++;
				a[top]=m;
			}continue;
	    }
		if(n==0){
			if(top==-1){
				printf("error ");
			}else{
				printf("%d ",a[top]);
				top--;
			}continue;
		}if(n==-1){
			break;
		} 
	}
	return 0;
} 


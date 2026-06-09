#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
	int a[100];
	int top=-1;
	int b,c;
	while(scanf("%d",&b)!=EOF){
		if(b==1){
			if(top==99){
				printf("error ");
			}
			else {
				top++;
				scanf("%d ",&a[top]);
			}
		}
		else if(b==0){
			if(top==-1){
				printf("error ");
			}
			else{
				printf("%d ",a[top]);
				top--;
			}
		}
		else{
			return 0;
		}
	}
	
	
	return 0;
}


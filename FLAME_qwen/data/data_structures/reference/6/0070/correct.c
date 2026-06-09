#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int top=-1;
int a[100];
int main(){
	int i=0,k;
	while(i==0){
	
		scanf("%d",&k);
		if(k==-1){
			break;
		}
		if(k==1){
			top++;
			if(top==100){
				printf("error ");
				continue;
			}
			scanf("%d",&a[top]);
			
		}
		if(k==0){
			if(top==-1){
				printf("error ");
				continue;
			}
			printf("%d ",a[top]);
			top--;
		}
	}

	
	
	return 0;
}




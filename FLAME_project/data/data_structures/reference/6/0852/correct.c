#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long

int main(){
	int top=-1;
	int a[105]={0};
	int n=1;
	while(1){
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		else if(n==1){
			top++;	
			scanf("%d",&a[top]);
		}
		else if(n==0){
			if(top==-1){
				printf("error ");
			} 
			else printf("%d ",a[top--]);
		}
	}
}



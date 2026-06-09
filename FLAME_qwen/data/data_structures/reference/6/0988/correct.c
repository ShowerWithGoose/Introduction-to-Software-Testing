//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define eps 1e-6
 
int main(){
	int a[105];
	int top=0,base=0,op,m;
	while(scanf("%d",&op)!=EOF){
		if(op==1){
			scanf("%d ",&m);
			if(top==99) printf("error ");
			else{
				a[top++]=m;
			}
		}else if(op==-1) return;
		else{// 0
			if(top==0) printf("error ");
			else{
				printf("%d ",a[--top]);
			}
		}	
		
	}
	
	
	return 0;
}




#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
int main()
{
int top=-1,stack[100],m=100,op,n;
while(scanf("%d",&op)!=EOF){
	if(op==1){
		if(top==m-1)
		printf("error ");
		else{
			scanf("%d",&n);
			stack[++top]=n;
		} 
	} 
	else if(op==0){
		if(top==-1)
		printf("error ");
		else 
		printf("%d ",stack[top--]);
	}
	else if(op==-1)
	break;
}
return 0;
}




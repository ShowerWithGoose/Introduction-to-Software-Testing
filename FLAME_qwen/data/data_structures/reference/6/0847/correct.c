#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int Top=-1;
int s[105];
int main()
{
	int op,member;
	while(~scanf("%d",&op)){
		if(op==1){
			scanf("%d",&member);
			if(Top>=99) printf("error ");
			else s[++Top]=member;
		}
		else if(op==0){
			if(Top<0) printf("error ");
			else printf("%d ",s[Top--]);
		}
		else if(op==-1) break;
	}
	return 0;
}


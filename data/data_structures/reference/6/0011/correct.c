#include "stdio.h"
void main(){
	int stack[20]={0,0};
	int top;
	top=-1;
	int caozuo;
	caozuo=1;
	int inStack;
	scanf("%d",&caozuo);
	while(caozuo!=-1){
		if(caozuo==1&&top!=19){
			scanf("%d",&inStack);
			stack[top+1]=inStack;
			top=top+1;
			scanf("%d",&caozuo);
		}
		else if(caozuo==1&&top==19){
			printf("%s","error ");
			scanf("%d",&caozuo);
		}
		else if(caozuo==0&&top==-1){
			printf("%s","error ");
			scanf("%d",&caozuo);
		}
		else if(caozuo==0&&top!=-1){
			printf("%d ",stack[top]);
			top=top-1;
			scanf("%d",&caozuo);
		}
	}
}


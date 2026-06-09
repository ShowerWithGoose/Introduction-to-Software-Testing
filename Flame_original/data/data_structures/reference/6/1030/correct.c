#include<stdio.h>
#define M 100
int stack[M];
int top;
int main()
{
	int caozuo;
	int ans[M];
	int k=0;
	top=-1;
	while(scanf("%d",&caozuo)!=-1){
		if(caozuo==1){
			if(top<M-1){
				top++;
				scanf("%d",&stack[top]);
			}
			else{
				ans[k]=0;
				k++;
			}
		}
		else if(caozuo==0){
			if(top>-1){
				ans[k]=stack[top];
				k++;
				top--;
			}
			else{
				ans[k]=0;
				k++;
			}
		}
	}
	for(int i=0;i<k;i++){
		if(ans[i]==0){
			printf("error ");
		}
		else{
			printf("%d ",ans[i]);
		}
	}
	return 0;
}


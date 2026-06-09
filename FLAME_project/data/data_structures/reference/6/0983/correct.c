#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct stack{
	int num[100];
	int top;
};
int main()
{
	int controlNum,useless;
	struct stack a;
	a.top=-1;
	while(scanf("%d",&controlNum)){
		if(controlNum==-1){
			break;
		}
		else if(controlNum==1){
			if(a.top>=99){
				scanf("%d",&useless);
				printf("error ");
			}
			else{
				a.top++;
				scanf("%d",&a.num[a.top]);
			}
		}
		else{
			if(a.top<0){
				printf("error ");
			}
			else{
				printf("%d ",a.num[a.top]);
				a.top--;
			}
		}
	}
	return 0;
}


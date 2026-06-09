#include <stdio.h>
struct zhan{
	int judge;
	int num;
}code[1000];
int top;

int temp;

int main(){
	while(scanf("%d",&code[top].judge)!=EOF){
		if(code[top].judge==-1){
			break;
		}
		else if(code[top].judge==1){			
			if(top==99){
				scanf("%d",&temp);
				printf("error ");
			}
				
			else{
				scanf("%d",&code[top].num);
				top++;
			}
					
		}
		else if(code[top].judge==0){
			if(top==0){
				printf("error ");
			}
			else{
				printf("%d ",code[top-1].num);
				top--;
			}
		}	
	}
	return 0;
}


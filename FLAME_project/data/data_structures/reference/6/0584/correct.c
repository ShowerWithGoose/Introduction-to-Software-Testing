#include<stdio.h>
#include<string.h>

int main(){
	int stack[100];
	int ope,x,top=-1;
	scanf("%d",&ope);
	while(ope!=-1){
		if(ope==1){
			if(ope==99){
				printf("error ");
			}
			else{
				scanf("%d",&x);	
				if(x!=-1&&x!=0&&x!=1){
			    	stack[++top]=x;					
				}	
			}
		}
		if(ope==0){
			if(top==-1){
				printf("error ");
			}
			else{
				printf("%d ",stack[top]);	
				top--;
			}
		}
		scanf("%d",&ope);
	}
	return 0;
}


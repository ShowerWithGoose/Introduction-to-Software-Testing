#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct stack{
	int data[1000];
};
struct stack s;
int i=0,f,n;
int main(){
	while(1){
		scanf("%d",&f);
		if(f==1){
			scanf("%d",&n);
			if(i>=100){
				printf("error ");
			}
			else{
				s.data [i]=n;
				i++;
			}
		}
		else if(f==0){
			if(i<1){
				printf("error ");
			}
			else{
				printf("%d ",s.data [i-1]);
				i--;
			}
		}
		else if(f==-1){
			break;
		}
	}
	return 0;
}


#include<stdio.h>
#include<stdlib.h>

struct stack{
	int num[101];
	int top;
}s;
int a,i,k;

int main(){
	s.top=-1;
	while(scanf("%d",&k)!=EOF){
		if(k==-1){
			break;
		}
		else if(k==1){
			scanf("%d",&i);
			if(s.top==99){
				printf("error ");
			}
			else{
				s.num[++s.top]=i;
			}
		}
		else if(k==0){
			if(s.top==-1){
				printf("error ");
			}
			else{
			    k=s.num[s.top--];
			    printf("%d ",k);
			}
		}
	}
	return 0;
}


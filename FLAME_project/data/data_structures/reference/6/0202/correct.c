#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct stack{
	int top;
	int data[2000];
};
struct stack s;
int main(){
	int n,m;
	s.top=0;
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			scanf("%d",&m);
			s.top++;
			s.data[s.top]=m;
		}
		if(n==0){
			if(s.top>0&&s.top<=100){
				printf("%d ",s.data[s.top]);
				s.top--;
			}
			else printf("error ");
		}
	}
	return 0;
}


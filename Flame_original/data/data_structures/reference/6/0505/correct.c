#include <stdio.h>
struct stack{
	int  num[10000];
	int top;
	
};
struct stack s;
int main()
{
	int i=0;
	int n,m;   //n->栈操作，m->输入的整数 
	while(~scanf("%d", &n)){
		if(n==1){
			if(s.top<=99){
			scanf("%d", &m);
			s.num[s.top]=m;
			s.top++;
			}
			else if(s.top>=100){
			printf("error "); 
			}
			
	    }
	    else if(n==0){
	    	if(s.top>0){
	    	printf("%d ", s.num[s.top-1]);
			s.top--;	
			}
			else if(s.top==0){
			printf("error "); 	
			}
		}
		else if(n==-1){
			break;
		}
	}
	
	return 0;
  }  


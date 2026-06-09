#include<stdio.h>
struct stack{
	int data[1005];
	int n;
};

int main(){
	struct stack s;
	int flag,e;
	
	s.n =0;	
	while(scanf("%d",&flag)!=EOF)
	{

		if(flag==1)
		{
			scanf("%d",&e);
			if(s.n >=100)
			{
				printf("error ");
			}
			else{
				s.data[s.n]=e;
				s.n ++;
			}
		}
		else if(flag==0)
		{
			if(s.n<1){
				printf("error ");
			}
			else{
				printf("%d ",s.data[s.n-1]);
				s.n --;
			}
		}
		else if(flag==-1)
		{
			return 0;
		}
	}
	return 0;
}


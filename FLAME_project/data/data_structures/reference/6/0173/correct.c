#include<stdio.h>
int main()
{
	int order, num;
	int s[100];
	int top=-1;
	while(scanf("%d",&order)!=EOF)
	{
		if(order==1) //ÈëÕ» 
		{
			if(top==99) printf("error ");//Õ»Âú 
			else
			{
				scanf("%d", &num);
				s[++top]=num;
			}
		}
		else if(order==0)
		{
			if(top==-1) printf("error ");//Õ»¿Õ
			else
			{
				printf("%d ", s[top--]);
			}
		}
		else if(order==-1) return 0;
	}
}


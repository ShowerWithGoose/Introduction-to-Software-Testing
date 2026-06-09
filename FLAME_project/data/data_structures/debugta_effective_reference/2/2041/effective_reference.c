#include <stdio.h>
#include <string.h>
int num[1000]; 
long long sum[1000];
char op[1000];
int i,j,len;
int ans;
void calculate(int num[], char op[]);
int Ans(long long sum[], char op[]);
int main()
{
	scanf("%d", &num[i]);
	scanf(" %c", &op[i]);
	
	while(op[i]!='=')
	{
		i++;
		scanf("%d", &num[i]);
		scanf(" %c", &op[i]);
	}
	len=strlen(op);

	calculate(num, op);
	ans=Ans(sum,op);
	printf("%d", ans);

	return 0;
}

void calculate(int num[], char op[])
{
	i=0;
	for(j=0;;j++)
	{
		sum[j]=num[i];
		if(op[0]=='=')
			return;
		while(op[i]!='+'&&op[i]!='-')
		{
			switch(op[i])
			{
				case '*': sum[j]*=num[i+1];break;
				case '/': sum[j]/=num[i+1];break;
				default:break;
			}
			if(op[i]=='=')
				break;
			i++;
		}
		if(op[i]=='=')
			break;
		if(op[i]=='+'||op[i]=='-')
			i++;
	}
	return ;
}
int Ans(long long sum[], char op[])
{
	int ans=sum[0];
	i=0;
	for(j=0;;j++)
	{
		while(op[j]=='+'||op[j]=='-')
		{
			switch (op[j])
			{
				case '+':ans+=sum[i+1];break;
				case '-':ans-=sum[i+1];break;
			}
			i++;
			break;
		}
		if(op[j]=='=')
		break;
	}
	return ans;
}













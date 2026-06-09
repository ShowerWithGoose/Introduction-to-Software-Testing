#include<stdio.h>
void f(int a,int b);
int mark[20]={0};
char ret[50];
int n;
int main()
{
	scanf("%d",&n);
	f(0,n);
	return 0;
}

void f(int a,int b)
{
	int i;
	
	if(b==0)
	{
		ret[2*a+1]='\0';
		puts(ret);
		return;
	}
	
	for(i=1;i<=n;i++)
	{
		if(mark[i]==0)
		{
			ret[2*a]=i+'0';
			ret[2*a+1]=' ';
			mark[i]=1;
			f(a+1,b-1);
			mark[i]=0;
		}
	}
}
	




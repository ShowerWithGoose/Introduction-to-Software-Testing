#include<stdio.h>
#include<string.h>
char str[15];
int mark[15];
int n;
void rank(int x,int y)
{
	int i=1;
	if(y==0)
	{
		for(int i=0;i<strlen(str);i++)
		{
			printf("%c ",str[i]);
		}
		printf("\n");
		return;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(mark[i]==0)
			{
				str[x]=i+'0';
				mark[i]=1;
				rank(x+1,y-1);
				mark[i]=0;
			}
		}
	}
 } 
 int main()
 {
 	scanf("%d",&n);
 	rank(0,n);
 	return 0;
 }


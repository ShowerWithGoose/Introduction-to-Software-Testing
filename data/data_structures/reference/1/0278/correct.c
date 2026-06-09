#include<stdio.h>
#include<string.h>
#include<ctype.h>
int a[11];
char m[25];
int n;
int pailie(int N,int i)
{
	if(N==0)
	{
		m[i]='\0';
		printf("%s\n",m);
		return 0;
	}
	else
	{
		for(int t=1;t<=n;t++)
		{
			if(a[t]==0)
			{
				if(t!=10)
				{
					a[t]=1;
				m[i]='0'+t;
				m[i+1]=' ';
				pailie(N-1,i+2);a[t]=0;
				}
				else
				{
					a[t]=1;
					m[i]='1';
					m[i+1]='0';
					m[i+2]=' ';
					pailie(N-1,i+3);a[t]=0;
				}
			}
		}
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	n=N;
	pailie(N,0);
	return 0;
}


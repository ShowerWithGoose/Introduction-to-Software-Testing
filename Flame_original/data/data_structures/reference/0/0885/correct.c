#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 10000
char k,in[MAXSIZE];
int l;
int pd(int i)
{
	if(i-1>=0)
	{
		if(in[i-1]<in[i+1])
		{
			if(in[i-1]<='Z'&&in[i+1]<='Z'&&in[i-1]>='A'&&in[i+1]>='A')
			return 1;
			else if(in[i-1]<='z'&&in[i+1]<='z'&&in[i-1]>='a'&&in[i+1]>='a')
			return 1;
			else if(in[i-1]<='9'&&in[i+1]<='9'&&in[i-1]>='0'&&in[i+1]>='0')
			return 1;
			else return 0;
		}
	}
	else return 0;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i=0;
	scanf("%s",in);
	l=strlen(in);
	while(i<l)
	{
		if(in[i]=='-')
		{
			if(pd(i))
			for(k=in[i-1]+1;k<in[i+1];k++)
			printf("%c",k);
			else printf("%c",in[i]);
		}
		else printf("%c",in[i]);
		i++;
	}
	return 0;
}



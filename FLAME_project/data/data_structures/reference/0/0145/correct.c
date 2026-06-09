#include<stdio.h>
#include<math.h>
#include<string.h>
char s[100000],ch[100000];

void f(int i, int len )
{
	int x,k=1,y,j,t;
	y=i+1;
	x=s[i+1]-s[i-1]+1;
	for(j=0;y<=len;y++,j++)
	ch[j]=s[y];
	
	for(k=1;k<=x;k++)
	{
		s[i+k-1]=s[i-1]+k;
	}
	for(t=0;t<j;t++)
	
	s[i+x+t-1]=ch[t+1];
}
int main()
{
	gets(s);
	int i=0,j=0,len;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]=='-'&&s[i+1]>s[i-1])
		{
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')
			{
				f(i,len);
			}
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')
			f(i,len);
			else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')
			f(i,len); 
		}
		len=strlen(s);
	}
	printf("%s",s);
	return 0;
}



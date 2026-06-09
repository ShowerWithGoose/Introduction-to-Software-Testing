#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define Status int
int main()
{
	char s[5000], ch[5000];
	gets(s);
	int L, l=0;
	L=strlen(s);
	for(int i=0;i<L;i++)
	{
		if(s[i]=='-'&&i>0&&i<L)
		{
			if(s[i-1]>='a'&&s[i-1]<'z'&&s[i+1]>'a'&&s[i+1]<='z'&&s[i-1]<s[i+1]||s[i-1]>='A'&&s[i-1]<'Z'&&s[i+1]>'A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]||s[i-1]>='0'&&s[i-1]<'9'&&s[i+1]>'0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
			{
				l=s[i+1]-'a'+'a'-s[i-1];
				if(l==1)
				{
					for(int k=i+1;k<=L;k++)
						s[k-1]=s[k];
				}
				else if(l>1)
				{
					for(int k=i;k<L;k++)
						ch[k]=s[k];
					for(int j=i;j<i+l;j++)
						s[j]=s[i-1]+j-i+1;
					for(int k=i;k<L-1;k++)
						s[k+l-1]=ch[k+1];
				}
			}
			L=L+l-2;
		}
	}
	puts(s);
	return 0;
}




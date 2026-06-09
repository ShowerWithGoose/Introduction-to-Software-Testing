#include<stdio.h>
int main()
{
	char str[1000],ch[1000];
	int i,j,a,b,A,B,n,m;
	scanf("%s",str);
	for(i=0,j=0;str[i]!='\0';i++)
	{
		if(str[i]=='-'&&i>0&&str[i+1]-str[i-1]!=1)
		{
			a=str[i-1]-'a';
			A=str[i-1]-'A';
			n=str[i-1]-'0';
			b=str[i+1]-'a';
			B=str[i+1]-'A';
			m=str[i+1]-'0';
			if((a>=0&&a<=25&&b>=0&&b<=25)||(A>=0&&A<=25&&B>=0&&B<=25)||(n>=0&&n<=9&&m>=0&&m<=9))
			{
				for(;(ch[j-1]!=str[i+1]-1)&&str[i+1]!='\0';j++)
				{
					ch[j]=ch[j-1]+1;	
				}	
			}	
			else
			{
				ch[j]=str[i];
				j++;	
			}
		}	
		else
		{
			ch[j]=str[i];
			j++;	
		}
	}
	ch[j]='\0';
	printf("%s",ch);
	return 0;
}


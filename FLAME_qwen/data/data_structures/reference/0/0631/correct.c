#include<stdio.h>
#include<string.h>
int main()
{
	int i,j=0,k,m=0;
	int flag=-1;
	int mark=0;
	char str[10000];
	char s[100000];
	scanf("%s",&str);
	char sign;
	sign='-';
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==sign&&i!=0&&str[i+1]!='\0')
		{
			if(flag==-1)
			{
				for(k=0;k<=i-2;k++)
				{
					s[j]=str[k];
					j++;
				}
				mark=j;
			}
			else if(i-1-(flag+1)>1)
			{
				for(k=flag+2;k<=i-2;k++)
				{
					s[j]=str[k];
					j++;
				}
				mark=j;
			}
			if(str[i-1]>='a'&&str[i-1]<='z'&&str[i+1]>='a'&&str[i+1]<='z'&&str[i-1]<str[i+1])
			{
				if(i-flag==2&&flag!=-1)
				{
					mark--;
				}
				flag=i;
				for(m=mark;m<=mark+(str[i+1]-str[i-1]);m++)	
				{
				s[m]=str[i-1]+m-mark;
				}
				mark=m;
			}
			else if(str[i-1]>='A'&&str[i-1]<='Z'&&str[i+1]>='A'&&str[i+1]<='Z'&&str[i-1]<str[i+1])
			{
				if(i-flag==2&&flag!=-1)
				{
					mark--;
				}
				flag=i;
				for(m=mark;m<=mark+(str[i+1]-str[i-1]);m++)	
				{
				s[m]=str[i-1]+m-mark;
				}
				mark=m;
			}
			else if(str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>='0'&&str[i+1]<='9'&&str[i-1]<str[i+1])
			{
				if(i-flag==2&&flag!=-1)
				{
					mark--;
				}
				flag=i;
				for(m=mark;m<=mark+(str[i+1]-str[i-1]);m++)	
				{
				s[m]=str[i-1]+m-mark;
				}
				mark=m;
			}
		}
	}
	if(flag==-1)
	{
		printf("%s",str);
		return 0;
	}
	else if(str[flag+2]!='\0')
	{
		for(i=flag+2;str[i]!='\0';i++)
		{
			s[m]=str[i];
			m++;
		}
		s[m]='\0';
	}
	printf("%s",s);
	return 0;
}


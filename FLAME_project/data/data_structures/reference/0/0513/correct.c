#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],ans[2000];
	memset(ans,' ',sizeof(ans));
	gets(s);
	int i=0,j=0,step=1;
	while(s[i]!='\0')
	{
		if(s[i]!='-')
		{
			ans[j]=s[i];
		}
		else
		{
			if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
			{
				j+=s[i+1]-s[i-1]-2;
			}
		    else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
			{
				j+=s[i+1]-s[i-1]-2;
			}
			else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
			{
				j+=s[i+1]-s[i-1]-2;
			}
			else
			{
				ans[j]=s[i];
			}
		}
		i++,j++;
	}
	ans[j]='\0';
	j=0;
	while(ans[j]!='\0')
	{
		if(ans[j]==' ')
		{
			int k=j-1;
			while(ans[j]==' ')
			{
				ans[j]=ans[k]+step;
				step++,j++;
			}
		}
		j++;
		step=1;
	}
	printf("%s",ans);
	return 0;
}



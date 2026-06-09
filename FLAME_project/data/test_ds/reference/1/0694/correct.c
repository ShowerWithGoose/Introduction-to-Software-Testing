#include<stdio.h>
#include<string.h>
char s[100],d[1000];
int main()
{
	scanf("%s",s);
	int i=0,j=0;
	while(s[i]!='\0')
	{
		if(s[i]=='-'&&(('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='9')||'a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='z'||'A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='Z'))
		{
			int k=0;
			while(d[j-1]<s[i+1]-1)
			{
				k++;
				d[j]=s[i-1]+k;
				j++;
			}
		}
		else
		{
			d[j]=s[i];
			j++;			
		}
		i++;
	}
	int q=0;
	while(q<=j)
	{
		printf("%c",d[q]);
		q++;
	}
	return 0;
}


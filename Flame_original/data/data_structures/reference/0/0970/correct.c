#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	char s1[10+5],s2[100+5];
	int i,j,k=0;
	scanf("%s",s1);
	for(i=0;i<strlen(s1);i++)
	{
		if(i!=0&&s1[i]=='-')
		{
			if(s1[i-1]>='0'&&s1[i-1]<='9' && s1[i+1]>='0'&&s1[i+1]<='9' && s1[i-1]<s1[i+1])
			{
				for(j=1;j<=s1[i+1]-s1[i-1];j++)
				{
					s2[k++]=s1[i-1]+j;
				}
				i++;
			}
			else if(s1[i-1]>='a'&&s1[i-1]<='z' && s1[i+1]>='a'&&s1[i+1]<='z' && s1[i-1]<s1[i+1])
			{
				for(j=1;j<=s1[i+1]-s1[i-1];j++)
				{
					s2[k++]=s1[i-1]+j;
				}
				i++;
			}
			else if(s1[i-1]>='A'&&s1[i-1]<='Z' && s1[i+1]>='A'&&s1[i+1]<='Z' && s1[i-1]<s1[i+1])
			{
				for(j=1;j<=s1[i+1]-s1[i-1];j++)
				{
					s2[k++]=s1[i-1]+j;
				}
				i++;
			}
			else
				s2[k++]=s1[i];
		}
		else
			s2[k++]=s1[i];
	}
	s2[k]='\0';
	printf("%s",s2);
	return 0;
}



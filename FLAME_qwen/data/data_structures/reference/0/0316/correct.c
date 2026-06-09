#include <stdio.h>
int main()
{	
	char s[100],s2[100];
	int i=0,j=0,k=0; 
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{	
		if(s[i]=='-')
		{
			k=0;
			if(s[i-1]>='0'&&s[i+1]<='9')
			for(j=1;j<=(s[i+1]-s[i-1]-1);j++)
			{	k=1;
				printf("%c",s[i-1]+j);
			}
			else if (s[i-1]>='a'&&s[i+1]<='z')
			for(j=1;j<=(s[i+1]-s[i-1]-1);j++)
			{
				k=1;
				printf("%c",s[i-1]+j);
			}
			else if (s[i-1]>='A'&&s[i+1]<='Z')
			for(j=1;j<=(s[i+1]-s[i-1]-1);j++)
			{
				k=1;
				printf("%c",s[i-1]+j);
			}
			if(k==0)
			printf("%c",s[i]);
		}
		else if(s[i]!='/0')
		printf("%c",s[i]);
	}
	
	return 0;
}


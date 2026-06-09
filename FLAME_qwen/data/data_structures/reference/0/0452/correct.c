#include <stdio.h>
#include <string.h>
int main()
{
	char str[1001];
	gets(str);
	int len=strlen(str);
	int i,j,k,m;
	for(i=0;i<len;i++)
	{
		if(str[i]=='-'&&((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z')&&str[i-1]<str[i+1]))
		{
			k=str[i-1];
			m=str[i+1];
			for(j=k+1;j<m;j++)
			printf("%c",j);
		}
		else if(str[i]=='-'&&((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z')&&str[i-1]<str[i+1]))
		{
			k=str[i-1];
			m=str[i+1];
		    for(j=k+1;j<m;j++)
			printf("%c",j);
		}
		else if(str[i]=='-'&&((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9')&&str[i-1]<str[i+1]))
				{
					k=str[i-1];
					m=str[i+1];
				    for(j=k+1;j<m;j++)
					printf("%c",j);
				}
				else{
					printf("%c",str[i]);
				}
	}
	return 0;
}




#include<stdio.h>
#include<string.h>
int main()
{
	char line[105],k,i;
	gets(line);
	for(i=0;i<strlen(line);i++)
	{
		if(line[i]=='-')
		{
			if(line[i-1]>='a'&&line[i-1]<='z'&&line[i+1]>='a'&&line[i+1]<='z'&&line[i-1]<line[i+1])
			{
				for(k=line[i-1]+1;k<line[i+1];k++)
				{
					printf("%c",k);
				}
			}
			else if(line[i-1]>='A'&&line[i+1]<='Z'&&line[i+1]>='A'&&line[i+1]<='Z'&&line[i-1]<line[i+1])
			{
				for(k=line[i-1]+1;k<line[i+1];k++)
				{
					printf("%c",k);
				}
			}
			else if(line[i-1]>='0'&&line[i+1]<='9'&&line[i+1]>='0'&&line[i+1]<='9'&&line[i-1]<line[i+1])
			{
				for(k=line[i-1]+1;k<line[i+1];k++)
				{
					printf("%c",k);
				}
			}
			else printf("%c",line[i]);
			}
			else printf("%c",line[i]);
	}
	return 0;
}
	
	
 




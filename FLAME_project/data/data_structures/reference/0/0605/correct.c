#include<stdio.h>
#include<string.h>
int main()
{
	char line[105],letter,i;
	gets(line);
	for(i=0;i<strlen(line);i++)
	{
		if(line[i]=='-')
		{
			if(line[i-1]>='a'&&line[i-1]<='z'&&line[i+1]>='a'&&line[i+1]<='z'&&line[i-1]<line[i+1])
			{
				for(letter=line[i-1]+1;letter<line[i+1];letter++)
				{
					printf("%c",letter);
				}
			}
			else if(line[i-1]>='A'&&line[i+1]<='Z'&&line[i+1]>='A'&&line[i+1]<='Z'&&line[i-1]<line[i+1])
			{
				for(letter=line[i-1]+1;letter<line[i+1];letter++)
				{
					printf("%c",letter);
				}
			}
			else if(line[i-1]>='0'&&line[i+1]<='9'&&line[i+1]>='0'&&line[i+1]<='9'&&line[i-1]<line[i+1])
			{
				for(letter=line[i-1]+1;letter<line[i+1];letter++)
				{
					printf("%c",letter);
				}
			}
			else printf("%c",line[i]);
			}
			else printf("%c",line[i]);
	}
	return 0;
}
	
	
 




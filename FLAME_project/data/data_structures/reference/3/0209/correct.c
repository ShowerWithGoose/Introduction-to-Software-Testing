#include<stdio.h>
#include<string.h>
int main()
{
	char str[150];
	int find_count,delete_count;
	
	gets(str);
	delete_count=strlen(str)-1;
	if(str[0]!='-')
	{
		if(str[0]!='0')
		{
			for(find_count=0;str[find_count]!='.';find_count++);
			str[find_count]='\0';
		
			printf("%c.%s%se%d",str[0],&str[1],&str[find_count+1],find_count-1);
		}
		else
		{
			for(find_count=2;str[find_count]=='0';find_count++);
			if(find_count==delete_count)
			{
				printf("%ce-%d",str[find_count],find_count-1);
				return 1;
			}
		
			printf("%c.%se-%d",str[find_count],&str[find_count+1],find_count-1);
		}
	}

	return 1;
	
	
}


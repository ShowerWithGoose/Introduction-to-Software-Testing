#include<stdio.h>
#include<string.h>

int main()
{
	char line[192608];
	int flag1=1,i=0,k=0;
	gets(line);
	if(line[0]=='0'&&line[1]=='.')
	{
		for(i=2;i<strlen(line);i++)
		{
			if(line[i]=='0')
				flag1++;
		    else
				break;
		}
		if(i==strlen(line)-1)
		{
			printf("%c",line[i]);
			printf("e-%d",flag1);
		}
		else
		{
			printf("%c.",line[i]);
			for(k=i+1;k<strlen(line);k++)
			{
				printf("%c",line[k]);
			}
			printf("e-%d",flag1);
		}
		
		
	}
	else
	{
		flag1=0;
		while(line[i]!='.')
		{
			i++;
			flag1++;
		}
		//printf("%d",cnt-1);
		printf("%c.",line[0]);
		for(i=1;i<strlen(line);i++)
		{
			if(line[i]=='.')
				i++;
			printf("%c",line[i]);
		}
		printf("e%d",flag1-1);
	}
	return 0;
}


#include<stdio.h>
#include<string.h>

int main()
{
	char line[192608];
	int cnt=1,i=0,j=0;
	gets(line);
	if(line[0]=='0'&&line[1]=='.')
	{
		for(i=2;i<strlen(line);i++)
		{
			if(line[i]=='0')
				cnt++;
		    else
				break;
		}
		if(i==strlen(line)-1)
		{
			printf("%c",line[i]);
			printf("e-%d",cnt);
		}
		else
		{
			printf("%c.",line[i]);
			for(j=i+1;j<strlen(line);j++)
			{
				printf("%c",line[j]);
			}
			printf("e-%d",cnt);
		}
		
		
	}
	else
	{
		cnt=0;
		while(line[i]!='.')
		{
			i++;
			cnt++;
		}
		//printf("%d",cnt-1);
		printf("%c.",line[0]);
		for(i=1;i<strlen(line);i++)
		{
			if(line[i]=='.')
				i++;
			printf("%c",line[i]);
		}
		printf("e%d",cnt-1);
	}
	return 0;
}


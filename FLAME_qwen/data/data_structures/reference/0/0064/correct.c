#include<stdio.h>
#include<string.h>

char io[500];
int main()
{
	int i,j,k;
	gets(io);
	for(i=0;i<=strlen(io);i++)
	{
		if(io[i]!='-')
		{
			printf("%c",io[i]);
		}
		else
		{
			if((io[i-1]>='a' && io[i-1]<='z') && (io[i+1]>='a' && io[i+1]<='z') && (io[i+1]>io[i-1]))
			{
				for(k=1;k<(io[i+1]-io[i-1]);k++)
				printf("%c",k+io[i-1]);
			}
			else if((io[i-1]>='0' && io[i-1]<='9') && (io[i+1]>='0' && io[i+1]<='9') && (io[i+1]>io[i-1]))
			{
				for(k=1;k<(io[i+1]-io[i-1]);k++)
				printf("%c",k+io[i-1]);
			}
			else if((io[i-1]>='A' && io[i-1]<='Z') && (io[i+1]>='A' && io[i+1]<='Z') && (io[i+1]>io[i-1]))
			{
				for(k=1;k<(io[i+1]-io[i-1]);k++)
				printf("%c",k+io[i-1]);
			}
			else
			{
				printf("-");
			}
		}
	}
	
	return 0;
}




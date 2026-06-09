#include<stdio.h>
int main()
{
	char luru[1000];
	gets(luru);
	for(int i=0;;i++)
	{
		if(luru[i+1]=='\0')
		{
			printf("%c",luru[i]);
			break;
		}
		else
		{
			if(luru[i+1]!='-') printf("%c",luru[i]);
			else
			{
				i+=1;
				if(luru[i-1]>='a'&&luru[i+1]<='z'&&luru[i-1]<luru[i+1])
				{
					for(int j=luru[i-1];j<luru[i+1];j++)
					{
						printf("%c",j);
					}	
					
				}
				else if(luru[i-1]>='A'&&luru[i+1]<='Z'&&luru[i-1]<luru[i+1])
				{
					for(int j=luru[i-1];j<luru[i+1];j++)
					{
						printf("%c",j);
					}	
					
				}
				else if(luru[i-1]>='0'&&luru[i+1]<='9'&&luru[i-1]<luru[i+1])
				{
					for(int j=luru[i-1];j<luru[i+1];j++)
					{
						printf("%c",j);
					}	
					
				}
				else {printf("%c%c",luru[i-1],luru[i]);
				
				}
			}
		}
	}
	return 0;
}


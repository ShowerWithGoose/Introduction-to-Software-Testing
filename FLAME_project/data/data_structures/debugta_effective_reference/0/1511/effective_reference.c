#include<stdio.h>
#include<string.h>
int main()
{
	char c[1000];
	char d[1000];
	scanf("%s", c);
	int j = 0;
	for(int i = 0; i <= strlen(c) - 1; i++)
	{
		if(((c[i]>='a' && c[i]<='z')||(c[i]>='0' && c[i]<='9')||(c[i]>='A' && c[i]<='Z') ))
		{
			d[j] = c[i];
			j++;
		}

		else if(i >= 1 && i <= strlen(c)-2 && c[i] == '-' && !(((c[i-1]>='a' && c[i-1]<='z')&&(c[i+1]>='a' && c[i+1]<='z'))||((c[i-1]>='0' && c[i-1]<='9')&&(c[i+1]>='0' && c[i+1]<='9'))||((c[i-1]>='A' && c[i-1]<='Z')&&(c[i+1]>='A' && c[i+1]<='Z')))&&(c[i-1]<c[i+1]))
		{
			d[j] = c[i];
			j++;
		}
		else if(i >= 1 && i <= strlen(c)-2 && c[i] == '-' &&(((c[i-1]>='a' && c[i-1]<='z')&&(c[i+1]>='a' && c[i+1]<='z'))||((c[i-1]>='0' && c[i-1]<='9')&&(c[i+1]>='0' && c[i+1]<='9'))||((c[i-1]>='A' && c[i-1]<='Z')&&(c[i+1]>='A' && c[i+1]<='Z'))))
		{
			if(c[i-1]>='a' && c[i-1]<='z')
			{
				for(int j = 1; j <= (int)(c[i+1] - c[i-1]-1); j++ )
				{

					d[j] = c[i-1] + j;
					j +=1 ;
				}
			}
			if(c[i-1]>='A' && c[i-1]<='Z')
			{
				for(int j = 1; j <= (int)(c[i+1] - c[i-1]-1); j++ )
				{

					d[j] = c[i-1] + j;
					j +=1 ;
				}
			}
			if(c[i-1]>='0' && c[i-1]<='9')
			{
				for(int j = 1; j <= (int)(c[i+1] - c[i-1]-1); j++ )
				{

					d[j] = c[i-1] + j;
					j +=1 ;
				}
			}
		}	
	}
	for(int i = 0; i <= j-1; i++)
	{
		printf("%c", d[i]);
	}
	return 0;
	
}




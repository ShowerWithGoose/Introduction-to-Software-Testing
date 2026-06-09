#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
char in[105];

int main() 
{
	gets(in);
	int l = strlen(in);
	if (in[0] == '0') 
	{
		int e = 0, start = 0;
		int flag = 0;
		for (int i = 2; i < l; i++) 
		{
			if (in[i] == '0') 
			{
				e++;
			} 
			else 
			{
				if (start == 0) 
				{
					start = i;
					if (in[i + 1] >= '0' && in[i + 1] <= '9') 
					{
						flag = 1;
					}
					break;
				}
			}
		}
		printf("%c",in[start]);
		if(flag) printf(".");
		for(int i=start+1;i<l;i++)
		{
			printf("%c",in[i]);
		}
		printf("e-%d",e+1);
	}
	else
	{
		printf("%c",in[0]);
		int e=0;
		while(in[e]!='.')
		{
			e++;
		}
		if(in[1]!='\0') printf(".");
		for(int i=1;i<l;i++)
		{
			if(in[i]!='.')
			{
				printf("%c",in[i]);
			}	
		}
		printf("e%d",e-1);
	}
	return 0;
}


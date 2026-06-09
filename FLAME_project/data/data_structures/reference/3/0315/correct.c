#include <stdio.h>
#include <string.h>
char num[1005];
int l;
void out(int pos,int power)
{
	printf("%c",num[pos]);
	if(pos == l-1) 
	{
		printf("e%d",power);
		return;
	}
		
	printf(".");
	for(int i=pos+1;i<l;i++)
	{
		if(num[i]!='.') printf("%c",num[i]);
	}
	printf("e%d",power);
	return;
}
int main() {
	gets(num);
	l = strlen(num);
	
	int isdot = 0;
	for(int i=0; i<l; i++)
	{
		if(num[i]=='.'&&i==1)
		{
			isdot = 1;
			int k=-1;
			if(num[0]=='0')
			{
				for(int j=2; j<l; j++) {
					if(num[j] == '0')
					{
						k--;
					}
					else
					{
						out(j,k);break;
					}
				}
				break;
			}
			else
				{
					isdot = 1;printf("%se0",num);break;
				}
		}
		
		if (num[i] == '.')
		{
			out(0,i-1);isdot=1;
			break;
		}
			
	}
	if (isdot == 0)
	{
		out(0,l-1);
	}
	return 0;
}




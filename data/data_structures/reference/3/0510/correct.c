#include<stdio.h>
#include<string.h>

int main(void)
{
	char in[1000];
	gets(in);
	int cnt,i=0;
	if(in[0]!='0'&&in[1]=='.')     printf("%se0",in);
    else if(in[0]=='0'&&in[1]=='.')
    {
    	cnt=1;
    	for(i=2;in[i]=='0';i++) cnt++;
    	printf("%c",in[i]);
    	if(cnt!=1) printf(".");
    	for(i++;i<strlen(in);i++)
    	   printf("%c",in[i]);
    	printf("e-%d",cnt);
	}
	else 
	{
		for(cnt=0;in[cnt]!='.';cnt++);
		printf("%c.",in[0]);
		for(i=1;i<cnt;i++)
		{
			printf("%c",in[i]);
		}	
		for(i=cnt+1;i<strlen(in);i++)
		{
			printf("%c",in[i]);
		}
		printf("e%d",cnt-1);
	}
	
	return 0;
 } 


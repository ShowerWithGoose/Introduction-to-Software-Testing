#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char input[105]; 
int i,len,di,zhi,j;
int main() {
	scanf("%s",input);
	len=strlen(input);
	if(input[0]=='0')              //纯小数的情况 
	{
		zhi=-1;
		for(i=2;input[i]=='0';i++)
		{
			zhi--;
		}
		printf("%c",input[i]);
        if(input[i+1]!='\0')
        {
        	putchar('.');
        	for(j=i+1;input[j]!=0;j++)
        	{
        		putchar(input[j]);
			}
		}
		printf("e%d",zhi);
		return 0;
	}
	//带小数的情况 
	for(i=0;input[i]!='.';i++);
	zhi=i-1;
	putchar(input[0]);
	putchar('.');
	for(i=1;input[i]!='\0';i++)
	{
		if(input[i]!='.') putchar(input[i]);
	}
	printf("e%d",zhi);
	return 0;
}




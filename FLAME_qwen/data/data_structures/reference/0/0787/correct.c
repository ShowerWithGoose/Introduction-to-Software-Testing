#include<stdio.h>
#include<string.h>
#include<ctype.h>
char input[1024];
int book[1024][2];
int out;
int main()
{
	gets(input);
	int len=strlen(input);
	printf("%c",input[0]);
	for(int i=1;i<len-1;i++)
	{
		if(input[i]=='-')
		{
			
			if((input[i-1]<input[i+1])&&(isdigit(input[i-1])&&isdigit(input[i+1])||islower(input[i-1])&&islower(input[i+1])||isupper(input[i-1])&&isupper(input[i+1])))
			{
				for(out=input[i-1]+1;out<input[i+1];out++)
					printf("%c",out);			
			}
			else
			printf("%c",input[i]);
		}else
		printf("%c",input[i]);
	}
	printf("%c",input[len-1]);
return 0;
}





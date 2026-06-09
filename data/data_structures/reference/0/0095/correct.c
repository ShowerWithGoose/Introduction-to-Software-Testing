#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void fun(char s[])
{
    for(int i=0;s[i];i++)
    {
		char op;
		if((s[i]=='-'))
		{
		if(s[i-1]<=s[i+1])
		{	
			if((isdigit(s[i-1])&&isdigit(s[i+1]))||(islower(s[i-1])&&islower(s[i+1]))||(isupper(s[i-1])&&isupper(s[i+1])))
			{
				for(op=s[i-1]+1;op<s[i+1];op++)
					printf("%c",op);
			}
			else
			printf("%c",s[i]);			
		}
		
	    }
		else
			printf("%c",s[i]);
	}
}
int main()
{
	char arr[1000]={'\0'};
	int c,i=0;
	while((c=getchar())!= EOF)
	{
		arr[i++]=c;
	}
	
	fun(arr);
	return 0;
}



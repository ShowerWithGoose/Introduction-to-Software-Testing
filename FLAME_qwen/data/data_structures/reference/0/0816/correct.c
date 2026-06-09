#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

char initial[100001];
int chtype(char a){
	if(islower(a))
	return 1;
	if(isupper(a))
	return 2;
	if(isdigit(a))
	return 3;
}
int main()
{
	int i,k,m,re;
	gets(initial);
	for(i=0;i<strlen(initial);i++)
	{
		if(initial[i]!='-')
		putchar(initial[i]);
		else if(initial[i]='-')
		{   if(initial[i-1]<initial[i+1]&&chtype(initial[i-1])==chtype(initial[i+1])){
		
		    re=initial[i+1]-initial[i-1];
			for(k=0,m=initial[i-1]+1;k<re-1;k++,m++)
			{
				putchar(m);
			}
		}
		else
		putchar(initial[i]);
	}
	}
	return 0;
}
	
 







#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include <ctype.h>
char a[1000];

int main()
{	
    int i,j=0,len;
    char b[1000],m;
	gets(a);
    len=strlen(a);
	while(i<len)
	{
	   b[j++]=a[i];
		if(a[i+1]=='-'&&a[i]<a[i+2]&&((isdigit(a[i])&&isdigit(a[i+2]))||(islower(a[i])&&islower(a[i+2]))||(isupper(a[i])&&isupper(a[i+2]))))
		{
			for(m=a[i]+1;m<a[i+2];m++)
			{
				b[j++]=m;
			}
			i +=2;
		}
		else
		i +=1;
	}
	b[j]='\0';
	printf("%s",b);
	return 0;
}


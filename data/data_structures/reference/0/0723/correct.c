#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char a[1000];
void print(char a,char b)
{
	for(int i=a+1;i<=b-1;i++) 
	    printf("%c",i);
}

int main()
{
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)
    {
    	if(a[i]=='-')
    	{
    		if(islower(a[i-1])&&islower(a[i+1])&&a[i-1]<a[i+1]) print(a[i-1],a[i+1]);
    		else if(isupper(a[i-1])&&isupper(a[i+1])&&a[i-1]<a[i+1]) print(a[i-1],a[i+1]);
    		else if(isdigit(a[i-1])&&isdigit(a[i+1])&&a[i-1]<a[i+1]) print(a[i-1],a[i+1]);
    		else printf("%c",a[i]);
		}
		else printf("%c",a[i]);
	}
	return 0;
}






#include<stdio.h>
#include<string.h>
char a[10000];
int main()
{
   scanf("%s",a);
   for(int i=0;i<strlen(a);i++)
   {
   	if(a[i]==45)
   	{
   		if((a[i-1]>=97&&a[i-1]<=122&&a[i+1]>=97&&a[i+1]<=122&&a[i-1]<a[i+1])||(a[i+1]>=48&&a[i+1]<=57&&a[i-1]>=48&&a[i-1]<=57&&a[i-1]<a[i+1])||(a[i+1]>=65&&a[i+1]<=90&&a[i-1]>=65&&a[i-1]<=90&&a[i-1]<a[i+1]))
	   	{
		   for(int j=a[i-1];j<a[i+1];j++)
		   {
		   	if(j>a[i-1])
		     printf("%c",j);			   	
		   }	
		} 
		else printf("%c",a[i]);
	}
	else printf("%c",a[i]);
   }
   return 0;
}


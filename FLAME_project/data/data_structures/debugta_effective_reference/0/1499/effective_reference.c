#include<stdio.h>
#include<string.h>
char a[10000];
int main()
{
   scanf("%s",a);
   for(int toa=0;toa<strlen(a);toa++)
   {
   	if(a[toa]==45)
   	{
   		if((a[toa-1]>=97&&a[toa-1]<=122&&a[toa+1]>=97&&a[toa+1]<=122&&a[toa-1]<a[toa+1])||(a[toa+1]>=48&&a[toa+1]<=57&&a[toa-1]>=48&&a[toa-1]<=57&&a[toa-1]<a[toa+1])||(a[toa+1]>=65&&a[toa+1]<=90&&a[toa-1]>=65&&a[toa-1]<=90&&a[toa-1]<a[toa+1]))
	   	{
		   for(int i=a[toa-1];i<a[toa+1];i++)
		   {
		   	if(i>a[toa-1])
		     printf("%c",i);			   	
		   }	
		} 
		else printf("%c",a[toa]);
	}
	else printf("%c",a[toa]);
   }
   return 0;
}


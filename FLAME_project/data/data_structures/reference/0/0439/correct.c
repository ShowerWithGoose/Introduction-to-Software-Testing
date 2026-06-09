#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
    scanf("%s",&a);
    char b[100];
	int i=0,j=0;
    while(a[i]!='\0')
    {
    	b[j++]=a[i++];
    	if(a[i]=='-'&&a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1])
    	{
    		int k;
			for(k=1;a[i-1]+k<a[i+1];k++)
			{
				b[j++]=a[i-1]+k;
			}
			i++;    
		}
    	else if(a[i]=='-'&&a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
    	{
    		int k;
			for(k=1;a[i-1]+k<a[i+1];k++)
			{
				b[j++]=a[i-1]+k;
			}
			i++;    
		}	
		else if(a[i]=='-'&&a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])
    	{
    		int k;
			for(k=1;a[i-1]+k<a[i+1];k++)
			{
				b[j++]=a[i-1]+k;
			}
			i++;   
		}
	}
	b[j]='\0';
	puts(b);
    return 0;
}


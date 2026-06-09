#include<stdio.h>
#include<string.h>

int main ()
{
	int i=0,gap;
	char a[1005],*p;
	p=a;
	scanf("%s",a); 
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='-')
		{
			if(a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a'&&a[i+1]>a[i-1])
			{
				a[i]='\0';
				printf("%s",p); 
			    for(gap=1;gap<=a[i+1]-a[i-1]-1;gap++)
			    printf("%c",a[i-1]+gap);
			    a[i]=a[i-1]+gap;
			    p=&a[i+1];
			}
			if(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A'&&a[i+1]>a[i-1])
			{
				a[i]='\0';
				printf("%s",p); 
			    for(gap=1;gap<=a[i+1]-a[i-1]-1;gap++)
			    printf("%c",a[i-1]+gap);
			    a[i]=a[i-1]+gap;
			    p=&a[i+1];
			}
			if(a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0'&&a[i+1]>a[i-1])
			{
				a[i]='\0';
				printf("%s",p); 
			    for(gap=1;gap<=a[i+1]-a[i-1]-1;gap++)
			    printf("%c",a[i-1]+gap);
			    a[i]=a[i-1]+gap;
			    p=&a[i+1];
			}
		}
		
		continue;
	}
	printf("%s",p);
	return 0;
 } 


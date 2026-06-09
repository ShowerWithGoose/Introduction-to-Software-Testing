#include<stdio.h>
#include<string.h>
char a[105];
int main()
{
	int i,l,tp,fl=0,bj;
	scanf("%s",a);
	l=strlen(a);
	if(a[0]=='0')
	{
		if(a[1]=='.')
		{
			for(i=2;i<l;i++)
		    if(a[i]!='0') {fl=1;break;}
		    if(fl)
		    {
		    	for(i=2;i<l;i++)
				if(a[i]!='0') {printf("%c",a[i]);tp=i-1;i++;break;}
				bj=i;
				for(;i<l;i++)
		        if(a[i]!='0') {fl=1;break;}
		        if(!fl)
		        {
		        	fl=0;
		        	for(i=bj;i<l;i++)
					if(a[i]!='0') 
					{
						if(!fl) printf(".%c",a[i]),fl=1;
						else  putchar(a[i]);
					}
					printf("e-%d",tp);
				}
				else
				{
					fl=0;
		        	for(i=bj;i<l;i++) 
					if(!fl) printf(".%c",a[i]),fl=1;
					else  putchar(a[i]);
					printf("e-%d",tp);
				}
			}
			else putchar('0');
		}
		else putchar('0');
	}
	else
	{
		putchar(a[0]);
		for(i=1;i<l;i++)
		if(a[i]!='0'&&a[i]!='.') {fl=1;break;}
		if(fl)
		{
			putchar('.');
			tp=l-1;
			for(i=1;i<l;i++)
			if(a[i]!='.') putchar(a[i]);
			else tp=i-1;
			printf("e%d",tp); 
		}
		else
		{
			tp=l-1;
			for(i=1;i<l;i++)
			if(a[i]=='.') {tp=i-1;break;}
			printf("e%d",tp); 
		}
	}
 } 




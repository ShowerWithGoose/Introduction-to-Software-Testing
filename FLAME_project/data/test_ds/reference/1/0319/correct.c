#include <stdio.h>
#include <string.h>

int getcato(char *p)
{
	if(*p>='a'&&*p<='z')return 0;
	else if(*p>='A'&&*p<='Z')return 1;
	else if(*p>='0'&&*p<='9')return 2;
}

int main()
{
	char a[100]="",b[100]="";
	int i,j,k; 
	gets(a);
	
	for(i=0,j=0;a[i]!='\0';i++)
	{
		if(a[i]!='-')b[j++]=a[i];
		else
		{
			if(getcato(a+i-1)!=getcato(a+1+i)) b[j++]=a[i];
			else if(*(a+i+1)-*(a+i-1)<=0) b[j++]=a[i];
			else
			{
				for(k=1;k<(*(a+i+1)-*(a+i-1));k++)
				b[j++]=*(a+i-1)+k;
			}
		}
		
	}
	
	b[j]='\0';
	
	puts(b);
	return 0;
}


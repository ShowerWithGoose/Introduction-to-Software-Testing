#include<stdio.h>
#include<string.h>
void squeez(char s[],char c)
 { int i,j; 
 for(i=j=0;s[i]!='\0';i++) 
 if(s[i]!=c) s[j++]=s[i]; 
 s[j]='\0'; 
 }
int main()
{
	char a[5000];
	char* p;
	int d=0;
	scanf("%s",a);
	p=a;
	for(int i=0;a[i]!='\0';i++)
	{
	if(a[i]=='.'&&i!=1)
	d=i-1;
	else if(a[i]=='.'&&i==1&&a[0]!='0')
	d=0;
	else if(a[i]=='.'&&i==1&&a[0]=='0')
	{
		for(int j=2;a[j]!='\0';j++)
		{
			if(a[j]!='0')
			{
				d=-j+1;
				p=&a[j-1];
				break;
			}
		}
	}
	}	
	squeez(a,'.');
	int k=strlen(a);
	for(;k>=0;k--)
	{
		if(a[k-1]=='0')
		a[k-1]='\0';
		else
		break;
	}	
    if(*(p+1)!='\0')
	printf("%c.%se%d",*p,p+1,d);
	 else
	 printf("%ce%d",*p,d);
	
	return 0;
}


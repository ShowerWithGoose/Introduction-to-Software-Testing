#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int js(int a, int b, char c);
int main()
{
	char f[100];//·ûºÅ 
	int num[100],i=0,q=0;
	scanf("%d %c",&num[0],&f[0]);
	while(f[i]!='=')
	{
	    i=i+1;
		scanf(" %d",&num[i]);
		scanf(" %c",&f[i]);
    	q=q+1;
	}

	/*for(i=0;f[i]!='=';i++)
	{
		scanf("%d",&num[i]);
		scanf("%c",&f[i+1]);
		q=q+1;
	}*/
	/*for(i=0;i<q;i++)
	{
		printf("%d",num[i]);
		printf("%c",f[i]);
	}
	printf("%d",num[q]);*/
	for(i=0;i<=q;i++)
	{
		char p;
		if(f[i]=='*'||f[i]=='/')
		{
			num[i+1]=js(num[i],num[i+1],f[i]);
			num[i]=0;
			if(i==0)
				f[i]='+';
			else
			{
    			p=f[i-1];
    			f[i-1]='+';
	    		f[i]=p;
			}
		}	
	}
	for(i=0;i<q;i++)
	{
		//printf("%d",num[i]);
		//printf("%c",f[i]);
		num[i+1]=js(num[i],num[i+1],f[i]);
	}
	printf("%d",num[q]);
	return 0;
}
int js(int a, int b, char c)
{
	int jieguo;
	if(c=='+')
		jieguo=a+b;
	else if(c=='-')
		jieguo=a-b;
	else if(c=='*')
		jieguo=a*b;
	else
		jieguo=a/b;
	return jieguo;
}







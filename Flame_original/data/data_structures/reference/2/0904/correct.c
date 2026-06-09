#include<stdio.h>
#include<string.h>
int main()
{
int n2,n3;
    char c1='+';
    char c2;
    char c3;
    int n1=0;
    while(c1!='='&&c2!='='&&c3!='=')
    {
    	scanf("%d %c",&n2,&c2);
    	while(c2=='*'||c2=='/')
    	{
    		scanf("%d %c",&n3,&c3);
    		if(c2=='*')
    		{
    			n2=n2*n3;
			}
			if(c2=='/')
			{
				n2=n2/n3;
			}
			c2=c3;
		}
		if(c1=='+')
		{
			n1=n1+n2;
		}
		if(c1=='-')
		{
			n1=n1-n2;
		}
		c1=c2;
	}
    printf("%d",n1);
		return 0;
}




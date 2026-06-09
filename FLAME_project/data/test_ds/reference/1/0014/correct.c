#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main()
{
	char a[1000];//´æ×Ö·û´® 
	gets(a);
	char x,b;
	int k=0,i,n,q;
    n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]=='-')
		{
			if('0'<=a[i-1]&&a[i-1]<'9'&&a[i+1]>a[i-1]&&a[i+1]<='9')//Êý×Ö 
	    	{
			    	for(q=1;q<a[i+1]-a[i-1];q++)
				    {
	    				x=a[i-1]+q;//ascii
		    			printf("%c",x);
			    	}
		    }
    		else if('A'<=a[i-1]&&a[i-1]<'Z'&&a[i+1]>a[i-1]&&a[i+1]<='Z')//´óÐ´ 
	    	{
					for(q=1;q<a[i+1]-a[i-1];q++)
					{
						x=a[i-1]+q;
						printf("%c",x);
					}
			}
    		else if('a'<=a[i-1]&&a[i-1]<'z'&&a[i+1]>a[i-1]&&a[i+1]<='z')//Ð¡Ð´ 
	    	{
	    			for(q=1;q<a[i+1]-a[i-1];q++)
	    			{
	    				x=a[i-1]+q;
	    				printf("%c",x);
	    			}
	    	}
	    	else
	    		printf("%c",a[i]);
		}
		else 
			printf("%c",a[i]);

	}	
	return 0;
}







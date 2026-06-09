#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
	char a[101],s,b[101];
	int i,o,k,e=-1,lenth;
	scanf("%s",&a);
	lenth=strlen(a);
	if(a[0]=='0')
	{
		for(i=0;i<lenth;i++)
	    {
	        if(a[i]<='9'&&a[i]>'0')
		    {
			    for(o=i,k=0;o<=lenth;o++,k++)
			    {
			    	b[k]=a[o];
				}
				break;
		    }	
        }
		for(i=0,k=-1;i<lenth-1;i++)
	    {
		    if(isdigit(a[1]))
		    {
			    break;
		    }
		    else
		    {
		    	if(a[i]=='0')
		    	{
		    		e--;
		    		k++;
				}
				if(a[i]>'0'&&a[i]<='9')
				{
					break;
				}
			}	
        }
        if(a[1]=='.'&&a[2]>'0'&&a[2]<='9')
        {
        	printf("%s",b);printf("%c%d",'e',e+1);
		}
        else
        {
        s='.';
        for(i=strlen(b);i>0;i--)
        {
        	b[i]=b[i-1];
		}
		b[1]=s;
            printf("%s",b);printf("%c%d",'e',e+1);
        }
	}
	else
	{
	    for(i=0;i<lenth;i++)
	    {
		    if(isdigit(a[i]))
		    {
			    e++;
		    }
		    if(a[i]=='.')
		    {
		    	o=i;
			    break;
		    }
	    }
	    if(a[1]=='.')
		{
			printf("%s",a);printf("%c%d",'e',e);
		}
		else
		{
		s='.';
	    for(i=e;i>0;i--)
	    {
	        a[o]=a[o-1];
			o--;        
		}
		    a[1]=s;
	        printf("%s",a);printf("%c%d",'e',e);
	    }
    }
	return 0;
}


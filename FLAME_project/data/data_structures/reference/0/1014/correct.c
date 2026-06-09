#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    int i;
    scanf("%s",s);
    char *place,*trans,*first;
    first=s;
    place=strchr(s,'-');
    if(place!=NULL)
    {
	    for(;place!=NULL;)
		{
		    if((*(place-1) <='z'&&*(place-1) >='a')&&(*(place+1) <='z'&&*(place+1) >='a'))
		    {
	            *place='\0';
	            printf("%s",first);
	            int a=*(place+1)-*(place-1) ;
	            for(i = 1; i < a; i++)
	            {
	                char c=*(place-1)+i;
	                printf("%c",c);
	            }
		    }
		    else if((*(place-1) <='Z'&&*(place-1) >='A')&&(*(place+1) <='Z'&&*(place+1) >='A'))
		    {
	            *place='\0';
	            printf("%s",first);
	            int a=*(place+1)-*(place-1) ;
	            for(i = 1; i < a; i++)
	            {
	                char c=*(place-1)+i;
	                printf("%c",c);
	            }
		    }
		    else if((*(place-1) <='9'&&*(place-1) >='0')&&(*(place+1) <='9'&&*(place+1) >='0'))
		    {
		    	*place='\0';
	            printf("%s",first);
	            for (i = 1; i < *(place+1)-*(place-1); i++)
	            {
	                char c=*(place-1)+i;
	                printf("%c",c);
	            }
	  		} 
	        else
	        {
	        	trans=strchr(place+1,'-');
	        	if(trans==NULL)
	        	{
	        		printf("%s",first);
	        		return 0;
	        	}
	        	else
	        	{
	        		*place='\0';
	        		printf("%s%c",first,'-');
	        	}
			}
		    first=place+1;
			place=strchr(first,'-');
		}
		printf("%s",first);
	}
	else printf("%s",s);
    return 0;
}




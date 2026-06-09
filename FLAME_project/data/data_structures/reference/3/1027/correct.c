#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,w0=0,w,j=0;
	char s[105],m[105];
	gets(s);
	if(s[0]!='0')
	{
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='.')
		{
			j=i;
			w0=i;
			while(j>0)
			{
				s[j]=s[j-1];
				j--;
			}
			s[1]='.';
		}
	}
	printf("%se%d",s,w0-1);
    }
    else
    {
    	i=2;
    	while(s[i]=='0')
    	    i++;
    	w0=i-1;
    	i++;
    	s[0]=s[i-1];
    	if(s[i+1]=='\0')
    	{
    		s[1]='\0';
    		printf("%se-%d",s,w0);
		}
		else
		{
    	    while(s[i]!='\0')
    	    {
    		    s[j+2]=s[i];
    		    i++;j++;
		    }
		    s[j+2]='\0';
		    printf("%se-%d",s,w0);
		}
	}
	return 0;
}


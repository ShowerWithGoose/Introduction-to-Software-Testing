#include<stdio.h>
int main()
{
	char s[1000],a[1000];
	gets(s);
	int i=0,j=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i+1]!='-')
		{
		a[j]=s[i];
		j++;
	    }
	    else if((s[i]>='0'&&s[i+2]<='9')||(s[i]>='a'&&s[i+2]<='z')||(s[i]>='A'&&s[i+2]<='Z'))
	    {
	    	for(j;s[i]<s[i+2];j++)
	    	{
	    		a[j]=s[i];
	    		s[i]++;
			}
			i++;
		}
		else
		{
			a[j]=s[i];
			j++;
		}
    }
    puts(a);
    return 0;	
}




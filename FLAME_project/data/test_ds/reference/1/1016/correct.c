#include <stdio.h>
#include <string.h>
int main()
    {
    	char s[100]={'\0'},ch;
    	int i,j;
        scanf("%s",s);
    	for(i=0;i<100;i++)
    	{
    	   if(s[i]=='-'&&i>0)
    	   {
    	   	if(s[i-1]<'9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
    	   	{
    	   		for(j=1;j<(s[i+1]+'0')-(s[i-1]+'0');j++)
    	   		{
    	   			ch=s[i-1]+j;
    	   			printf("%c",ch);
				   }
			   }
			else if(s[i-1]<'z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
    	   	{
    	   		for(j=1;j<(s[i+1]+'0')-(s[i-1]+'0');j++)
    	   		{
    	   			ch=s[i-1]+j;
    	   			printf("%c",ch);
				   }
			   }
		   else if(s[i-1]<'Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
    	   	{
    	   		for(j=1;j<(s[i+1]+'0')-(s[i-1]+'0');j++)
    	   		{
    	   			ch=s[i-1]+j;
    	   			printf("%c",ch);
				   }
			   }
		   else printf("-");
		   
		}
		else printf("%c",s[i]);
	}	
	return 0;
}


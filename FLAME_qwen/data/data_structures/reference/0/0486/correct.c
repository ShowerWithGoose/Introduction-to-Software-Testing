#include<stdio.h>
char s[1000];
int main()
{
    int i,k,n,temp=1;
	scanf("%s",s);
    for(i=0;s[i]!='\0';i++)
    {
    	if(s[i]=='-')
    	{
    		k=i;
    		k--;
    		if(s[k]>='0'&&s[k]<='9')
    		{
    			if(s[k+2]>='0'&&s[k+2]<='9'&&s[k+2]>s[k])
    			{
    				n=s[k+2]-s[k];
    				n--;
    				for(temp=1;n>0;n--,temp++)
    				{
    					printf("%c",(s[k]+temp));
					}
				}
				else
				{
					printf("-");
				}
			}
			else if(s[k]>='a'&&s[k]<='z')
			{
				if(s[k+2]>='a'&&s[k+2]<='z'&&s[k+2]>s[k])
				{
					n=s[k+2]-s[k];
    				n--;
    				for(temp=1;n>0;n--,temp++)
    				{
    					printf("%c",(s[k]+temp));
					}
				}
				else
				{
					printf("-");
				}
			}
			else if(s[k+2]>='A'&&s[k+2]<='Z'&&s[k+2]>s[k])
			{
				n=s[k+2]-s[k];
    				n--;
    				for(temp=1;n>0;n--,temp++)
    				{
    					printf("%c",(s[k]+temp));
					}
			}
			else
				{
					printf("-");
				}
		}
		else
		{
			printf("%c",s[i]);
		}
	}
	return 0;
	
}




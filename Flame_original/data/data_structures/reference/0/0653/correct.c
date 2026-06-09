#include <stdio.h> 
#include<string.h>
int main ()
{
	char s[1000];
	gets(s);
	int len=strlen(s),i,j;
	for(i=0;i<=len-1;i++)
	{
		if(s[i]=='-')
		{
		  if(s[i-1]>='a'&&s[i-1]<='z')
		    {
			   if(s[i+1]>s[i-1]&&s[i+1]<='z')
			    {
				   for(j=s[i-1]+1;j<=s[i+1]-1;j++)
				   printf("%c",j);
				}
				else printf("-");
			}
		 else if(s[i-1]>='0'&&s[i-1]<='9')
		    {
			    if(s[i+1]>s[i-1]&&s[i+1]<='9')
			    {
				   for(j=s[i-1]+1;j<=s[i+1]-1;j++)
				   printf("%c",j);
				}
				else printf("-");
			
			}
		  else if(s[i-1]>='A'&&s[i-1]<='Z')
		    {
			  if(s[i+1]>s[i-1]&&s[i+1]<='Z')
			    {
				   for(j=s[i-1]+1;j<=s[i+1]-1;j++)
				   printf("%c",j);
				}
				else printf("-");
			
			}
		
		}
		else printf("%c",s[i]);
	}
	
    return 0;
} 






#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,k,n;
	char s[100];
    gets(s); 
	for(i=0;i<strlen(s);i++)
	{
	   if(s[i]=='-')
	   {
	   	if((s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>s[i-1]&&s[i+1]<='Z')||(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>s[i-1]&&s[i+1]<='z')||(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>s[i-1]&&s[i+1]<='9'))
	   	 {
		   for(n=s[i-1]+1;n<s[i+1];n++)
	       {
	  	    printf("%c",n);
	       }	
		 }
		 else
		 printf("-");
	   }
	   else
	   {
	   	 printf("%c",s[i]); 
	   }
	}
	return 0;
}




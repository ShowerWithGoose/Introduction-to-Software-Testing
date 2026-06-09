#include<stdio.h>
#include<string.h>
char s[1000];
int a[1000]={0};
char n[1000];
int t; 
int main()
{
	gets(s);
	for(int i=1;i<strlen(s);i++)
	{
		if(s[i]=='-'&&(s[i+1]-s[i-1]>=2)&&((s[i-1]>='0'&&s[i+1]<='9')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')))
	     
	          a[i-1]=s[i+1]-s[i-1];
		}	
		for(int i=0,y=0;i<strlen(s);i++,y++)
		{
			
			if(a[i]==0)
			{
				n[y]=s[i];
			}
			else
			{
				for(int j=0;j<a[i];j++)
				 
				 {
				  n[y]=s[i]+j;	 
				  y++;	  
			 }
			 i=i+1;
			y=y-1;
			}
			
		}
	puts(n);
	
	return 0;
}


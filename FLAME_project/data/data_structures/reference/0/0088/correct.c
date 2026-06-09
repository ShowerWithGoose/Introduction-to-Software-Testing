#include<stdio.h>
#include<string.h>
int main()
{
	char in[100],c;
	gets(in);
	int i,j=0;
	for(i=0;in[i]!='\0';i++)
	{
		if(in[i]!='-')
		{
		  printf("%c",in[i]);
		  
		}
		
		if(in[i]=='-')
		{
		  
		  if(in[i-1]>='0'&&in[i-1]<='9'&&in[i+1]>='0'&&in[i+1]<='9')
		    for(c=in[i-1]+1;c<in[i+1];c++)
		   {
			printf("%c",c);
			
		   }
		  else if(in[i-1]>='a'&&in[i-1]<='z'&&in[i+1]>='a'&&in[i+1]<='z')
		   for(c=in[i-1]+1;c<in[i+1];c++)
		   {
			printf("%c",c);
			
		   }
		   else if(in[i-1]>='A'&&in[i-1]<='Z'&&in[i+1]>='A'&&in[i+1]<='Z')
		   for(c=in[i-1]+1;c<in[i+1];c++)
		   {
			printf("%c",c);
			
		   }
		   else
		   printf("-");
		   
		}
		
		
		
	}
	
	return 0;
	
	
	
	
}


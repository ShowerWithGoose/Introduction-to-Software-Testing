#include <stdio.h>
#include <string.h>
	char a[200];
	int len;
int main()
{
   
	gets(a);
	int now=1;
	 len=strlen(a);
	 while(now<=len)
	 {    if(a[now-1]=='-')
	 {
	 	    if(a[now-2]>=a[now])
	 	    {
	 	    	printf("-");now++;continue;
			 }
			 else
			 {
			 	  char p,q;
			 	  p=a[now-2];
			 	  q=a[now];
			 	  if(!((p>='0'&&q<='9')||(p>='a'&&q<='z')||(p>='A'&&q<='Z')))
			 	  {
			 	  	printf("-");now++;
			 	  	continue;
				   }
				   else
				   {
				   	    char k=a[now-2]+1;
				   	    while(k<=a[now])
				   	    {
				   	    	printf("%c",k);
				   	    	k++;
						   }
						 now+=2;
				   }
			 }
	 }
	 	  if(a[now]!='-') 
	 	  {
	 	  	printf("%c",a[now-1]);
	 	  	now++;
	 	  	continue;
		   }
		   else
		   {
		   	     char ch=a[now-1];
		   	     char sh=a[now+1];
		   	     if(ch>=sh) 
		   	     {
		   	     	printf("%c",a[now-1]);
		   	     	now++;
		   	     	continue;
					}
				 else
				 {
				 	  if(!((ch>='0'&&sh<='9')||(ch>='A'&&sh<='Z')||(ch>='a'&&sh<='z')))
				 	  {
				 	  	  printf("%c",a[now-1]);
				 	  	  now++;
				 	  	  continue;
					   }
					   else
					   {
					   	   char k=ch;
					   	   while(k<=sh)
					   	   {
					   	   	printf("%c",k);
					   	   	k++;
							  }
							  now+=3;
					   }
				 }
		   }
	 }
 } 


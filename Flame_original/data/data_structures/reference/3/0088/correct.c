#include<stdio.h>
#include<string.h>
#define size 100
int main()
{
	 char in[size],op='+';
	 fgets(in,size,stdin);
	 int i,j,k=0;
	 if(in[0]>'0')
	    {
	
	 	for(i=0;in[i]!='\0';i++)
	 	{
	 		k++;
			 if(in[i]=='.')
	 		{
	 			for(;in[i]!='\0';i++)
				 in[i]=in[i+1];
			    break;
			}	 
			    
			}	 
		 }
	 if(in[0]=='0')
	  {
	  op='-'; 
	  for(i=0;in[i]!='\0';i++)
	  {
	  	if(in[i]>'0')
	  	{
	  		k=i;
	  		for(j=0;in[i]!='\0';i++,j++)
	  		in[j]=in[i];
	  		in[j]='\0';
			break;
		}
	  }
	  
	  } 
	  
	  
	   
		
	 	for(j=strlen(in);j>0;j--)
	 	{
	 		in[j]=in[j-1];
		 }
		in[strlen(in)]='\0';
	 	if(strlen(in)>1)
		 {
		 in[0]=in[1];
	 	in[1]='.';
	 	}
	 	if(strlen(in)<=4&&in[1]=='.')
	 	in[1]='\n';
		 for(i=0;in[i]!='\n';i++)
	 	printf("%c",in[i]);
	 	if(op=='-')
	 	printf("e%c%d",op,k-1);
		 else
		 printf("e%d",k-2) ;
	 	
	 
	 
	
	
	
	
	
 } 




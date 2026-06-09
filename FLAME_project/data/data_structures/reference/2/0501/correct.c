#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char shi[1000];
int shu[800];
int op[500];
int i,j,len,result;
int rank=1;
int main() {
   scanf("%[^=]s",shi);
   len=strlen(shi);
   for(i=0;i<len;i++)
   {
   	   if(shi[i]!=' ') shi[j++]=shi[i];
   }
   shi[j]='\0';
   len=strlen(shi);  
   for(i=0;i<len;i++)
   {
   	   if(shi[i]<='9'&&shi[i]>='0')
   	   {
   	   	  shu[rank]=shu[rank]*10+shi[i]-'0';
		  }
		else
		{			
			if(shi[i]=='*') op[rank]=1;
			else if(shi[i]=='/') op[rank]=2;
			else if(shi[i]=='+') op[rank]=3;
			else if(shi[i]=='-') op[rank]=4;
			else printf("err\n");
			rank++;
		}
   }
   for(i=1;i<rank;i++)
   {
   	if(op[i]==4)
   	{
   		shu[i+1]=-shu[i+1];
	   }
   }
   for(i=1;i<rank;i++)
   {
   	   if(op[i]==1)
   	   {
   	   	    shu[i+1]=shu[i]*shu[i+1];
   	   	    shu[i]=0;
   	   	}
   	   	else if(op[i]==2)
   	   	{
   	   		shu[i+1]=shu[i]/shu[i+1];
   	   		shu[i]=0;
			  }
   }
   for(i=1;i<=rank;i++)
   {
   	result+=shu[i];
   }
   printf("%d",result);
   return 0; 	
}




#include<stdio.h>
#include<string.h>
int main()
{
	char num[102];
	int p,pn,pd,pp;
	scanf("%s",&num);
	for(p=0;p<strlen(num);p++)
	{
		if(num[p]=='.')   break;
	}
     if(p>=1&&num[0]!='0')
     {
     	printf("%c",num[0]); 
     	if(strlen(num)!=1)  printf(".") ;
     	for(pn=1;pn<strlen(num);pn++)
     	{
     		if(num[pn]!='.')  printf("%c",num[pn]);
		 }
		 printf("e%d",p-1);
	 }
	  if(p==1&&num[0]=='0')
	  {
	  	for(pd=0;pd<strlen(num);pd++)
	  	{
	  		if(num[pd]=='.')  pp=pd;
	  		if(num[pd]!='0'&&num[pd]!='.')
	  		{
	  		   printf("%c",num[pd]);
	  		   break;
	     	}
		  }
		  if(strlen(num)!=pd+1)  printf(".");
		  for(int a=pd+1;a<strlen(num);a++)
		  {
		  	printf("%c",num[a]);
		  }
		  printf("e%d",pp-pd);
	  }
	 return 0;
 } 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
char c[10000005];
int x[10000];
char y[10000];
int main()
{
 int i,k,j,s,n;
 k=0;n=0;
 gets(c);
 for(i=0;c[i]!='\0';i++)
 {
 	if((c[i]>='0')&&(c[i]<='9')) k=c[i]-'0'+k*10;
 	if((c[i]=='+')||(c[i]=='-')||(c[i]=='*')||(c[i]=='/')||(c[i]=='=')) 
 	  {
 	  	x[n]=k;
 	  	y[n]=c[i]; 	  	k=0;n++;
	   }
 }
 for(i=0;i<n;i++)
 {
 	if(y[i]=='*')
 	{
 		y[i]='0';
 		x[i]=x[i]*x[i+1];
 		j=i;
 		while(y[j]=='0')
 		 {
 		 	x[j]=x[i];
 		 	j++;
		  }
		x[j]=x[i];
		j=i;
 		while(y[j]=='0')
 		 {
 		 	x[j]=x[i];
 		 	j--;
		  }
	 }
	 if(y[i]=='/')
 	{
 		y[i]='0';
 		x[i]=x[i]/x[i+1];
 		j=i;
 		while(y[j]=='0')
 		 {
 		 	x[j]=x[i];
 		 	j++;
		  }
		x[j]=x[i];
		j=i;
 		while(y[j]=='0')
 		 {
 		 	x[j]=x[i];
 		 	j--;
		  }
	 }	  
 }
  for(i=0;i<n;i++)
 {
 	if(y[i]=='+')
 	{
 		y[i]='0';
 		x[i]=x[i]+x[i+1];
 		j=i;
 		while(y[j]=='0')
 		 {
 		 	x[j]=x[i];
 		 	j++;
		  }
		x[j]=x[i];
		j=i;
 		while(y[j]=='0')
 		 {
 		 	x[j]=x[i];
 		 	j--;
		  }
	 }
	 if(y[i]=='-')
 	{
 		y[i]='0';
 		x[i]=x[i]-x[i+1];
 		j=i;
 		while(y[j]=='0')
 		 {
 		 	x[j]=x[i];
 		 	j++;
		  }
	    x[j]=x[i];	  
		j=i;
 		while(y[j]=='0')
 		 {
 		 	x[j]=x[i];
 		 	j--;
		  }
	 }	  
 }
 printf("%d",x[0]);
 return 0;
}





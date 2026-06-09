#include<stdio.h>
#include<math.h>
#include<string.h>
char x2[200];
int main()
{
char x1[100];
scanf("%s",x1);
int i=0,j=0,m,n,k;
m=strlen(x1)-1;
for(i==0;i<=m;i++)
 {
 if(x1[i]!='-')
  {
  x2[j]=x1[i];
  j++;	
  }	
 else if(x1[i]=='-') 	
  {
  if(x1[i-1]<='Z'&&x1[i-1]>='A'&&x1[i+1]<='Z'&&x1[i+1]>='A'&&x1[i-1]<x1[i+1])
   {	
   n=x1[i+1]-x1[i-1];
   k=1;
   for(k=1;k<n;k++)
    {
    x2[j]=x2[j-1]+1;
	j++;	
	}
   }
  else if(x1[i-1]<='z'&&x1[i-1]>='a'&&x1[i+1]<='z'&&x1[i+1]>='a'&&x1[i-1]<x1[i+1])
   {	
   n=x1[i+1]-x1[i-1];
   k=1;
   for(k=1;k<n;k++)
    {
    x2[j]=x2[j-1]+1;
	j++;	
	} 		
   }
  else if(x1[i-1]<='9'&&x1[i-1]>='0'&&x1[i+1]<='9'&&x1[i+1]>='0'&&x1[i-1]<x1[i+1])
   {	
   n=x1[i+1]-x1[i-1];
   k=1;
   for(k=1;k<n;k++)
    {
    x2[j]=x2[j-1]+1;
	j++;	
	}   	
   }
  else
   {
   x2[j]=x1[i];
   j++;	
   } 	
  }	
 }
puts(x2);
return 0; 
}




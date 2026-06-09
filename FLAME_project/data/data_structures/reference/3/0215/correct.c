#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
void wr();
int ws(int q);
char c[10000005];
int main()
{
 int n;
 gets(c);
 if(c[1]=='.') n=ws(0);
   else n=ws(1);
   printf("e%d",n);
 return 0;
}

int ws(int q)
{
	int i,j,k;
	i=0;
	if(q==0)
	 {
	   while((c[i]=='0')||(c[i]=='.'))  i++;
       if((c[0]=='0')&&(i==strlen(c)-1))
       {
       	i--;
		printf("%c",c[i+1]);
		return 0-i;
	   }
	   printf("%c.",c[i]);
	   for(j=i+1;c[j]!='\0';j++) 
	   {
	    if(c[j]=='.') continue;
		   else printf("%c",c[j]);
       }
       if(c[0]=='0') i--;
	   return 0-i;
	 }
	 if(q==1)
	 {
	   while(c[i]!='.') i++;
	   printf("%c.",c[0]);
	   for(j=1;c[j]!='\0';j++) 
	   {
	   if(c[j]=='.') continue;
	                 else printf("%c",c[j]);
       }
	   return i-1;
	 }
}	


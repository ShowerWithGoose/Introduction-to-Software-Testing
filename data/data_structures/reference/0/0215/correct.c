#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
char c[10000005];
int main()
{
 int i,k,j;
 gets(c);
 for(i=0;c[i]!=0;i++)
 {
 	if(c[i]=='-')
 	 {
 	 	if(((c[i-1]>='0')&&(c[i+1]<='9'))||((c[i-1]>='a')&&(c[i+1]<='z'))||((c[i-1]>='A')&&(c[i+1]<='Z')))
 	 	 {
 	 	 	for(k=c[i-1]+1;k<c[i+1];k++)
 	 	 	printf("%c",k);
		   }
		   else printf("%c",c[i]);
	  }
	else printf("%c",c[i]);  
 }
 return 0;
}





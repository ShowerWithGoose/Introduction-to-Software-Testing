#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
	  char a[100];
	  gets(a);
	  int i=0;
	  for(i=0;i<strlen(a);i++){
	  	if(a[i]=='-'){
		  if(a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>a[i-1])
		  for(char c=a[i-1]+1;c<a[i+1];c++)
		  printf("%c",c);
		  
		  else if(a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>a[i-1])
		  for(char c=a[i-1]+1;c<a[i+1];c++)
		  printf("%c",c);
		  
		  else if(a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>a[i-1])
		  for(char c=a[i-1]+1;c<a[i+1];c++)
		  printf("%c",c);
		  
		   else printf("%c",a[i]);
	  }
	  else printf("%c",a[i]);
	  }
return 0;
}



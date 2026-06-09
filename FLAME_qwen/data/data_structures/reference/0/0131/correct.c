#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1024
int main()
{
 int i=0,j=0,k=0;
  char s[max]={'\0'};
 char t;
 scanf("%s",s);
 //gets(s);
 for(i=0;s[i]!='\0';i++){	 
 	if(s[i]=='-'){
 	if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
 	{
 	for(t=s[i-1]+1;t<s[i+1];t++){
 	printf("%c",t );
	 }
	 }
	else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
 	{
 	for(t=s[i-1]+1;t<s[i+1];t++){
 	  printf("%c",t );
	 }
	 } 
    else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
 	{
 	for(t=s[i-1]+1;t<s[i+1];t++){
	 printf("%c",t );
	 }
	 }
    else{
    t=s[i];
	printf("%c",t);
	}
}
    else{
    t=s[i];
	printf("%c",t);
	}
}

return 0;
}


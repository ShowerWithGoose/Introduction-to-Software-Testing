#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100000
int main()
{	
   char s[M];
   char s1[M];
   gets(s);
   int i,k,j;
   for(i=0;i<strlen(s);i++){
   	   if(s[i]!='-')  printf("%c",s[i]);
	   else{
   		int q=i-1; 
   		int p=i+1;
   		if('0'<=s[q]&&s[q]<='9'&&'0'<=s[p]&&s[p]<='9'){
   			for(j=s[q]+1;j-s[p]<0;j++){
   				printf("%c",j);
			   }
		   }
		else if('a'<=s[q]&&s[q]<='z'&&'a'<=s[p]&&s[p]<='z'){
   			for(j=s[q]+1;j-s[p]<0;j++){
   				printf("%c",j);
			   }
		   }
		else if('A'<=s[q]&&s[q]<='Z'&&'A'<=s[p]&&s[p]<='Z'){
   			for(j=s[q]+1;j-s[p]<0;j++){
   				printf("%c",j);
			   }
		   }
		   else printf("%c",s[i]);  
	   }
   }
    return 0;
}



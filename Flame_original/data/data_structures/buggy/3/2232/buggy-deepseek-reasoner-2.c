#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
    char s[1000];    
int main(){
   fgets(s,1000,stdin);
int i,j,mark=0;
for(i=0,j=i;s[i+1]!='\0';i++){ // @@ [Loop condition is unconventional and after loop the index i ends one past the last processed character, leading to incorrect null-termination later. Also, the loop does not properly handle the newline from fgets.]
    if(s[i]=='.'){
     mark=i;        
    }else{
    s[j++]=s[i];    
    }
}
if(mark==0){
    printf("%s",s);
}else{
    s[i]='\0'; // @@ [Should set s[j]='\0' instead of s[i]. This leaves duplicate characters in the string (characters from j to i-1 remain), causing incorrect output.]
    if(s[0]!='0'){
        printf("%c.",s[0]);
       for(i=1;i<strlen(s)-1;i++){ // @@ [Using strlen(s)-1 is incorrect because the string has not been properly null-terminated; the loop may include duplicate characters.]
        printf("%c",s[i]);
       }
     printf("e%d",mark-1);
    }else{
       int count=1;
       for(i=1;i<strlen(s)-1;i++){ // @@ [Same issue with strlen(s)-1; the loop may include extra characters from the buggy null-termination.]
          if(s[i]=='0'){
            count++;
          }else{
        printf("%c",s[i]);
            break;
          }
       }

      if(s[++i]!='\0'){ // @@ [This check does not guarantee that the next character is a digit; due to the duplicate string, it may cause an unnecessary dot.]
        printf(".");
        for(;i<strlen(s)-1;i++){ // @@ [Again, strlen(s)-1 is unreliable.]
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count);    
  }
}
return 0;
}
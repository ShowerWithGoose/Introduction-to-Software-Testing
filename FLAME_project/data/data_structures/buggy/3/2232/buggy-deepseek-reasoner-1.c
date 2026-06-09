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
for(i=0,j=i;s[i+1]!='\0';i++){ // @@ Using s[i+1]!='\0' includes the newline character from fgets, causing the loop to process it as a digit and leading to an extra character in the string.
    if(s[i]=='.'){
     mark=i;        
    }else{
    s[j++]=s[i];    
    }
}
if(mark==0){
    printf("%s",s);
}else{
    s[i]='\0'; // @@ Null terminator should be placed at s[j] (the end of the new string after removing dots), not at s[i] (which may leave duplicate characters and wrong length).
    if(s[0]!='0'){
        printf("%c.",s[0]);
       for(i=1;i<strlen(s)-1;i++){ // @@ Loop condition i < strlen(s)-1 is off‑by‑one; it should be i < strlen(s) to include the last character. Also, this loop does not skip the original dot character, so it prints the dot again.
        printf("%c",s[i]);
       }
     printf("e%d",mark-1);
    }else{
       int count=1;
       for(i=1;i<strlen(s)-1;i++){ // @@ Same off‑by‑one error: condition should be i < strlen(s) to include the last digit.
          if(s[i]=='0'){
            count++;
          }else{
        printf("%c",s[i]);
            break;
          }
       }

      if(s[++i]!='\0'){ // @@ This increments i before the check, potentially skipping a digit; it should check s[i+1] without modifying i.
        printf(".");
        for(;i<strlen(s)-1;i++){ // @@ Again off‑by‑one: should be i < strlen(s).
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count);    
  }
}
return 0;
}
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
for(i=0,j=i;s[i+1]!='\0';i++){
    if(s[i]=='.'){
     mark=i;        
    }else{
    s[j++]=s[i];    
    }
}
if(mark==0){
    printf("%s",s);
}else{
    s[i]='\0';
    if(s[0]!='0'){
        printf("%c.",s[0]);
       for(i=1;i<strlen(s)-1;i++){ // @@ The condition `i<strlen(s)-1` causes an off-by-one error, skipping the last character of the string and preventing correct processing of all digits.
        printf("%c",s[i]);
       }
     printf("e%d",mark-1);
    }else{
       int count=1;
       for(i=1;i<strlen(s)-1;i++){ // @@ Same off-by-one error; the loop should iterate until `s[i]!='\0'` or `i<strlen(s)` to correctly find the first non-zero digit.
          if(s[i]=='0'){
            count++;
          }else{
        printf("%c",s[i]);
            break;
          }
       }

      if(s[++i]!='\0'){ // @@ Incrementing `i` before checking may skip a valid digit or access out of bounds, and combined with loop bounds causes a trailing decimal point when no fractional digits exist.
        printf(".");
        for(;i<strlen(s)-1;i++){ // @@ Off-by-one error prevents printing the remaining fractional digits after the decimal point.
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count);    
  }
}
return 0;
}
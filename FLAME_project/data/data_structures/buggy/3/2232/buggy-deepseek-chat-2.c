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
       for(i=1;i<strlen(s)-1;i++){
        printf("%c",s[i]);
       }
     printf("e%d",mark-1);
    }else{
       int count=1;
       for(i=1;i<strlen(s)-1;i++){
          if(s[i]=='0'){
            count++;
          }else{
        printf("%c",s[i]);
            break;
          }
       }

      if(s[++i]!='\0'){ // @@ The increment of i here skips the first non-zero digit, causing the decimal part to start from the wrong position. For input "0.9", after the loop, i points to '9', then ++i makes i point to '\0', so the condition fails and the decimal part is not printed.
        printf(".");
        for(;i<strlen(s)-1;i++){
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count); // @@ The exponent should be count (the number of zeros after the decimal point), but for "0.9", count is 1, giving "e-1" instead of "e-1". However, the base is missing the '9' before the decimal point. The issue is that the non-zero digit '9' is printed in the loop but not stored, and the decimal part logic is flawed.
  }
}
return 0;
}
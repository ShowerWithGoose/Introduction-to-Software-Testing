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
        printf("%c",s[i]); // @@ This prints the first non-zero digit but does not handle the case where the number is like "0.9" correctly; it should print the digit and then handle the decimal point and exponent properly.
            break;
          }
       }

      if(s[++i]!='\0'){ // @@ This increments i after the break, but i may already be at the correct position; also, the condition checks s[++i] which skips the current digit and may go out of bounds or miss characters.
        printf(".");
        for(;i<strlen(s)-1;i++){
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count); // @@ The exponent should be count (the number of zeros after the decimal point), but for input "0.9", count becomes 1, which is correct, but the output format is missing the base digit before 'e'.
  }
}
return 0;
}
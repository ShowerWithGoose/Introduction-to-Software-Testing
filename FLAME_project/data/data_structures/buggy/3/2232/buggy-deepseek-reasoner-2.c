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
    s[i]='\0'; // @@ Error: Should be s[j]='\0' to properly terminate the new string; using s[i] may leave extra characters or fail to null-terminate at the correct position.
    if(s[0]!='0'){
        printf("%c.",s[0]);
       for(i=1;i<strlen(s)-1;i++){
        printf("%c",s[i]);
       }
     printf("e%d",mark-1);
    }else{
       int count=1;
       for(i=1;i<strlen(s)-1;i++){ // @@ Error: Loop condition should be i<strlen(s) to include the last digit; using i<strlen(s)-1 skips the digit after the decimal point when there is no trailing newline, causing no digit to be printed before the exponent.
          if(s[i]=='0'){
            count++;
          }else{
        printf("%c",s[i]);
            break;
          }
       }

      if(s[++i]!='\0'){ // @@ Error: Using ++i modifies i and may lead to off-by-one; should check s[i+1] without incrementing to properly determine if there are more digits to print as fractional part.
        printf("."); // @@ Error: Prints a decimal point even when there are no fractional digits after the first non-zero digit; should only be printed if additional digits exist.
        for(;i<strlen(s)-1;i++){
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count);    
  }
}
return 0;
}
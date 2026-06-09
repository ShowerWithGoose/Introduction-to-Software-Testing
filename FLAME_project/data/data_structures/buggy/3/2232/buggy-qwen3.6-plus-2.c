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
        printf("%c",s[i]); // @@ The logic fails to print the decimal point and subsequent digits correctly for inputs like 0.9. When the first non-zero digit is found (e.g., '9'), it prints the digit but breaks. The subsequent block checks s[++i], which moves past the current digit. For "0.9", after stripping '.', s is "09". i=1, s[1]='9'. It prints '9'. Then i becomes 2 in the loop increment or via ++i. The condition s[++i] checks s[2] which is '\0' (or end of string). So it doesn't print ".". Also, the exponent calculation 'count' is 1, so it prints e-1. But the base is just "9". The expected output is "9e-1". Wait, if it prints "9" and then "e-1", the output is "9e-1". Let's re-trace.
        // Input: 0.9\n. fgets keeps \n? Usually yes.
        // Loop 1: i=0, s[0]='0', j=0. s[0]!='.' -> s[0]='0', j=1.
        // i=1, s[1]='.', mark=1.
        // i=2, s[2]='9', s[3]='\n' or '\0'. If \n, s[4]='\0'.
        // s[2]!='.' -> s[1]='9', j=2.
        // i=3, s[3]='\n' or '\0'. Loop ends if s[i+1] is null? No, condition is s[i+1]!='\0'.
        // If input is "0.9\n", s="0.9\n\0".
        // i=0: s[1]='.' != '\0'. s[0]='0'->s[0]='0', j=1.
        // i=1: s[2]='9' != '\0'. s[1]='.' -> mark=1.
        // i=2: s[3]='\n' != '\0'. s[2]='9'->s[1]='9', j=2.
        // i=3: s[4]='\0'. Loop terminates.
        // s[3] = '\0'. s is now "09\0". mark=1.
        // s[0]=='0'. Enter else.
        // count=1.
        // Loop: i=1. strlen(s)=2. i < 1? No. 1 < 1 is false.
        // The loop `for(i=1;i<strlen(s)-1;i++)` does not execute because strlen(s) is 2, so 2-1=1. i=1, 1<1 is false.
        // So nothing is printed inside the loop.
        // Then `if(s[++i]!='\0')`. i was 1. ++i makes i=2. s[2] is '\0'. Condition false.
        // So nothing more printed.
        // Then `printf("e-%d",count)`. Prints "e-1".
        // Total output: "e-1".
        // Expected: "9e-1".
        // The error is that the digit '9' was not printed.
        // The loop condition `i < strlen(s)-1` excludes the last character of the significant part if it's the only one or at the end.
        // In "09", the '9' is at index 1. strlen(s)-1 is 1. The loop runs for i < 1. So i=1 is skipped.
        // The digit '9' is missed.
            break;
          }
       }

      if(s[++i]!='\0'){
        printf(".");
        for(;i<strlen(s)-1;i++){
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count);    
  }
}
return 0;
}
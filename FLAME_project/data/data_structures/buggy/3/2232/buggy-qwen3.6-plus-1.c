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
        printf("%c",s[i]); // @@ The logic fails to print the decimal point and subsequent digits if the significant digit is the last character in the stripped string (e.g., "0.9" becomes "9", loop doesn't run or breaks immediately without handling the "integer" case correctly for single digit). Specifically, for "0.9", s becomes "9". The loop `for(i=1; ...)` does not execute because strlen("9")-1 is 0, so i=1 is not < 0. Then it checks `if(s[++i]!='\0')`. i becomes 2. s[2] is '\0'. So it skips printing "." and remaining digits. It only prints "9" then "e-1". Wait, looking at the trace: Input "0.9\n". mark=1. Loop strips dot: s[0]='0', s[1]='9'. j moves. s becomes "09". i ends at 2 (index of \n or \0 depending on fgets). s[i]='\0' makes s="09". s[0]=='0'. count=1. Loop `for(i=1; i<strlen("09")-1; i++)` -> `i<1`. Loop doesn't run. `if(s[++i]!='\0')` -> i becomes 2. s[2] is '\0'. Condition false. Prints "e-1". Missing the significant digit '9'.
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
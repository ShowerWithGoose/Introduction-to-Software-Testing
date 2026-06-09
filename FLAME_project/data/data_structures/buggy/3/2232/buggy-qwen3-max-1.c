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
for(i=0,j=i;s[i+1]!='\0';i++){ @@ // The loop condition skips the last character, which may be a digit or newline; this causes loss of last digit if input doesn't end with newline or misprocessing.
    if(s[i]=='.'){
     mark=i;        
    }else{
    s[j++]=s[i];    
    }
}
if(mark==0){
    printf("%s",s);
}else{
    s[i]='\0'; @@ // This truncates the string at index i, but i is at the position before the last character due to loop condition; may drop last digit.
    if(s[0]!='0'){
        printf("%c.",s[0]);
       for(i=1;i<strlen(s)-1;i++){ @@ // Using strlen(s)-1 here is incorrect because s was already truncated and original digits after '.' may be lost; also, -1 may skip valid digits.
        printf("%c",s[i]);
       }
     printf("e%d",mark-1);
    }else{
       int count=1;
       for(i=1;i<strlen(s)-1;i++){ @@ // Same issue: strlen(s)-1 may skip the last significant digit.
          if(s[i]=='0'){
            count++;
          }else{
        printf("%c",s[i]);
            break;
          }
       }

      if(s[++i]!='\0'){ @@ // After breaking from loop, i points to first non-zero; ++i skips it, so decimal part starts from next digit, possibly missing digits or causing out-of-bound access.
        printf(".");
        for(;i<strlen(s)-1;i++){ @@ // Again, -1 may skip last digit; also, if s was truncated incorrectly earlier, this may not reflect original input.
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count);    
  }
}
return 0;
}
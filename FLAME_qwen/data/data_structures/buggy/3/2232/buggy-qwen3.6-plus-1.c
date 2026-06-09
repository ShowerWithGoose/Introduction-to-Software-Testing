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
for(i=0,j=i;s[i+1]!='\0';i++){ // @@ The loop condition s[i+1]!='\0' stops before processing the last character, which is then overwritten by s[i]='\0';, causing data loss if the input does not end with a newline. It should be s[i]!='\0'.
    if(s[i]=='.'){
     mark=i;        
    }else{
    s[j++]=s[i];    
    }
}
if(mark==0){
    printf("%s",s);
}else{
    s[i]='\0'; // @@ This overwrites the last character of the string. After fixing the loop condition, the string should be properly terminated at s[j]='\0'; instead.
    if(s[0]!='0'){
        printf("%c.",s[0]);
       for(i=1;i<strlen(s)-1;i++){ // @@ The condition i<strlen(s)-1 incorrectly skips the last character of the string. It should be i<strlen(s).
        printf("%c",s[i]);
       }
     printf("e%d",mark-1);
    }else{
       int count=1;
       for(i=1;i<strlen(s)-1;i++){ // @@ Same error as above, skips the last character. Should be i<strlen(s).
          if(s[i]=='0'){
            count++;
          }else{
        printf("%c",s[i]);
            break;
          }
       }

      if(s[++i]!='\0'){
        printf(".");
        for(;i<strlen(s)-1;i++){ // @@ Same error as above, skips the last character. Should be i<strlen(s).
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count);    
  }
}
return 0;
}
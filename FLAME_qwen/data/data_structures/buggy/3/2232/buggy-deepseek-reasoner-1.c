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
for(i=0,j=i;s[i+1]!='\0';i++){ // @@ loop condition should be s[i]!='\0' to process all characters; using s[i+1] misses the last character if no newline is present after the number.
    if(s[i]=='.'){
     mark=i;        
    }else{
    s[j++]=s[i];    
    }
}
if(mark==0){
    printf("%s",s);
}else{
    s[i]='\0'; // @@ should be s[j]='\0' to correctly terminate the string at the position of the last copied character; otherwise duplicate digits remain from the original array.
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
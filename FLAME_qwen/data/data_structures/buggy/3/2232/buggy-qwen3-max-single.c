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
for(i=0,j=i;s[i+1]!='\0';i++){ @@ [Loop condition skips last character; should check s[i] != '\0' to process entire string including last digit]
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
       for(i=1;i<strlen(s)-1;i++){ @@ [Incorrect loop bound: strlen(s)-1 may skip last digit due to prior truncation and off-by-one error]
        printf("%c",s[i]);
       }
     printf("e%d",mark-1);
    }else{
       int count=1;
       for(i=1;i<strlen(s)-1;i++){ @@ [Same incorrect bound: should be i < strlen(s) or adjusted logic to include all digits]
          if(s[i]=='0'){
            count++;
          }else{
        printf("%c",s[i]);
            break;
          }
       }

      if(s[++i]!='\0'){ @@ [Undefined behavior if loop ended because i reached strlen(s)-1; s[i] may be out of bounds]
        printf(".");
        for(;i<strlen(s)-1;i++){ @@ [Again, incorrect bound skips last character]
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count);    
  }
}
return 0;
}
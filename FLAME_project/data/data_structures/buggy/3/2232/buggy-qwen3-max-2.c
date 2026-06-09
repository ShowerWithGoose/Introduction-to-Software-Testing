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
for(i=0,j=i;s[i+1]!='\0';i++){ @@ // The loop condition skips the last character, which may be a digit; this causes loss of the last digit when input has no newline or when newline is at end.
    if(s[i]=='.'){
     mark=i;        
    }else{
    s[j++]=s[i];    
    }
}
if(mark==0){
    printf("%s",s);
}else{
    s[i]='\0'; @@ // This truncates the string incorrectly because 'i' is at the position before '\0', but due to loop condition s[i+1]!='\0', 'i' stops one short, so s[i] might not be the correct place to null-terminate.
    if(s[0]!='0'){
        printf("%c.",s[0]);
       for(i=1;i<strlen(s)-1;i++){ @@ // Using strlen(s)-1 here is incorrect because s was already truncated and doesn't account for original length properly; also, it may skip last digit.
        printf("%c",s[i]);
       }
     printf("e%d",mark-1);
    }else{
       int count=1;
       for(i=1;i<strlen(s)-1;i++){ @@ // Same issue: strlen(s)-1 is wrong after truncation and leads to skipping digits.
          if(s[i]=='0'){
            count++;
          }else{
        printf("%c",s[i]);
            break;
          }
       }

      if(s[++i]!='\0'){ @@ // After breaking from loop, i points to first non-zero; incrementing again skips the next digit. Also, condition uses s[++i] which modifies i and may go out of bounds.
        printf(".");
        for(;i<strlen(s)-1;i++){ @@ // Again, using strlen(s)-1 incorrectly skips last character.
        printf("%c",s[i]);
         }   
       }
    printf("e-%d",count);    
  }
}
return 0;
}
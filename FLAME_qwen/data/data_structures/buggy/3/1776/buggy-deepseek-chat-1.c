#include <stdio.h>
#include <string.h>
#define eps 1e-4
int main() {
    char s[110];
    gets(s);
    int len =strlen(s);
    int i=0,j=0;
    for( i=0; i<len; i++) {
        if(s[i]=='.')
        break;
    }
    int len1=len-i-1;//hou mian you ji wei
    if(i==1) {
       if(s[i-1]=='0'){  
            j=i+1;
            for( j=i+1; j<len; j++) {
            if(s[j]!='0')
            break;
            }
            printf("%c",s[j]);
        
            for(j=j+1; j<len; j++) { // @@ The loop variable j is being reused incorrectly; after the first loop, j points to the first non-zero digit, but then j is incremented again, skipping that digit in the output. Also, the loop should start from the first non-zero digit and include all remaining digits, but the decimal point is missing.
                printf("%c",s[j]);
            }
            printf("e-%d",len-i-1); // @@ The exponent calculation is incorrect; it should be based on the position of the first non-zero digit after the decimal point, not len-i-1. For example, for "0.001", the exponent should be -3, but len-i-1 gives -2.

        } 
        
         else{ 
               for(i=0; i<len; i++) {
                printf("%c",s[i]);
            }
               printf("e0");
        
        }



    }
    else
      {
        printf("%c",s[0]);
           printf(".");
               for(int c=1; c<i; c++) {
                printf("%c",s[c]);
            }
            for(int b=i+1; b<len; b++) {
                printf("%c",s[b]);
            }
            printf("e");
            printf("%d",i-1);
   }                       
    return 0;
}
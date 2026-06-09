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
        
            for(j=j+1; j<len; j++) { // @@ The variable j has been modified in the previous loop, and here j is reassigned to j+1, but the loop condition uses the same j, which may cause the loop to start from an incorrect position or skip characters. Additionally, the decimal point '.' is not printed before the fractional part.
                printf("%c",s[j]);
            }
            printf("e-%d",len-i-1); // @@ The exponent should be the number of zeros after the decimal point before the first non-zero digit, which is (j - i - 1) where j is the index of the first non-zero digit, not len-i-1. len-i-1 is the total number of digits after the decimal point, which is incorrect.

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
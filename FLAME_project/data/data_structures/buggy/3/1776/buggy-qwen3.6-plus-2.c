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
        
            for(j=j+1; j<len; j++) {
                printf("%c",s[j]);
            }
            printf("e-%d",len-i-1); // @@ The exponent calculation is incorrect for numbers less than 1. It should be -(j - 1) or similar, representing the position of the first significant digit relative to the decimal point. Specifically, for 0.00...0X, the exponent is -(number of zeros after decimal + 1). Here len-i-1 is the total number of digits after decimal, which is wrong. It should be printf("e-%d", j - 1); because j is the index of the first non-zero digit, and the exponent is -(j-1) since the decimal point was at index 1.

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
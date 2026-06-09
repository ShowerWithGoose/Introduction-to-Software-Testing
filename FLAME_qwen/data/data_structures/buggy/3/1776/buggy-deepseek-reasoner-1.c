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
            printf("%c",s[j]); // @@ Missing decimal point when there are more digits after the first non-zero digit. Should print base like "x.yz" not "xyz".
        
            for(j=j+1; j<len; j++) {
                printf("%c",s[j]); // @@ Should be preceded by a decimal point if any digits follow.
            }
            printf("e-%d",len-i-1); // @@ Exponent calculation is wrong: should be -(position of first non-zero digit - 1), not -(number of digits after decimal point). For "0.123", len-i-1=3 but exponent is -1.

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
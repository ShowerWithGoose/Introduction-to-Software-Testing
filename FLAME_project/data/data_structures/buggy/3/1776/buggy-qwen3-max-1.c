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
            printf("e-%d",len-i-1); // @@ [The exponent calculation is wrong. It should be (j - i - 1), not (len - i - 1). For input "0.00000009123...", the first non-zero digit '9' is at index 9, so exponent should be -(9 - 1) = -8, but code outputs -(len - i - 1) = -(21 - 1 - 1) = -19 or similar, which is incorrect.]

        } 
        
         else{ 
               for(i=0; i<len; i++) {
                printf("%c",s[i]);
            }
               printf("e0"); // @@ [This branch handles numbers like "5.123", but it prints the whole number and appends "e0", which violates scientific notation format. It should normalize to one digit before decimal, e.g., "5.123e0" is acceptable only if formatted as "5.123", but according to problem, base must have exactly one significant digit before decimal. However, this case may not trigger for given test, but still logically flawed. But primary error is in the zero-leading case above.]

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
            printf("%d",i-1); // @@ [This part assumes there's no leading zeros before decimal, which is valid per problem, but doesn't handle cases where integer part has more than one digit correctly in all edge cases. However, for the given failing test case, this branch isn't taken, so not the cause of the current WA. The main bug is in the exponent calculation in the leading-zero decimal case.]
   }                       
    return 0;
}
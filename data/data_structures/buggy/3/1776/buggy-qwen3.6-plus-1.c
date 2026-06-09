#include <stdio.h>
#include <string.h>
#define eps 1e-4
int main() {
    char s[110];
    gets(s); // @@ gets() is removed in the C11 standard and will cause a compilation error in modern compilers; use fgets() instead.
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
            printf("e-%d",len-i-1);

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
               for(int c=1; c<i; c++) { // @@ Declaring variables inside the for loop initialization is not allowed in C89/C90 standard, which may cause a compilation error.
                printf("%c",s[c]);
            }
            for(int b=i+1; b<len; b++) { // @@ Same as above, variable declaration in for loop is invalid in older C standards.
                printf("%c",s[b]);
            }
            printf("e");
            printf("%d",i-1);
   }
    return 0;
}
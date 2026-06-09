#include <stdio.h>
#include <string.h>
char num[110];
int main() {
    int zs=0,xs=0;
    gets(num);
    for(; (num[zs]!='.')&&(num[zs]!='\0'); zs++);
    if((zs==strlen(num))&&(strlen(num)==1))
        printf("%ce0",num[0]);
    else if(zs==strlen(num)) {
        printf("%c.",num[0]);
        for(int i=1; i<strlen(num); i++)
            printf("%c",num[i]);
        printf("e%d",strlen(num)-1);
    } else {
        for(int i=zs+1; num[i]!='\0'; i++)
            xs=i-zs;
        if(zs>=2) {
            printf("%c.",num[0]);
            for(int i=1; i<zs; i++)
                printf("%c",num[i]);
            for(int i=zs+1; i<=zs+xs; i++)
                printf("%c",num[i]);
            printf("e%d",zs-1);
        } else if(num[0]=='0') {
            int zero=0;
            for(int i=2; num[i]=='0'; i++)
                zero++;
            if(zero==xs-1)
                printf("%ce-%d",num[zs+xs],xs); // @@ Error: When all digits after decimal are zeros, this outputs only one digit without decimal point, but the expected output should have a decimal point after the first significant digit. Also, the exponent calculation is incorrect; it should be -(xs - zero) instead of -xs.
            else {
                printf("%c.",num[zero+2]); // @@ Error: This incorrectly skips the first non-zero digit. The first significant digit is at index zero+2, but it should be printed as the digit before the decimal point, not after. The exponent calculation also uses xs-zero, which is wrong; it should be -(xs - zero - 1) for numbers like 0.00000009123456789012.
                for(int i=zero+3; num[i]!='\0'; i++)
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ Error: The exponent should be -(xs - zero - 1) to account for the fact that the decimal point is moved after the first non-zero digit. For input 0.00000009123456789012, xs=14, zero=7, so xs-zero=7, but expected exponent is -8.
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
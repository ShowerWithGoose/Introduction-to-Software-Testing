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
                printf("%ce-%d",num[zs+xs],xs); // @@ [The exponent calculation is incorrect. For input 0.00000009123456789012, xs is the number of decimal places (14). The first significant digit is at index zs+xs (which is 1+13=14? No, loop logic for xs: i goes from zs+1 to end. xs becomes last_i - zs. If string is "0.00...0912", zs=1. i starts at 2. Loop runs until null. xs = (len-1) - 1 = len-2. This represents total decimal digits. zero counts leading zeros after decimal. The position of the first non-zero digit relative to the decimal point determines the exponent. If we have 0.00...0D..., the exponent is -(number of zeros + 1). Here, zero is count of '0's. The exponent should be -(zero + 1). The code uses `xs` which is total decimal digits, or `xs-zero` in the else branch. In the specific failing case 0.00000009123456789012, zs=1. The loop `for(int i=2; num[i]=='0'; i++) zero++;` will count 7 zeros. `xs` calculated above is 14 (total decimal digits). `zero` is 7. `xs-1` is 13. `zero == xs-1` is false (7 != 13). So it goes to else. It prints `num[zero+2]` which is `num[9]` ('9'). Then prints rest. Exponent printed is `e-%d`, `xs-zero` = 14-7 = 7. Expected is -8. The exponent for 0.00...09... is -(count_of_zeros + 1). Here zeros=7, so exp should be -8. The formula `xs-zero` calculates remaining digits after the first significant one? No. `xs` is total decimal digits. `zero` is leading zeros. `xs-zero` is digits from first sig digit to end. This is not the exponent. The exponent is determined by the position of the first significant digit. Position is `zero + 1` places after decimal. So exponent is `-(zero + 1)`.]
            else {
                printf("%c.",num[zero+2]);
                for(int i=zero+3; num[i]!='\0'; i++)
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ [Same error as above. The exponent calculation `xs-zero` is incorrect. It should be `-(zero + 1)` because the first significant digit is at `zero + 1` positions to the right of the decimal point.]
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
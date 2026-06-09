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
            xs=i-zs; // @@ This loop only updates xs to the last index difference, not the count of digits after decimal point. It should be xs = strlen(num) - zs - 1; or initialize xs=0 and increment inside the loop.
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
                printf("%ce-%d",num[zs+xs],xs); // @@ When zero==xs-1, the number is like 0.0...0x, but this prints only one digit without decimal point, which is incorrect. It should print the digit with "e" and exponent.
            else {
                printf("%c.",num[zero+2]); // @@ This assumes the first non-zero digit is at index zero+2, but if zero is 0, it should be num[2] (the first digit after decimal). However, for numbers like 0.123, zero=0, so zero+2=2, which is correct. But for numbers like 0.00123, zero=2, zero+2=4, which skips the '1' at index 3. Should be num[zero+2]? Actually index of first non-zero is zero+2, so this is correct.
                for(int i=zero+3; num[i]!='\0'; i++)
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ The exponent should be -(zero+1) because the decimal point is moved past the leading zeros. For 0.00123, zero=2, xs=5, xs-zero=3, but correct exponent is -3 (since 0.00123 = 1.23e-3). Actually zero+1=3, so xs-zero=3 is correct only if xs is total digits after decimal. But xs is computed incorrectly.
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
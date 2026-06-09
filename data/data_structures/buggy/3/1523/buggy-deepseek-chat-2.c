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
            xs=i-zs; // @@ This line only updates xs to the last index difference, not the count of digits after decimal point. It should be xs = strlen(num) - zs - 1; or similar to count all digits after the decimal.
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
                printf("%ce-%d",num[zs+xs],xs); // @@ This line incorrectly uses num[zs+xs] which may be out of bounds or wrong digit; also xs may be incorrect due to previous error.
            else {
                printf("%c.",num[zero+2]); // @@ This line assumes the first non-zero digit is at index zero+2, but zero counts leading zeros after decimal, so the first non-zero is at index zs+1+zero, not zero+2.
                for(int i=zero+3; num[i]!='\0'; i++) // @@ This line starts from zero+3, which is incorrect; should start from zs+1+zero+1.
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ xs may be incorrect due to earlier error.
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
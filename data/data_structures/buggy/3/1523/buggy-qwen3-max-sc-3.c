#include <stdio.h>
#include <string.h>
char num[110];
int main() {
    int zs=0,xs=0;
    gets(num); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings.]
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
            xs=i-zs; // @@ [This loop overwrites 'xs' in every iteration, so after the loop, 'xs' will be equal to (last_index - zs), not the total number of fractional digits. It should count the number of digits after the decimal point instead.]
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
                printf("%ce-%d",num[zs+xs],xs); // @@ [If all digits after the decimal are zeros except the last one, this prints only the last digit as the base, but according to problem description, trailing zeros after decimal are not present, so this case may not occur. However, indexing 'num[zs+xs]' assumes that 'xs' correctly represents the number of fractional digits, which it doesn't due to earlier error.]
            else {
                printf("%c.",num[zero+2]);
                for(int i=zero+3; num[i]!='\0'; i++)
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ ['xs' is incorrectly computed, leading to wrong exponent calculation.]
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
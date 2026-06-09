#include <stdio.h>
#include <string.h>
char num[110];
int main() {
    int zs=0,xs=0;
    gets(num); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in many modern compilers, 'gets' is removed entirely, leading to a compilation error]
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
            xs=i-zs; // @@ [This loop overwrites 'xs' in every iteration, so after the loop, 'xs' will be equal to (last_index - zs), not the total number of fractional digits. This leads to incorrect exponent calculation.]
        if(zs>=2) {
            printf("%c.",num[0]);
            for(int i=1; i<zs; i++)
                printf("%c",num[i]);
            for(int i=zs+1; i<=zs+xs; i++)
                printf("%c",num[i]); // @@ [Loop condition uses 'zs+xs' which may exceed string length because 'xs' was incorrectly computed; this can cause reading beyond the null terminator.]
            printf("e%d",zs-1);
        } else if(num[0]=='0') {
            int zero=0;
            for(int i=2; num[i]=='0'; i++)
                zero++;
            if(zero==xs-1) // @@ ['xs' is incorrectly computed earlier, so this condition may not reflect the actual number of trailing significant digits.]
                printf("%ce-%d",num[zs+xs],xs); // @@ [Accessing 'num[zs+xs]' may be out-of-bounds due to incorrect 'xs'. Also, when all fractional digits after leading zeros are consumed, this indexing fails.]
            else {
                printf("%c.",num[zero+2]);
                for(int i=zero+3; num[i]!='\0'; i++)
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ ['xs' is wrong, so exponent is wrong.]
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
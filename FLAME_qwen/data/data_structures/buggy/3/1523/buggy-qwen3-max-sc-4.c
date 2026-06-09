#include <stdio.h>
#include <string.h>
char num[110];
int main() {
    int zs=0,xs=0;
    gets(num); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
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
            xs=i-zs; // @@ [This loop overwrites 'xs' in every iteration, so after the loop, 'xs' will be equal to (last_index - zs), not the total number of fractional digits. It should count the number of digits after the decimal point, but instead it ends up as (strlen(num)-1 - zs). This leads to incorrect exponent calculation.]
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
            if(zero==xs-1) // @@ [Because 'xs' is incorrectly computed above, this condition may evaluate incorrectly. For example, if input is "0.001", 'xs' becomes 3 (since last i=4, zs=1, xs=4-1=3), but actual fractional digits = 3, trailing non-zero at position 4. However, 'zero' counts leading zeros after '.', which is 2. Then 'zero == xs-1' → 2 == 2 → true, which is correct in this case, but logic is fragile due to wrong 'xs'.]
                printf("%ce-%d",num[zs+xs],xs);
            else {
                printf("%c.",num[zero+2]);
                for(int i=zero+3; num[i]!='\0'; i++)
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ [Again, uses incorrect 'xs', leading to wrong exponent.]
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
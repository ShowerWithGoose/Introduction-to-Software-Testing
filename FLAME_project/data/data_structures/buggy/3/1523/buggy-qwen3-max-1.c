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
            xs=i-zs; // @@ [This loop sets xs to the offset of the last digit from the decimal point, not the total number of digits after the decimal. It should count total fractional digits, but instead ends up as (last_index - zs), which equals (strlen(num)-1 - zs). However, the real issue is in exponent calculation later.]
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
                zero++; // @@ [This loop counts leading zeros after "0.", but stops at first non-zero. However, it doesn't ensure that i stays within bounds (no check for '\0'), risking undefined behavior. More critically, the exponent logic below is flawed.]
            if(zero==xs-1) // @@ [Here, xs is (strlen(num)-1 - zs), and since zs=1 (because input starts with "0."), xs = strlen(num)-2. But zero counts only consecutive zeros starting at index 2. The condition zero == xs-1 implies only one non-zero digit at the end, but even then, exponent should be -(zero+1), not -xs.]
                printf("%ce-%d",num[zs+xs],xs); // @@ [Exponent should be -(zero + 1), not -xs. For input "0.00000009123...", zero=7, so exponent should be -8, but xs = 19 (since string length is 21: "0.00000009123456789012" → 21 chars, zs=1, so xs = 20-1=19?), leading to wrong exponent -19 or similar. In test case, this branch may not even trigger correctly.]
            else {
                printf("%c.",num[zero+2]); // @@ [This prints the first significant digit correctly.]
                for(int i=zero+3; num[i]!='\0'; i++)
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ [This is the core error: exponent should be -(zero + 1), but here it's -(xs - zero). Since xs = (last index - zs) = (n-1 - 1) = n-2, and zero is count of leading zeros after '0.', then xs - zero = (n-2) - zero, which is not equal to zero+1. For input "0.00000009123456789012" (length=21), zs=1, xs=19 (from earlier loop), zero=7, so xs-zero=12, but expected exponent is -8. Correct exponent is -(zero+1) = -8. So this line computes wrong exponent.]
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
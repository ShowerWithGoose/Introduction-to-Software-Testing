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
                zero++; // @@ [This counts leading zeros after "0.", but starts at index 2 assuming input always starts with "0."; however, it doesn't verify that zs==1 (i.e., only one digit before '.'). Also, if there are no non-zero digits, this may go out of bounds.]
            if(zero==xs-1) // @@ [xs is incorrectly computed earlier; also, condition assumes all digits after zeros are a single digit, but logic fails when multiple significant digits exist.]
                printf("%ce-%d",num[zs+xs],xs); // @@ [Exponent should be -(zero + 1), not -xs. For input "0.00000009123...", zero=7, so exponent should be -8, but xs = (last_index - zs) = (len-1 - 1) = ~19, leading to wrong exponent.]
            else {
                printf("%c.",num[zero+2]); // @@ [Indexing assumes "0." prefix (zs=1), so first digit after zeros is at 2+zero. This is correct only if zs==1, but code doesn't ensure that.]
                for(int i=zero+3; num[i]!='\0'; i++)
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ [Exponent calculation is wrong. Correct exponent is -(zero + 1). Here, xs is total offset of last digit, not count of fractional digits. Should be: exponent = -(zero + 1). For input, zero=7 → exponent=-8, but xs-zero ≈ 19-7=12 → outputs e-12 or similar, but actual buggy output was e-13 due to other miscalculations. In test case, this branch is taken and computes wrong exponent.]
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
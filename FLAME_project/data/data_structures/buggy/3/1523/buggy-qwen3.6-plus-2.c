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
                printf("%ce-%d",num[zs+xs],xs); // @@ The exponent calculation is incorrect for numbers like 0.00...0d... It should be -(zero + 1). Here xs is the count of digits after decimal, but the exponent depends on the position of the first non-zero digit. For 0.00000009..., zero is 7 (digits 2 to 8 are '0'), xs is 14. The first non-zero is at index 2+7=9. The exponent should be -(7+1) = -8. The code prints e-xs which is e-14. Wait, let's re-read carefully.
            // Input: 0.00000009123456789012
            // zs = 1 (index of '.')
            // xs loop: i goes from 2 to end. xs becomes length of string - 1 - zs = total digits after dot.
            // zero loop: starts at i=2. Counts consecutive '0's.
            // For 0.00000009123456789012:
            // indices: 0:'0', 1:'.', 2:'0', 3:'0', 4:'0', 5:'0', 6:'0', 7:'0', 8:'0', 9:'9'...
            // zero counts 0s at 2,3,4,5,6,7,8. So zero = 7.
            // xs = 14 (total digits after dot).
            // Condition zero == xs - 1? 7 == 13? False.
            // Else branch:
            // printf("%c.", num[zero+2]) -> num[9] which is '9'. Correct base start.
            // Loop prints rest.
            // printf("e-%d", xs-zero) -> e-(14-7) = e-7. Expected e-8.
            // The exponent for 0.00...0d (k zeros after dot before d) is -(k+1).
            // Here k = zero. So exponent should be -(zero+1).
            // xs-zero = (total digits after dot) - (leading zeros after dot). This equals number of digits from first non-zero to end. Not the exponent.
            // The exponent is determined by how many places the decimal point moves.
            // From 0.00000009... to 9....
            // Move right 8 times. So e-8.
            // zero is 7. Exponent is -(zero + 1).
            else {
                printf("%c.",num[zero+2]);
                for(int i=zero+3; num[i]!='\0'; i++)
                    printf("%c",num[i]);
                printf("e-%d",xs-zero); // @@ Error in exponent calculation. Should be -(zero + 1).
            }
        } else {
            for(int i=0; num[i]!='\0'; i++)
                printf("%c",num[i]);
            printf("e0");
        }
    }
    return 0;
}
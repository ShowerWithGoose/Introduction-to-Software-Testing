#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[10000],b[10000],c[10000];
    scanf("%s",a);
    int h=strlen(a);
    if(h!=1)
    {
            if(a[0]=='0')
    {
        int u; // @@ [u may be used uninitialized if all digits after '0.' are zero, but problem states no trailing zeros and at least one non-zero digit exists, so logically safe; however, more critically, the loop starts at i=2 assuming input format "0.x...", but if input has no decimal point or malformed, this fails. However, per problem, input always has digits before and after '.', so "0." is guaranteed. Still, the real bug is below:]
        int v=2;
        for(int i=2;i<h;i++)
        {
            if(a[i]!='0'){
                u=i;
                break;
            } 
        } // @@ [If the input is like "0.0...0x" with many zeros, u gets set correctly, but if the loop never breaks (which shouldn't happen per problem constraints), u remains uninitialized. But the main issue is in output formatting and exponent calculation.]
        c[0]=a[u];
        c[1]='.';
        for(int i=u+1;i<h;i++)
        {
            c[v]=a[i];
            v++;
        }
        for(int i=0;i<v-1;i++) // @@ [This prints up to index v-2, which omits the last digit. For example, if v was incremented for each digit after u, then valid indices are 0 to v-1, but loop stops at i < v-1, so last character is not printed. This causes missing digits in mantissa.]
        printf("%c",c[i]);
        printf("e");
        printf("-%d",u-1); // @@ [Exponent should be -(u - 1) because position of first non-zero after decimal at index u (0-based in string "0.d1d2...") means value is d * 10^{-(u-1)}. But since string is "0.", the first digit after '.' is at index 2, so exponent = -(u - 2 + 1) = -(u -1). So this part is actually correct. The real error is in printing loop above.]
    }
    else{
        int m; // @@ [m may be used uninitialized if there's no '.' in the input, but problem states input has digits before and after decimal point, so '.' must exist. So logically safe under problem constraints.]
        int n=2;
        b[0]=a[0];
        b[1]='.';
        for(int i=1;i<h;i++)
        {
            if(a[i]=='.') m=i;
            else {
                b[n]=a[i];
                n++;
            }
        }
        for(int i=0;i<n;i++) // @@ [This prints the base including all digits after the decimal, but if original number had only one digit before decimal (like "5.6"), it should output "5.6e0", but here m = index of '.', so exponent = m - 1 = 1 - 1 = 0 → correct. However, if input is "123.45", then m=3, exponent=2, and base becomes "1.2345" — but current code sets b[0]=a[0]='1', b[1]='.', then copies rest skipping '.', so b becomes "1.2345", which is correct. So logic seems okay, but wait: what if input has multiple digits before decimal? The problem says: "If there’s only one digit before the decimal point, it can be 0; otherwise, the first digit before the decimal point cannot be 0." So inputs like "123.45" are valid. But the code assumes that the first character is the only one before decimal that matters, which is correct for scientific notation. However, the bug is elsewhere.]
        printf("%c",b[i]);
        printf("e");
        printf("%d",m-1);
    }
    }
    if(h==1)
    {
        printf("%c",a[0]);
        printf("e0");
    }
    return 0;
}
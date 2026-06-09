#include<stdio.h>
#include<string.h>
#include<math.h>
char str[10005]; 
char real[10005];
int main ()
{
    gets(str);
    int i,j,k,flag,flag2,flag3=2;
    char c;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='.')
        {
            flag=i;
            break;
        }
        
    }
    if(flag==1) // @@ The condition `flag==1` only handles cases where the decimal point is at index 1 (e.g., "0.xxx" or "x.xxx"). It fails to correctly distinguish between numbers like "0.00..." (where exponent is negative) and "1.23..." (where exponent is 0 or positive). Specifically, for input "0.00000009123456789012", flag is 1, so it enters this block. However, the logic inside assumes the format is "0.digits" and calculates exponent based on leading zeros after decimal.
    {
        if(str[0]=='0')
        {
            for(i=2;i<len;i++)
        {
            if(str[i]!='0')
            {
            flag2=i;    
            c=str[i];
            break;
            }
        }
        real[0]=c;
        if(flag2!=len-1) {
        real[1]='.';}
        else if(flag2==len-1)
        {
            flag3--;
        }
        for(k=flag3,j=flag2+1;j<len;j++,k++)
        {
            real[k]=str[j];
        }printf("%s",real);    
        printf("e-%d",flag2-flag3); // @@ The exponent calculation `flag2-flag3` is incorrect. `flag2` is the index of the first non-zero digit. `flag3` is initialized to 2. For "0.00000009...", flag2 is 9 (index of '9'). The expected exponent is -8. The formula `flag2 - flag3` yields `9 - 2 = 7`, resulting in `e-7`. The correct exponent for "0.00...0d" is `-(number of zeros after decimal + 1)` or `point_index - first_non_zero_index + 1`? No. Scientific notation for $0.00\dots d$ is $d \times 10^{-k}$. If the first non-zero digit is at index `i` and dot is at `p`, the exponent is `p - i`. Here `p=1`, `i=9`. Exponent should be `1 - 9 = -8`. The code prints `-(flag2 - flag3)`. If we want -8, and flag2=9, we need `flag3` to be 1? Or simply calculate `flag - flag2`. `1 - 9 = -8`. So it should be `printf("e%d", flag - flag2);`.
        }        
        else 
        {
        printf("%s",str);
        printf("e0");
        }
    }
        
    else if(flag>1)
    {
        real[0]=str[0];
        real[1]='.';
        
        for(k=2,j=1;j<len;j++,k++)
    {
        if(j!=flag)
        {
        real[k]=str[j];
        }
        else {
        k--;}
    }
    printf("%s",real);
    printf("e%d",flag-1);
    }

    return 0;
}
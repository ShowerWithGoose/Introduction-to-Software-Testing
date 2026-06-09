#include<stdio.h>
#include<string.h>
int main()
{
    char c[100];
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings.]
    int num=0,flag=0,i=0,judge=0;
    if(strlen(c)==1)
    {
        printf("%c",c[0]);
        printf("e0");
    }
    else
    {
        if(c[0]=='0')
        {
            for(num=1,i=2;c[i]=='0';i++) // @@ [If the input is "0.x" where x starts with non-zero, this loop skips initialization of 'i' correctly but assumes at least two characters exist (index 0='0', index 1='.', index 2...). However, if input is just "0." (invalid per problem but possible), i=2 would be out of bounds. More critically, if the number after decimal starts immediately with non-zero (e.g., "0.5"), the loop condition c[i]=='0' fails, so 'num' remains 1 and 'i' remains 2, which is correct. But logic for printing mantissa is flawed: it prints all remaining digits without ensuring only significant digits are printed and doesn't handle trailing zeros (though problem says no trailing zeros). However, the main issue causing failure is likely in exponent calculation and output format.]
                num++;
            while(c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);    
                i++;
            }
            printf("e-%d",num); // @@ [Exponent should be -(number of leading zeros after decimal + 1). For "0.005", leading zeros = 2, exponent = -3. But 'num' starts at 1 and increments per zero, so for "0.005", i starts at 2, c[2]=='0' → num=2, then c[3]=='0' → num=3, then c[4]=='5' breaks. Then exponent printed is -3, which is correct. However, if input is "0.5", loop doesn't run, num=1, exponent=-1, which is wrong (should be -1? Wait: 0.5 = 5e-1 → correct. So exponent logic seems okay. But what if input is "0.0"? Problem states all digits are significant and no trailing zeros, so "0.0" won't occur. However, the bigger issue is in the mantissa printing: it prints all digits starting from first non-zero, but does not ensure that only one digit is before decimal. For "0.00567", it prints "5.67", which is correct. But the code prints the first digit, then on next iteration (judge=1) prints ".", then subsequent digits. So for "0.00567": i=4 ('5'), judge=0 → print '5', judge=1; i=5 ('6') → judge==1 → print '.', then '6'; i=6 ('7') → print '7'. So output becomes "5.67", which is correct. So why error? Possibly because when there's only one digit after removing leading zeros, e.g., "0.005", it prints "5" (no decimal point), which violates the requirement: if base is decimal, must have one digit before and after decimal. But problem says: "If it’s a decimal, it must have one significant digit before and after the decimal point". However, note: "If it’s an integer, it contains only one significant digit without a decimal point." So for single-digit mantissa, should output as integer (no decimal). But in this case, "0.005" → "5e-3", which is acceptable as integer base. However, the problem also says: "the digit before the decimal point is non-zero" — which is satisfied. But wait: the reference program handles this by always putting a '.' after first digit, then appending rest. But this program only puts '.' if there are more than one digit in mantissa. That seems correct. So maybe the real bug is elsewhere.]

            // However, looking at test case failure: Compilation Error. The only compilation error possible here is use of 'gets'. Modern compilers (like gcc with -std=c11 or later) will refuse to compile 'gets'. Hence, the error message "/bin/sh: 1: gcc: not found" might be misleading, but the actual issue is that the environment doesn't allow 'gets'. So the primary error is use of 'gets'.
        }
        else
        {
            while(c[i]!='.'&&c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);
                i++;
            }
            if(c[i]=='\0')
            {
                printf("e%d",judge-1);
            }
            else
            {
                printf("."); 
                for(i++;c[i]!='\0';i++)
                {
                    printf("%c",c[i]);
                }
                printf("e%d",judge-1);
            }
        }
    }
        

    return 0;
}
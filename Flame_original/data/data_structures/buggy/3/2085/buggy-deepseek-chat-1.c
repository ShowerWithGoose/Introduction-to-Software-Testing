#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#define eps 1e-6 
char c[1000];

int main() {
    gets(c);
    int s=strlen(c);int flag;
    for(int i=0;i<s;i++)
    {
        if(c[i]=='.') 
        {
            flag=i;break;
        }
    }
    if(flag!=1) 
    {
        for(int i=0;i<s;i++)
        {
            if(i==1) printf(".");
            else if (c[i]!='.')printf("%c",c[i]);
        }
        printf("e%d",flag-1);
    }     
    else
    {
        if(c[0]!='0') puts(c); // @@ Error: When the number has one digit before the decimal point and it's non-zero, the output should be the number followed by "e0", not just the number. For example, "1.23" should output "1.23e0", but this code outputs "1.23".
        else
        {
            int count=0;
            for(int i=0;i<s;i++)
            {
                if(c[i]=='0') count++;
                else if(c[i]>='1'&&c[i]<='9')
                {
                    flag=i;break;
                }
            }
            printf("%c",c[flag]);
            if(flag!=s-1)
            {
                printf(".");
                for(int i=flag+1;i<s;i++)
                {
                    printf("%c",c[i]);
                }    
                printf("e-%d",count);
            }
                
            else printf("e-%d",count); // @@ Error: When the number is like "0.001" (only one non-zero digit at the end), the output should include a decimal point before the non-zero digit. For example, "0.001" should output "1e-3", but this code outputs "1e-3" correctly for this case. However, for "0.0" (which shouldn't occur per problem constraints), it would be wrong. More critically, the logic for count is incorrect: count should count the number of zeros after the decimal point before the first non-zero digit, but here it counts all leading zeros including the one before the decimal point. For input "0.001", count becomes 2 (zeros at positions 0 and 1), but it should be 3 (zeros after decimal point: positions 2 and 3? Actually "0.001" has zeros at index 0, and after decimal at index 2,3? Let's trace: c = "0.001", s=5, flag=1. Loop: i=0: c[0]='0' count=1; i=1: c[1]='.' skip; i=2: c[2]='0' count=2; i=3: c[3]='0' count=3; i=4: c[4]='1' flag=4 break. So count=3, which is correct for exponent -3. But for "0.010", c="0.010", s=5, flag=1. Loop: i=0: count=1; i=1: '.' skip; i=2: '0' count=2; i=3: '1' flag=3 break. count=2, but expected exponent is -2? Actually "0.010" in scientific notation is "1.0e-2", so exponent -2 is correct. However, the output would be "1.0e-2" which is correct. But the problem says no trailing zeros, so "0.010" shouldn't appear. So this part might be okay, but the main error is the missing "e0" for the non-zero case.
        }
    }
    
return 0;
}
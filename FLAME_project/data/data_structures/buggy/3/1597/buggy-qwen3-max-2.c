#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    char str[1000];
    int count=0,a=1,b;
    
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it's deprecated. However, the main logic errors are elsewhere.]
    int n=strlen(str);
    
    if(str[1]=='.' && str[0]=='0')
    {
        for(int i=2;i<n;i++)
        {
            if(str[i]=='0')
            {
                a++;
                continue;
            }
            else
            {
                b=a+1;
                break;
            }
        }
        for(b;b<n;b++)
        {
            count++;
            printf("%c", str[b]);
            if(count>0)
            {
                printf("."); // @@ [This always prints a '.' after the first digit, even when there are no more digits, leading to trailing decimal point like "9." instead of "9"]
                count=0-n;
            }
            
            
        }
        printf("e-%d", a);
    }
    
    else if(str[1]=='.' && str[0]!='0')
    {
        for(int i=0;i<n;i++)
        {
            printf("%c", str[i]); // @@ [This prints the whole number including the decimal part, e.g., "5.3", but scientific notation should have only one digit before decimal, so this fails for numbers like "5.3" which should become "5.3e0", but the problem says if base is decimal it must have one digit before AND after — however, input like "5.3" is valid and this branch handles it correctly per spec? But note: test case is 0.9, so this branch not triggered. Main error is in first branch.]
        }
        printf("e0");
    }
    
    else if(str[1]!='.')
    {
        for(int i=0;i<n;i++)
        {
            if(str[i]!='.')
            {
                printf("%c", str[i]);
                a++;
            }
            if(count==0)
            {
                printf("."); // @@ [This prints a '.' immediately after the first digit, but if the number has no fractional part (e.g., "123"), it will output "1.23" which is correct, but if the input is like "12.34", this logic is flawed because it doesn't skip the existing decimal point properly. Also, 'a' counts non-decimal digits including those after '.', which is wrong.]
            }
            count++;
            if(str[i]=='.')
            {
                b=a; // @@ [b is set to a (which counts all non-'.' chars up to and including current), but this leads to incorrect exponent calculation.]
            }
        }
        printf("e%d", b-2); // @@ [Exponent calculation is incorrect due to flawed logic in tracking position of decimal point and digit count.]
    }
    return 0;
}
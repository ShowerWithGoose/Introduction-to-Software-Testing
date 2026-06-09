#include <stdio.h>
#include <string.h>
int ifproper(char c1,char c2)
{
    if(48<=c1&&c1<=57&&48<=c2&&c2<=57)
    {
        return 1;
    }
    else if(97<=c1&&c1<=122&&97<=c2&&c2<=122)
    {
        return 1;
    }
    else if(65<=c1&&c1<=90&&65<=c2&&c2<=90)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    char str[100],s;
    int i=0,j;
    gets(str);
    while(str[i]!=0)
    {
        if(str[i]!=45) 
        {
            s=str[i];
            printf("%c",s);
            i++;
        }
        else if(i>0)
        {
            if(ifproper(str[i-1],str[i+1]) && str[i+1] > str[i-1]) // @@ The original code only checks if characters are of the same type, but fails to check if the end character is greater than the start character. For "B-e", 'B' and 'e' are not the same type, so ifproper returns 0, which is correct. However, looking at the provided buggy output "Be" vs expected "B-e", let's re-examine.
            // Wait, the provided buggy code outputs "Be" for input "B-e".
            // Input: B - e
            // i=0: 'B' != '-', print 'B', i=1.
            // i=1: '-' == 45. i>0 is true.
            // ifproper('B', 'e'):
            // 'B' is 66. 'e' is 101.
            // 48<=66<=57? No.
            // 97<=66<=122? No.
            // 65<=66<=90? Yes.
            // 65<=101<=90? No.
            // So ifproper returns 0.
            // The if condition fails.
            // The code does NOT print '-' or 'e' in the else branch because there is no else branch for the inner if.
            // It just does i++.
            // Then i=2.
            // i=2: 'e' != '-', print 'e', i=3.
            // Result: "Be".
            // Expected: "B-e".
            // The error is that when expansion is NOT performed (either types mismatch or order is wrong), the hyphen and the next character should still be printed.
            {
                for(s=str[i-1]+1;s<=str[i+1]-1;s++)
                {
                    printf("%c",s);
                }
            }
            else // @@ Missing else block to handle cases where expansion is not valid. In these cases, the '-' and the following character must be output unchanged.
            {
                printf("%c%c", str[i], str[i+1]);
            }
            i++; 
        }
    }
    return 0;
}
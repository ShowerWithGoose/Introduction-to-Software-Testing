#include <stdio.h>
#include <string.h>
char arr[105];
int main()
{
    scanf("%s",arr);
    int i=0;
    
    if(arr[0]>'0')
    {
        for(i=1;i<strlen(arr);i++)
        {
            if(arr[i]=='.')
            {
                break;
            }
        }
        printf("%d.",arr[0]-'0'); // @@ This always prints a decimal point, but when the input has only one digit before the decimal point and no other digits after (like "0.9" is handled in else branch, but for numbers like "1.0" which shouldn't occur per spec, or for cases where the base should be an integer, this adds an extra '.'). For the given test case 0.9, this branch is not executed, but the bug is in the else branch.
        for(int j=1;j<strlen(arr);j++)
        {
            if(arr[j]!='.')
            {
                putchar(arr[j]);
            }
        }
        printf("e%d",i-1);
        
    }
    else
        {
            for(i=1;i<strlen(arr);i++)
            {
                if(arr[i]!='0'&&arr[i]!='.')
                {
                    break;
                }
            }
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') // @@ This condition is incorrect. It checks if the second-to-last character is '0' and also equals '.', which is impossible. It should check if the number is like "0.x" where x is a single digit (i.e., the decimal point is at index 1 and the last character is the digit). For input "0.9", strlen(arr)=3, arr[1]='.', arr[2]='9', so arr[strlen(arr)-2] = arr[1] = '.', which is not '0', so this condition is false, leading to the else branch that prints a decimal point, but the expected output is "9e-1" (no decimal point). The correct logic should detect when the number after the decimal point is a single digit and output without a decimal point.
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0'); // @@ This prints a decimal point even when the remaining digits after the first non-zero digit are only one digit (like in "0.9"), causing an extra '.' in the output.
            }
            for(int j=i+1;j<strlen(arr);j++)
            {
                if(arr[j]!='.')
                {
                    putchar(arr[j]);
                }
            }
            printf("e-%d",i-1);
            
        }
    
    
    
    return 0;
}
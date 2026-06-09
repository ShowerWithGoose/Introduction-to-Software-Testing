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
        printf("%d.",arr[0]-'0'); // @@ This always prints a decimal point, but when the input has only one digit before the decimal point and no other digits after it (like "0.9" is handled in the else branch, but for cases like "1.0" which shouldn't occur per spec, or for numbers like "12.3" this is correct; however, the bug is in the else branch for "0.9" where it prints a decimal point when it should not)
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
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') // @@ This condition is incorrect: it checks if the second-to-last character is '0' and also equals '.' which is impossible; it should check if the number after removing leading zeros and decimal point has no digits after the first non-zero digit (i.e., the input is like "0.x" where x is a single digit). For input "0.9", strlen(arr)=3, arr[1]='.', arr[2]='9', so arr[1] is '.' not '0', so this condition is false, causing it to go to the else branch and print a decimal point.
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0'); // @@ For input "0.9", i=2 (since arr[2]='9' is the first non-zero non-dot), this prints "9." which is incorrect; it should print "9" without the decimal point because there are no digits after the '9' in the original number.
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
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
        printf("%d.",arr[0]-'0'); // @@ [This always prints a decimal point even when the number has only one digit before the decimal and no fractional part in scientific notation, but more critically, in cases like "9" (from "0.9") it should not print a decimal point if there are no digits after it.]
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
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') // @@ [This condition is logically flawed: it checks if the second last character is both '0' and '.', which is impossible. It likely intended to check if the significant digit is the last character (i.e., no digits follow), but this condition never holds true.]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0'); // @@ [This prints a decimal point even when there are no following digits, leading to output like "9." instead of "9". For input "0.9", i=2, and the loop for printing digits after runs from j=3 to end (which is beyond string length), so nothing is printed after '.', resulting in "9.e-1" instead of "9e-1".]
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
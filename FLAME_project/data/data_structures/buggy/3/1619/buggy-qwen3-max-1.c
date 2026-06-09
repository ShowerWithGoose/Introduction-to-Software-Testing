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
        printf("%d.",arr[0]-'0'); // @@ [This always prints a decimal point even when the number has only one significant digit and should be output as an integer without a decimal point, e.g., "9" not "9."]
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
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') // @@ [This condition is logically incorrect: it checks if the same character equals both '0' and '.', which is impossible. It likely intended to check if the last non-decimal character is '0', but the logic is flawed and doesn't correctly detect when trailing part after significant digit is empty.]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0'); // @@ [Same issue as above: unnecessarily prints a decimal point when the scientific notation should be an integer (only one significant digit and nothing after). For input "0.9", this prints "9." instead of "9".]
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
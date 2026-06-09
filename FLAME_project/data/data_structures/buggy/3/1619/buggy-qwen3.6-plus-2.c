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
        printf("%d.",arr[0]-'0');
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
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') // @@ [Logical error: The condition checks if the same character is both '0' and '.', which is impossible. It should check if the last digit is '0' (meaning the number ends in .0 or similar, but problem says no trailing zeros, so this likely intends to check if there are no digits after the decimal point other than the significant one found, or specifically handles the case where the result is an integer. For input 0.9, strlen is 3, arr[1] is '.', arr[2] is '9'. arr[strlen-2] is arr[1] which is '.'. The condition '.'=='0' && '.'=='.' is false. So it goes to else. In else, it prints "%d.", resulting in "9.". The expected output is "9e-1". The logic for determining if the base is an integer or decimal is flawed. Specifically, if there are no digits after the first significant digit following the decimal point, it should be an integer. Here, for 0.9, i becomes 2 (index of '9'). The loop for printing digits starts at j=i+1=3, which is end of string. So no digits are printed after the dot. The issue is deciding whether to print the dot. If there are no more significant digits, don't print dot. The condition here is completely wrong.]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0');
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
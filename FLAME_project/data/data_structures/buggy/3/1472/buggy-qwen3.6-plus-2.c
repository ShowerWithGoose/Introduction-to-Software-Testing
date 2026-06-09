#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,n;
    char a[666]; 
    gets(a);
    n=strlen(a);
    for(i=1;i<=n;i++)
    {
        int flag=0; // @@ [The variable 'flag' is declared inside the loop and reset to 0 in every iteration, so it cannot correctly count the number of leading zeros after the decimal point. It should be declared outside the loop.]
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.')
            flag++; // @@ [Because 'flag' is reset to 0 each iteration, this count is incorrect. Also, logic for calculating exponent for numbers like 0.9 is flawed. For 0.9, i=1, a[1]='.', flag becomes 1. The else-if block is not entered. The loop continues. When i=2, a[2]='9', flag is reset to 0. a[2] is not '0' or '.', so it goes to else-if. flag is 0. Exponent printed is flag-1 = -1. But output format is wrong.]
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1) // @@ [This condition checks if all remaining characters were zeros/dots, which is incorrect logic for determining if there are trailing digits. For input "0.9", when i=2 (digit '9'), flag is 0 (reset). n-1 is 2. 0 != 2. So it goes to else.]
                printf("%c",a[i]);
                else
                printf("%c.",a[i]); // @@ [For input "0.9", this prints "9.". The problem states that if the base is an integer (one significant digit), it should not have a decimal point. Here, "9" is a single significant digit, so it should be printed as "9", not "9.".]
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ [The exponent calculation is incorrect. For "0.9", the exponent should be -1. Here flag is 0 (due to reset), so it prints e-1. This part happens to be correct for this specific case due to coincidence, but the logic is fundamentally broken because flag doesn't track the position correctly. More importantly, the previous line printed "9." instead of "9".]
                break;
            }
        }
        else
        {
            if(a[i]=='.')
            {
                printf("%c.",a[0]);
                for(j=1;j<i;j++)
                {
                    printf("%c",a[j]);
                    
                } 
                for(j=i+1;j<n;j++)
                {
                    printf("%c",a[j]);
                    
                }
                printf("e%d",i-1);
                break;
                
            }
        }
    }
    return 0;        
}
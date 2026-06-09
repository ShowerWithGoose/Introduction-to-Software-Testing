#include <stdio.h>
#include <string.h>

int main()
{
    char sim[101];
    char ha;
    int i,j;
    gets(sim);
    for(i=0;i<strlen(sim);i++)
    {
        if(sim[i]=='-'&&sim[i+1]>sim[i-1]) 
        {
            if(sim[i-1]>='a'&&sim[i-1]<='z'&&sim[i+1]>='a'&&sim[i+1]<='z')
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else if(sim[i-1]>='A'&&sim[i-1]<='Z'&&sim[i+1]>='A'&&sim[i+1]<='Z') // @@ The original code used independent 'if' statements. If the first 'if' (lowercase) is false, it falls through to the second 'if'. If the second 'if' (uppercase) is also false, it falls through to the third 'if'. If the third 'if' (digits) is false, it executes the 'else' block which prints "-". However, if the first 'if' is true, it executes the loop, but then because the subsequent checks are 'if' and not 'else if', it continues checking. More critically, if the first 'if' is FALSE, and the second 'if' is TRUE, it executes the uppercase loop. But then it skips the third 'if' condition check? No, 'if...if...if...else' structure means the 'else' belongs only to the last 'if'. So if it's lowercase, it prints expansion, then checks uppercase (false), then checks digits (false), then executes ELSE of the digit check, printing "-". This causes the hyphen to be printed even after successful expansion if the types don't match the later conditions. We need 'else if' to ensure only one block executes.
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else if(sim[i-1]>='0'&&sim[i-1]<='9'&&sim[i+1]>='0'&&sim[i+1]<='9') // @@ Same logic error as above. The 'else' attached to this block only triggers if this specific condition is false, regardless of whether previous conditions were true. This leads to incorrect output like printing '-' after expanding lowercase letters.
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else
            {
                printf("-");
            }
        }
        else
        {
            printf("%c", sim[i]);
        }
    }
    return 0;
}
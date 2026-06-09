#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a);
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ fabs calculates absolute difference, failing to verify that a[i+1] > a[i-1] as required; should use a[i+1] > a[i-1].
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ Should be 'else if' to create a mutually exclusive conditional chain; otherwise, the 'else' on line 21 will execute incorrectly even if the lowercase condition was true.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ Should be 'else if' for proper logical chaining; also incorrectly uses fabs instead of checking a[i+1] > a[i-1].
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else // @@ This 'else' only binds to the immediately preceding 'if' (digit check), causing '-' to be printed even when a valid lowercase or uppercase expansion occurs.
                printf("-");
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}
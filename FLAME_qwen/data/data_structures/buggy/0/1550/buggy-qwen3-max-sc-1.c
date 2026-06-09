#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in some environments, this may lead to compilation errors if strict standards are enforced.]
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Using 'fabs' from <math.h> on integer character values is unnecessary and incorrect; also, when i=0, a[i-1] accesses invalid memory (a[-1]).]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same issue: 'fabs' misuse and potential out-of-bounds access when i=0. Also, multiple 'if's instead of 'else if' causes overlapping expansions and incorrect '-' handling.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same issues: 'fabs' misuse, out-of-bounds access at i=0, and should be 'else if' chain. Also, condition allows expansion even if a[i+1] < a[i-1], because fabs makes it positive.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else
                printf("-"); // @@ [This 'else' only pairs with the last 'if', so if any earlier 'if' matches but shouldn't (e.g., due to reverse order), it still prints nothing and skips printing '-', leading to missing '-'.]
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}
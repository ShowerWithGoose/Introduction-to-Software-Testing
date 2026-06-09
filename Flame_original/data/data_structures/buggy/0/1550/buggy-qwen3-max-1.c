#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers]
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Using 'fabs' from math.h for integer comparison is unnecessary and incorrect; also, condition should ensure a[i+1] > a[i-1], not just absolute difference >=1]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same issue: 'fabs' misuse and incorrect condition logic]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same issue: 'fabs' misuse and incorrect condition logic; also, multiple 'if's instead of 'else if' causes '-' to be printed even when expansion occurs]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else
                printf("-"); // @@ [This 'else' only pairs with the last 'if', so if any earlier 'if' matches but later ones don't, it may incorrectly print '-' in addition to expanded chars or skip printing '-' when needed]
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}
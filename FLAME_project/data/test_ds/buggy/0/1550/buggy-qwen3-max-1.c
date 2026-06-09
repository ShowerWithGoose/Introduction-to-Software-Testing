#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logic error is elsewhere.]
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1)
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Using multiple independent 'if' statements instead of 'else if' causes the final 'else' to only apply to the last 'if', leading to incorrect '-' output when earlier conditions match but later ones don't.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same issue: this is an independent 'if', so if it fails, the 'else' runs even if a previous condition succeeded, causing extra '-' to be printed.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else
                printf("-"); // @@ [This 'else' only pairs with the last 'if' (isdigit), not the whole group. So if, e.g., the first 'if' (islower) is true and prints letters, but the last 'if' (isdigit) is false, it still prints '-', causing duplicate or incorrect output like "abcdefghijklmnopqrst-uBCDE-F".]
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}
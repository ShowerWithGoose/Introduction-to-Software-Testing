#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a); // @@ gets is deprecated and removed in C11, often causing compilation errors in modern environments; use fgets instead.
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ Logical error: fabs allows reverse order expansion (e.g., d-a); should check a[i+1] > a[i-1]. Also accesses a[-1] when i=0 causing undefined behavior.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ Should be 'else if' to form a mutually exclusive chain; otherwise multiple blocks may execute and the final 'else' attaches incorrectly.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ Should be 'else if'. Same logical error with fabs.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else // @@ This 'else' is only attached to the last 'if', causing '-' to be printed even when lowercase/uppercase expansion conditions are met.
                printf("-");
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}
#include<stdio.h>
#include<string.h>

char s[105];

int main()
{
    scanf("%s", &s); // @@ Incorrect argument type for %s format specifier; should be 's' instead of '&s' to pass a char pointer, which causes a type mismatch compilation error/warning.
    
    int i, l = strlen(s), k = 106, p; // @@ Variable 'p' is uninitialized; should be initialized (e.g., p = 0) to prevent undefined behavior or compilation errors if the compiler enforces strict initialization checks.
    
    for(i = 0; i < l; i++)
    {
        if(s[i] == '.')
        {
            k = i;
        }
        if(i > k && s[i] != '0')
        {
            p = i;
            break;
        }
    }
    
    if(k == 1 && s[0] == '0')
    {
         printf("%c", s[p]);
         if(p < l - 1)
         {
             printf(".");
        }
         for(i = p + 1; i < l; i++)
         {
             printf("%c", s[i]);
         }
         printf("e-");
         printf("%d", l - p); // @@ Logical error: exponent calculation is incorrect. It should be 'p - 1' instead of 'l - p', as the exponent depends on the position of the first significant digit relative to the decimal point, not the total string length.
    }
    else
    {
        printf("%c", s[0]);
         printf(".");
        for(i = 1; i < l; i++)
        {
            if(s[i] != '.')
            {
                printf("%c", s[i]);
            }
        }
        printf("e");
        printf("%d", k - 1);
    }
    return 0;
}
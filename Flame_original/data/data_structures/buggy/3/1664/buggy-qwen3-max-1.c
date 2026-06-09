#include<stdio.h>
#include<string.h>

char s[105];

int main()
{
    scanf("%s", &s); // @@ [Using &s is incorrect; s is already a pointer to char array, should be scanf("%s", s);]
    
    int i, l = strlen(s), k = 106, p; // @@ [Variable 'p' is used uninitialized if the input has no decimal point or no non-zero digit after it]
    
    for(i = 0; i < l; i++)
    {
        if(s[i] == '.')
        {
            k = i;
        }
        if(i > k && s[i] != '0') // @@ [This condition may access uninitialized 'k' (if no '.' found, k remains 106) leading to out-of-bound or logic error]
        {
            p = i;
            break;
        }
    }
    
    if(k == 1 && s[0] == '0')
    {
         printf("%c", s[p]); // @@ ['p' may be uninitialized if all digits after decimal are zero or if there's no decimal point]
         if(p < l - 1)
         {
             printf(".");
        }
         for(i = p + 1; i < l; i++)
         {
             printf("%c", s[i]);
         }
         printf("e-");
         printf("%d", l - p); // @@ [Exponent calculation is incorrect; should be based on position relative to first non-zero digit, not total length]
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
        printf("%d", k - 1); // @@ [If there's no decimal point (k remains 106), this prints a large negative exponent instead of handling integer case correctly]
    }
    return 0;
}
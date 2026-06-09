#include<stdio.h>
#include<string.h>

char s[105];

int main()
{
    scanf("%s", &s); // @@ Incorrect argument type for scanf; should be 's' instead of '&s' to pass a char pointer.
    
    int i, l = strlen(s), k = 106, p; // @@ Initializing k to 106 causes incorrect exponent calculation for integers without a decimal point. It should be initialized to -1 or handled conditionally.
    
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
         printf("%d", l - p);
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
        printf("%d", k - 1); // @@ When no decimal point is present, k remains 106, resulting in an incorrect exponent of 105. It should output l - 1 for integers.
    }
    return 0;
}
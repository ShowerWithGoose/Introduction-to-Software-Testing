#include<stdio.h>
#include<string.h>

char s[105];

int main()
{
    scanf("%s", &s); // @@ [Using &s is incorrect; s is already a pointer to char array, should be scanf("%s", s);]
    
    int i, l = strlen(s), k = 106, p; // @@ [Variable 'p' is used uninitialized if the loop doesn't set it (e.g., when there's no non-zero digit after decimal)]
    
    for(i = 0; i < l; i++)
    {
        if(s[i] == '.')
        {
            k = i;
        }
        if(i > k && s[i] != '0') // @@ [This condition only executes after '.' is found, but if input has no '.', k remains 106 and i > k is false, so 'p' never gets set]
        {
            p = i;
            break;
        }
    }
    
    if(k == 1 && s[0] == '0')
    {
         printf("%c", s[p]); // @@ [If input is "0.0", the loop never sets 'p', leading to undefined behavior when accessing s[p]]
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
        printf("%d", k - 1); // @@ [If input has no decimal point (k remains 106), this prints e105 which is wrong; also, for numbers like "123", exponent should be 2, not k-1 where k=106]
    }
    return 0;
}
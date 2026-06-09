#include<stdio.h>
#include<string.h>

char s[105];

int main()
{
    scanf("%s", &s); @@ [Using &s is incorrect; s is already a pointer to char array, should be scanf("%s", s);]
    
    int i, l = strlen(s), k = 106, p;
    
    for(i = 0; i < l; i++)
    {
        if(s[i] == '.')
        {
            k = i;
        }
        if(i > k && s[i] != '0') @@ [This condition may access uninitialized 'k' if no '.' is found; also logic flawed for leading zeros after decimal]
        {
            p = i;
            break;
        }
    }
    
    if(k == 1 && s[0] == '0')
    {
         printf("%c", s[p]); @@ [If input is "0.0", p is uninitialized → undefined behavior]
         if(p < l - 1)
         {
             printf(".");
        }
         for(i = p + 1; i < l; i++)
         {
             printf("%c", s[i]);
         }
         printf("e-");
         printf("%d", l - p); @@ [Exponent calculation is wrong; should be based on position relative to first non-zero digit, not total length]
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
        printf("%d", k - 1); @@ [If there's no decimal point (k remains 106), this prints e105 which is wrong; also fails when input has no decimal point]
    }
    return 0;
}
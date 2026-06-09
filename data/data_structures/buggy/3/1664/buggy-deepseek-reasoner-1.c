#include<stdio.h>
#include<string.h>

char s[105];

int main()
{
    scanf("%s", &s); // @@ [Error: scanf expects char* for %s, but &s is char (*)[105]; should be scanf("%s", s)]
    
    int i, l = strlen(s), k = 106, p; // @@ [Error: p is uninitialized; if no non-zero digit after decimal is found (though unlikely), using p later leads to undefined behavior]
    
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
         printf("%d", l - p); // @@ [Error: exponent should be (p - k) (number of places moved), not (l - p). For example, input "0.001" gives wrong exponent]
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
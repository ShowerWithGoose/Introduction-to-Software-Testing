#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 105
#define array_num(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-10
int main ()
{
    char s[MAXN];
    int i, j;
    scanf("%s", s);
    for (i=0; s[i]!='\0'; i++)//what if - is the last in the string?
    {
        if (s[i]=='-')
        {
            if (s[i-1]>='0' && s[i-1]<='9') // @@ [Error: s[i-1] is out-of-bounds when i==0 (dash at beginning of string).]
            {
                if (s[i+1]>s[i-1] && s[i+1]<='9')
                {
                    for (j=1; s[i-1]+j<s[i+1]; j++)
                        printf("%c", s[i-1]+j);
                }
                else
                    printf("%c", s[i]);
            }
            else if (s[i-1]>='A' && s[i-1]<='Z') // @@ [Error: s[i-1] is out-of-bounds when i==0.]
            {
                if (s[i+1]>s[i-1] && s[i+1]<='Z')
                {
                    for (j=1; s[i-1]+j<s[i+1]; j++)
                        printf("%c", s[i-1]+j);
                }
                else
                    printf("%c", s[i]);
            }
            else if (s[i-1]>='a' && s[i-1]<='z') // @@ [Error: s[i-1] is out-of-bounds when i==0.]
            {
                if (s[i+1]>s[i-1] && s[i+1]<='z')
                {
                    for (j=1; s[i-1]+j<s[i+1]; j++)
                        printf("%c", s[i-1]+j);
                }
                else
                    printf("%c", s[i]);
            }
            else
                printf("%c", s[i]);
        }
        else
            printf("%c", s[i]);
    }
    
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define NumberOf(a) (sizeof(a)/sizeof(a[0]))
#define eps 1e-7
#define ll long long
#define maxn 1000000005
#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[10001];
    int location[10001] = { -2};
    gets(s);
    int l = strlen(s);
    int i,j=1,k,p;
    for (i = 0; i < l; i++)
    {
        if (s[i] == '-')
        {
            location[j++] = i;
        }
    }
    for (i = 1; i <j; i++)
    {
        for (k = location[i-1]+2; k < location[i]; k++)
        {
            printf("%c", s[k]);
        }
        if ((s[location[i] - 1] >= 'a' && s[location[i] + 1] <= 'z') || (s[location[i] - 1] >= '0' && s[location[i] + 1] <= '9') || (s[location[i] - 1] >= 'A' && s[location[i] + 1] <= 'Z')) // @@ The condition is incorrect; it should check that both characters are within the same range (e.g., both lowercase, both uppercase, or both digits) and that the second character is greater than the first. The current condition only checks the lower bound of the first character and the upper bound of the second, which does not ensure they are of the same type or that the second is greater.
        {
            for (p = 1; p <= s[location[i] + 1] - s[location[i] - 1]; p++)
            {
                printf("%c", s[location[i] - 1] + p);
            }
        }
    }
    for (i = location[j-1]+2; i < l; i++)
    {
        printf("%c", s[i]);
    }
}
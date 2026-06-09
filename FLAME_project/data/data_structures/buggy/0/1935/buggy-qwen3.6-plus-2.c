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
        // @@ The condition checks if the start char is in a range and end char is in a range, but does not ensure they are the SAME type. 
        // For "B-e": 'B' is >= 'A' (True) and 'e' is <= 'Z' (False). So this block is skipped.
        // However, the character 'B' (before '-') and 'e' (after '-') are not printed anywhere else if expansion doesn't happen.
        // The logic fails to output the original characters (start, '-', end) when expansion conditions are not met.
        if ((s[location[i] - 1] >= 'a' && s[location[i] + 1] <= 'z') || (s[location[i] - 1] >= '0' && s[location[i] + 1] <= '9') || (s[location[i] - 1] >= 'A' && s[location[i] + 1] <= 'Z'))
        {
            // @@ Additionally, even if types matched, it doesn't check if start < end.
            for (p = 1; p <= s[location[i] + 1] - s[location[i] - 1]; p++)
            {
                printf("%c", s[location[i] - 1] + p);
            }
        }
        else {
             // @@ Missing else block to print the original sequence (char, '-', char) when expansion is invalid.
             printf("%c-%c", s[location[i]-1], s[location[i]+1]);
        }
    }
    for (i = location[j-1]+2; i < l; i++)
    {
        printf("%c", s[i]);
    }
}
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
    gets(s); // @@ [gets is deprecated and removed in the C11 standard, which causes compilation errors in modern compilers; use fgets instead]
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
        for (k = location[i-1]+2; k < location[i]; k++) // @@ [Logical error: index calculation is flawed; location[0] is -2 so it starts at index 0 incorrectly, and this loop structure skips printing the '-' character itself when expansion conditions are not met]
        {
            printf("%c", s[k]);
        }
        if ((s[location[i] - 1] >= 'a' && s[location[i] + 1] <= 'z') || (s[location[i] - 1] >= '0' && s[location[i] + 1] <= '9') || (s[location[i] - 1] >= 'A' && s[location[i] + 1] <= 'Z')) // @@ [Semantic error: condition incorrectly checks only the lower bound of the left character and the upper bound of the right character; it fails to verify that both characters belong to the exact same range and that the left character is strictly less than the right character]
        {
            for (p = 1; p <= s[location[i] + 1] - s[location[i] - 1]; p++)
            {
                printf("%c", s[location[i] - 1] + p);
            }
        }
    }
    for (i = location[j-1]+2; i < l; i++) // @@ [Logical error: incorrect starting index for the remaining string; fails to print the last hyphen and subsequent characters when no expansion occurs, violating the requirement to output unchanged input for invalid cases]
    {
        printf("%c", s[i]);
    }
}
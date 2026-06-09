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
    gets(s); @@ [Using 'gets' is unsafe and deprecated; many compilers no longer support it, leading to compilation errors. Use 'fgets' instead.]
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
        if ((s[location[i] - 1] >= 'a' && s[location[i] + 1] <= 'z') || (s[location[i] - 1] >= '0' && s[location[i] + 1] <= '9') || (s[location[i] - 1] >= 'A' && s[location[i] + 1] <= 'Z')) @@ [Incorrect condition: should check both ends are same type AND that the left char < right char. Also, current logic uses <= on right side without checking lower bound (e.g., 'a' <= x <= 'z'), so it may accept invalid ranges like 'z-a'.]
        {
            for (p = 1; p <= s[location[i] + 1] - s[location[i] - 1]; p++) @@ [This loop prints one character too many. It should stop before reaching s[location[i]+1], but condition p <= diff causes it to print up to and including s[location[i]+1]. Should be p < diff. Also, if the range is invalid (left >= right), this still runs incorrectly.]
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
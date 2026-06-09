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
        if ((s[location[i] - 1] >= 'a' && s[location[i] + 1] <= 'z') || (s[location[i] - 1] >= '0' && s[location[i] + 1] <= '9') || (s[location[i] - 1] >= 'A' && s[location[i] + 1] <= 'Z')) // @@ The condition checks if the start char is in a range and end char is in a range, but doesn't ensure they are the SAME type (e.g., 'B' is >= 'a' is false, but 'B' >= 'A' is true and 'e' <= 'Z' is false. Wait, 'B' >= 'A' is true. 'e' <= 'Z' is false. So this specific case B-e fails the third part. But what about a-Z? 'a' >= 'a' true, 'Z' <= 'z' true. This incorrectly identifies a-Z as valid lowercase expansion. The logic must ensure BOTH are lowercase, OR BOTH are uppercase, OR BOTH are digits. The current logic uses OR between mixed checks which can allow cross-type matches if ranges overlap or checks are insufficient. Specifically, it fails to enforce that the left and right characters belong to the exact same category exclusively.)
        {
            for (p = 1; p <= s[location[i] + 1] - s[location[i] - 1]; p++)
            {
                printf("%c", s[location[i] - 1] + p);
            }
        }
        else // @@ Missing else block to print the original segment (char before '-', the '-', and char after '-') when expansion conditions are not met. Currently, if the condition fails, nothing is printed for this segment, causing missing output like 'B-' in 'B-e'.
        {
             printf("%c%c%c", s[location[i]-1], s[location[i]], s[location[i]+1]);
        }
    }
    for (i = location[j-1]+2; i < l; i++)
    {
        printf("%c", s[i]);
    }
}
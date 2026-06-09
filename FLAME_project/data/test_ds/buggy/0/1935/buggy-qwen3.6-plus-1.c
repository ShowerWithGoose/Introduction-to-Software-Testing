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
        for (k = location[i-1]+2; k < location[i]; k++) // @@ Incorrectly starts from location[i-1]+2, skipping the character immediately after the previous hyphen, which causes missing output when expansion is not performed.
        {
            printf("%c", s[k]);
        }
        if ((s[location[i] - 1] >= 'a' && s[location[i] + 1] <= 'z') || (s[location[i] - 1] >= '0' && s[location[i] + 1] <= '9') || (s[location[i] - 1] >= 'A' && s[location[i] + 1] <= 'Z')) // @@ The condition incorrectly validates character types and ranges. It should check if both characters are in the same category (lowercase, uppercase, or digits) and that the left character is strictly less than the right. Additionally, the lack of an else branch causes the hyphen and following character to be omitted when expansion is invalid.
        {
            for (p = 1; p <= s[location[i] + 1] - s[location[i] - 1]; p++) // @@ Relies on the flawed condition above and does not handle invalid expansion cases, leading to incorrect output.
            {
                printf("%c", s[location[i] - 1] + p);
            }
        }
    }
    for (i = location[j-1]+2; i < l; i++) // @@ Incorrectly starts from location[j-1]+2, skipping the character after the last hyphen, potentially omitting output.
    {
        printf("%c", s[i]);
    }
}
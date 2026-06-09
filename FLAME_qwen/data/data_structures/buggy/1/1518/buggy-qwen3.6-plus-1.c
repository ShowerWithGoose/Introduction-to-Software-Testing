#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int Mark[10] = { 0 }; // @@ Array size is 10, but indices up to N (max 10) are accessed, causing out-of-bounds. Should be size 11.
char s[11];
void rank(int m, int n);
int x;
int main()
{
    scanf("%d", &x);
    rank(0, x);
    return 0;
}
void rank(int m, int n)
{
    int i;
    if (n == 0) {
        s[m] = '\0';
        puts(s); // @@ Does not print spaces between integers as required by the output format. Should use a loop to print characters separated by spaces.
        return;
    }
    for (i = 1; i <= x; i++)
        if (Mark[i] == 0) {
            Mark[i] = 1;
            s[m] = '0' + i;
            rank(m + 1, n - 1);
            Mark[i] = 0;
        }
}
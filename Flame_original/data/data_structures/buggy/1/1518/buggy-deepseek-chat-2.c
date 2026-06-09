#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int Mark[10] = { 0 };
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
        puts(s); // @@ [Error: puts(s) outputs the string without spaces between digits, but the expected output requires each integer separated by a space. For example, for N=3, the output should be "1 2 3" not "123".]
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
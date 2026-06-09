#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printloop(int begin, int n, char* string);

void swap(char* string, int begin, int k);
int main() {
    int n;
    scanf("%d", &n);
    char string[100];
    for (int i = 1; i <= n; i++)
    {
        string[i] = i; // @@ [Error: Assigning integer value to char array element without converting to character. This stores the integer value directly, not the digit character. For example, i=1 stores 1 (ASCII SOH) instead of '1'. This will cause incorrect output when printing with %d.]
    }
    printloop(1,n,string);

    

    
}
    
void swap(char* string, int begin, int k)
{
    int inter = string[begin];
    string[begin] = string[k];
    string[k] = inter;
    
}
    
void printloop(int begin, int n, char* string)
{
    if (begin == n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", string[i]); // @@ [Error: Printing char values with %d will output the ASCII integer values, not the intended numbers 1 to N. Since string[i] stores integer values (not character digits), this prints the raw integer values, but the output format expects space-separated integers. However, the core issue is that the array should be int, not char, to properly handle numbers > 9 and avoid ASCII conversion issues.]
        }
        printf("\n");
    }
    else
    {
        for (int k = begin; k <= n; k++)
        {
            swap(string, begin, k);
            printloop(begin + 1, n, string);
            swap(string, begin, k);

        }
    }



}
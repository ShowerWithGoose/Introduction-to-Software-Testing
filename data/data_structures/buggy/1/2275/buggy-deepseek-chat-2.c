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
        string[i] = i; // @@ [Error: Assigning integer value to char array element without converting to character representation. This stores the raw integer (e.g., 1, 2) instead of the character '1', '2', leading to incorrect output when printed with %d.]
    }
    printloop(1,n,string);

    

    
}
    
void swap(char* string, int begin, int k)
{
    int inter = string[begin]; // @@ [Error: Using int to store char value is acceptable, but the underlying issue is that string contains raw integers, not characters. This will swap raw integer values correctly, but the output will still be wrong due to the initialization error.]
    string[begin] = string[k];
    string[k] = inter;
    
}
    
void printloop(int begin, int n, char* string)
{
    if (begin == n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", string[i]); // @@ [Error: Printing char values with %d will output the raw integer values (1, 2, ...) instead of the intended digits. However, the core issue is that the array stores integers, not characters, so the output will be numbers but without spaces between them correctly? Actually, the output will be numbers like "1 2 3" but the initialization stores raw ints, so it prints correctly as numbers. The real problem is that the array is of type char, which may overflow for N>9, and the initialization does not convert to character digits. For N=10, char may not hold 10 properly, and the output will be wrong. Also, the problem expects integers separated by spaces, but the code prints raw integer values, which for N=10 will produce incorrect results due to char overflow.]
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
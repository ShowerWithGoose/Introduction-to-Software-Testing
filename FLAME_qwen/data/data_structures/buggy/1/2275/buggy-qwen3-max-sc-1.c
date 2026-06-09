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
        string[i] = i; // @@ [Storing integer values directly into a char array is incorrect. The ASCII value of the integer is stored, not the character representation. For example, if i=1, string[i] becomes 1 (non-printable), not '1'. This leads to wrong output when printing as %d.]
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
            printf("%d ", string[i]); // @@ [Printing char array elements with %d will output their numeric (ASCII) values, which are not the intended digits. Since the array was filled with integer values (e.g., 1,2,...) instead of character digits ('1','2',...), this may coincidentally appear correct for small N, but it's logically flawed and inconsistent with standard permutation output expectations. However, the primary error is in initialization, not here.]
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
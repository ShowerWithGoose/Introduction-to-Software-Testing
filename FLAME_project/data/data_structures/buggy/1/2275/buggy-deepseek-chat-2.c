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
        string[i] = i; // @@ Error: Assigning integer value to char array element without converting to character representation. This stores the raw integer (e.g., 1, 2) instead of the character '1', '2'. When printed with %d, it will output the integer value, but the logic for lexicographic ordering may be incorrect if N > 9, and the array is not null-terminated.
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
    if (begin == n) // @@ Error: The base case should be when begin > n or begin == n+1 to include the last element. For N=2, when begin=2, it prints only one element (string[2]) instead of both elements. The correct condition should be begin > n to print the full permutation.
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", string[i]);
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
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
        string[i] = i; // @@ Error: Assigning integer value to char array element without converting to character representation. This stores the raw integer (e.g., 1, 2) instead of the character '1', '2'. When printed with %d, it will output the integer value, but the logic for lexicographic ordering may be affected if the array is treated as characters elsewhere. However, the main issue is that the output format does not match the expected output for N=2; the program outputs "1 2 " and "2 1 " but the expected output is only "1 2 " (one line). This indicates the permutation generation logic is incorrect for N=2, producing two permutations instead of one.
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
    if (begin == n) // @@ Error: The base case should be when begin > n or begin == n+1 to include the last element. For N=2, when begin=2, it prints the permutation, but then the recursion continues incorrectly. The condition should be begin > n to stop recursion after processing all elements. With begin == n, for N=2, when begin=2, it prints and returns, but the loop in the else branch for begin=1 will call printloop(2, ...) which prints, then after returning, it swaps back and continues the loop, leading to duplicate permutations. The correct base case is begin > n.
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
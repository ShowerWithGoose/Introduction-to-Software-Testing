#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printloop(int begin, int n, char* string);

void swap(char* string, int begin, int k);
int main() {
    int n;
    scanf("%d", &n);
    char string[100]; // @@ [Error: Using `char` array to store integers is semantically incorrect; should be `int` array to properly handle integer values and avoid type mismatch with `%d` format specifier.]
    for (int i = 1; i <= n; i++)
    {
        string[i] = i;
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
            printf("%d ", string[i]); // @@ [Error: Outputs a trailing space after the last integer in each line. Should conditionally print space only between numbers to match the expected output format.]
        }
        printf("\n");
    }
    else
    {
        for (int k = begin; k <= n; k++)
        {
            swap(string, begin, k); // @@ [Error: The standard swap-backtracking algorithm does not generate permutations in lexicographical order. A different approach (like the reference program's rotation method) is required to satisfy the lexicographical order constraint.]
            printloop(begin + 1, n, string);
            swap(string, begin, k);

        }
    }



}
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
        string[i] = i; // @@ [Storing integer values directly into a char array leads to incorrect representation; should store 'i' as character (e.g., '0'+i) or use int array]
    }
    printloop(1,n,string); // @@ [Function expects permutations in lexicographical order but current swapping approach does not guarantee sorted output due to using char array with integer values]

    

    
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
            printf("%d ", string[i]); // @@ [Printing char array elements as %d interprets them as integers, but they were stored as raw integer values in char slots, causing potential misinterpretation and wrong output format]
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
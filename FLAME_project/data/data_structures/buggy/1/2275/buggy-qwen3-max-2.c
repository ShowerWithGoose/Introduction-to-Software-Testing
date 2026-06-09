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
        string[i] = i;
    }
    printloop(1,n,string); // @@ [The program generates all permutations correctly but does not output them in lexicographical order because the swapping approach used does not maintain sorted order during recursion. The initial array is sorted, but after swaps and backtracking, the order of generation is not lexicographic.]

    

    
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
            swap(string, begin, k); // @@ [This backtracking step restores the original order, but the sequence of recursive calls does not guarantee lexicographical output. For lexicographical order, either generate permutations iteratively using std::next_permutation or ensure recursive calls process elements in a way that maintains global order, which this code fails to do.]

        }
    }



}
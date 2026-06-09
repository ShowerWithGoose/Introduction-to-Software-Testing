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
        string[i] = i; // @@ [Storing integer values directly into a char array leads to incorrect representation; should store 'i' as character (e.g., '0'+i) or use int array. Also, indexing starts at 1, leaving string[0] unused, which is unconventional but not erroneous by itself. However, the main issue is that when printing with %d, it will print the ASCII value if stored as char, but here it's stored as integer in char type, causing potential truncation and wrong output.]
    }
    printloop(1,n,string);

    

    
}
    
void swap(char* string, int begin, int k)
{
    int inter = string[begin]; // @@ [Using 'int' for 'inter' is unnecessary and inconsistent since string is char*. Should use char to avoid sign-extension issues and maintain type consistency. However, this may not cause compilation error but can lead to logical errors. The primary compilation-related concern is elsewhere.]
    string[begin] = string[k];
    string[k] = inter;
    
}
    
void printloop(int begin, int n, char* string)
{
    if (begin == n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", string[i]); // @@ [Printing char values with %d will output their numeric (ASCII) values, not the intended integers 1..N. This causes incorrect output. Should either use an int array or convert char to digit correctly. This is a logical error leading to wrong output, not compilation error. However, the reported error was "gcc: not found", which is environment-related, but assuming that's a red herring and focusing on code bugs per problem context.]
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
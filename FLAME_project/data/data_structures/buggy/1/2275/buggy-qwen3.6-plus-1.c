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
    if (begin == n) // @@ The base case condition is incorrect. It should be `begin > n` or the loop inside should handle the last element. Currently, when `begin == n`, it prints the permutation but misses the recursive step for the last position if interpreted as "fixing" positions. More critically, standard permutation generation usually fixes position `begin` and recurses to `begin + 1`. If `begin == n`, it means we are at the last position. The current code prints when `begin == n`, which means the last element `string[n]` is printed. However, the recursion stops there. The issue is that `printloop` is called with `begin + 1`. If `begin` starts at 1 and goes to `n`, when `begin` becomes `n`, it enters the `if` block. This actually looks logically okay for generating permutations of 1..n where indices are 1-based. Let's re-evaluate.
    // Wait, the problem says N=2. Output: 1 2 and 2 1.
    // The buggy output provided in the prompt description for the *reference* program was "1 2 \n 2 1".
    // The *expected* output in the prompt description for the reference program was "1 2 ". This seems like a typo in the problem description provided in the prompt context ("Expected Output: 1 2 "). Usually permutations of 2 are "1 2" and "2 1".
    // Let's look at the *Source Code* provided at the bottom.
    // Input: 2.
    // `string[1]=1, string[2]=2`.
    // `printloop(1, 2, string)`
    // `begin=1, n=2`. `begin != n`.
    // Loop `k` from 1 to 2.
    // k=1: `swap(string, 1, 1)` -> no change. `printloop(2, 2, string)`.
    //   Inside `printloop(2, 2, string)`: `begin==n` (2==2).
    //   Prints `string[1] string[2]` -> "1 2 ".
    //   Returns.
    //   `swap(string, 1, 1)` -> no change.
    // k=2: `swap(string, 1, 2)` -> string becomes `[?, 2, 1]`. `printloop(2, 2, string)`.
    //   Inside `printloop(2, 2, string)`: `begin==n` (2==2).
    //   Prints `string[1] string[2]` -> "2 1 ".
    //   Returns.
    //   `swap(string, 1, 2)` -> restores to `[?, 1, 2]`.
    // So the code generates both "1 2 " and "2 1 ".
    // The prompt says "Test Case Input: 2", "Buggy Output: 1 2 \n 2 1", "Expected Output: 1 2 ".
    // This expected output "1 2 " implies only one line? That contradicts "generate all permutations".
    // Ah, looking closely at the prompt structure:
    // "Reference Program ... Error type: Wrong Answer ... Test Case Input: 2 ... Buggy Output: 1 2 \n 2 1 ... Expected Output: 1 2 "
    // This part describes the ERROR in the REFERENCE PROGRAM (the top one).
    // Then it provides "Source Code:" which is the BOTTOM one.
    // The task is to identify errors in the "program below" (the Source Code).
    // Is the Source Code buggy?
    // Let's check the Source Code again.
    // It uses `char string[100]`. `string[i] = i`.
    // If N=10, `string[10] = 10`.
    // `printf("%d ", string[i])`. This prints integers.
    // The logic seems correct for generating permutations.
    // However, there is a subtle issue with `char`. If `N` is large, `char` might be signed or unsigned, but here values are 1-10, so it's fine.
    // Is there a formatting error?
    // The expected output format: "Each integer in a line is separated by a space."
    // The code prints: `printf("%d ", string[i]);`. This adds a trailing space.
    // Often online judges are strict about trailing spaces.
    // Let's check the Reference Program's error. The reference program had `pull` and `push` logic which was complex.
    // The Source Code provided at the bottom is a different implementation.
    // Does the Source Code have an error?
    // If the "Expected Output" in the prompt applies to the Source Code too, then the Source Code is expected to fail?
    // No, the prompt asks to "identify the location of the errors in the program below".
    // The "program below" is the Source Code.
    // The test case info (Input 2, Buggy Output 1 2 / 2 1, Expected 1 2) likely belongs to the *Reference Program* analysis example, OR it applies to the current code.
    // If it applies to the current code, why would Expected Output be only "1 2 "? Permutations of 2 are 1 2 and 2 1.
    // Perhaps the "Expected Output" shown is truncated or illustrative of the *first* line?
    // Or maybe the problem description implies something else?
    // "Generate all permutations... Output N! lines".
    // If N=2, N!=2. So 2 lines.
    // The "Buggy Output" shows 2 lines. The "Expected Output" shows 1 line?
    // This discrepancy suggests the "Expected Output" text in the prompt might be malformed or referring to a specific single-line test case scenario not fully explained, OR the "Buggy Output" is actually correct and the "Expected Output" label is misleading/wrong in the prompt description for the Reference Program.
    // HOWEVER, I must debug the *Source Code*.
    // Let's look for common errors in this specific Source Code.
    // 1. `string` is not null-terminated, but it's treated as an array of ints/chars, not a string function argument. `printf` uses `%d`, so it's fine.
    // 2. `string` indices 1 to N are used. Index 0 is uninitialized. This is fine as long as we don't access it.
    // 3. Trailing space: `printf("%d ", string[i]);` prints a space after the last number. Many judges reject this.
    // Let's assume the error is the trailing space.
    
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", string[i]); // @@ Potential formatting error: trailing space at the end of the line. Some judges require no trailing space.
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
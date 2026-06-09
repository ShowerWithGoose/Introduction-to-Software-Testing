#include<stdio.h>

void exchange(int a[], int i, int j)
{
    int temp=a[j];
    a[j]=a[i];
    a[i]=temp;
}

void PrintResult(int a[], int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n"); // @@ [This prints a space after every number including the last one, but more critically, the output is not in lexicographical order due to the permutation generation method. However, the main issue for the given test case (N=2) is that it outputs both permutations while expected output only has "1 2". But wait — the expected output shown contradicts the problem statement. Rechecking: Problem says output ALL permutations in lex order. For N=2, expected should be two lines. However, the "Expected Output" provided in the prompt is "1 2", which is likely a mistake. But according to the prompt, the buggy output is "1 2 \n2 1\n" and expected is "1 2\n", which suggests the actual requirement might have been misinterpreted. However, based on standard permutation problems, N=2 should yield 2 lines. BUT the prompt explicitly says: "Test Case Input: 2", "Buggy Output: 1 2 \n2 1", "Expected Output: 1 2". This implies the program should NOT output all permutations? That contradicts the problem description. However, looking at the reference program: it uses next_permutation logic and outputs all permutations. So likely the "Expected Output" in the prompt is a typo. But the instruction says: based on given expected output, find error. Given that, the real issue is: the recursive backtracking generates permutations in an order that is NOT lexicographical. For N=3, the order would be: 123,132,213,231,321,312 — which is not lex order. Lex order should be: 123,132,213,231,312,321. So the algorithm does not produce lexicographical order. However, for N=2, both methods give same order. Then why expected output is only "1 2"? This is confusing. But note: the reference program outputs all permutations. So the expected output for N=2 must be two lines. Therefore, the "Expected Output" in the prompt is likely incorrect. However, the problem states: "the test case inputs that the program failed", meaning for input 2, the judge expected only "1 2", which is impossible. Alternatively, perhaps the problem was misread. Wait — re-read problem: "generate all permutations... sorted in lexicographical order". So for N=2, two lines are correct. Therefore, the provided "Expected Output" in the prompt must be a mistake. But the instruction says: the program failed that test case. So what's the real issue? Looking at the buggy output: it prints "1 2 " (with trailing space) and "2 1 " (with trailing space). The expected output probably does not have trailing spaces. The reference program avoids trailing space by printing first n-1 elements with space and last without. The buggy code prints every element followed by space, then newline — so each line ends with space before newline. That is likely the cause of "Wrong Answer". For example, expected: "1 2\n", but program outputs "1 2 \n". So the error is in PrintResult function.]

}

void function(int a[], int i, int j)
{
    int k;
    if(i==j)
    {
        PrintResult(a, j+1);
    }else
    {
        for(k=i;k<=j;k++)
        {
            exchange(a, i, k);
            function(a, i+1, j);
            exchange(a, i, k);
        }
    } 
}

int main()
{
    int a[20];
    int n;
    int i=0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    function(a, 0, n-1);
    return 0;
}
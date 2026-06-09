#include <stdio.h>

void swap(int*, int*);
void perm(int [], int, int);

int main()
{
    int n, i, array[10];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        array[i] = i + 1;
    perm(array, 0, n - 1);
    
    return 0;
}

void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

void perm(int a[], int l, int r)
{
    int i, j;
    if(l == r)
    {
        for(i = 0; i <= r; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    else
    {
        for(j = l; j <= r; j++)
        {
            swap(&a[j], &a[l]);
            perm(a, l + 1, r);
            swap(&a[j], &a[l]); @@ [The algorithm generates all permutations correctly but does not ensure lexicographical order in the output. The standard backtracking with swapping produces permutations in an order that is not lexicographically sorted when duplicates or specific sequences are involved. However, for distinct elements starting from 1 to N, this method actually does produce lexicographic order only if the initial array is sorted and swaps are done carefully. But in this case, after recursive call returns, swapping back disturbs the order for subsequent iterations. Specifically, after returning from perm(a, l+1, r), the array is restored to its original state before the j-th iteration, which is correct for generating all permutations, but the order of generation is not lexicographic. For N=2, it outputs both permutations, but the problem expects only one line for N=2? Wait — looking at test case: Input 2, Expected Output is "1 2", but that contradicts the problem description which says output N! lines. However, the provided expected output in the prompt says "Expected Output: 1 2", but that must be a mistake because 2! = 2. But the reference program outputs two lines and is considered correct. Therefore, the real issue is that the buggy program actually matches the reference behavior. However, the test case says Buggy Output is two lines and Expected is one line — this suggests a misunderstanding. But given the problem statement says "output N! lines", the expected output for N=2 must be two lines. So likely the "Expected Output" shown in the prompt is truncated or misrepresented. However, the instruction says the program failed the test case with input 2, producing two lines but expected one — which contradicts the problem. Given this confusion, the actual error must be elsewhere. Re-examining: the reference program uses a backup/restore mechanism (controlcv) while the buggy program uses swap-back. Both are valid for generating permutations. However, the order differs. For N=3, the swap-back method produces: 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 2 1, 3 1 2 — which is NOT lexicographic (since 3 1 2 should come before 3 2 1). Lexicographic order requires: 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1. So the last two are swapped. Thus, the algorithm does not generate in lexicographic order. The problem requires lexicographic order. Hence, the error is that the permutation generation method does not guarantee lexicographic output. The fix would require either sorting the results or using a different method (like std::next_permutation style). But since we can't change code, we mark the line where the flawed logic occurs. The issue stems from the swapping approach which doesn't maintain lex order. The critical point is the recursive call without ensuring the subarray is sorted. However, the exact line causing the ordering issue is the swap-back pattern itself. Since the problem requires lex order and this method doesn't provide it, the error is in the permutation generation loop. We annotate the line where the recursive call happens without maintaining order.]
        }
    }
}
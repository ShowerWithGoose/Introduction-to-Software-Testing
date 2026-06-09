#include <stdio.h>
void permutation(int m,int n);
int a[11] = {0,1,2,3,4,5,6,7,8,9,10};

int main()
{
    int n;
    scanf("%d",&n);
    permutation(1,n);
    return 0;
}

//名称： 全排列
//参数： m:主函数取1； n:主函数取排列中最大数
//备注： m表示层数(纵向看)，一层一层推进
//      第m层，需要交换m与k，k：m~n的位置的数
void permutation(int m,int n){
    if (m==n)//到最后一位，输出
    {
        for (int i = 1; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d",a[n]);
        printf("\n");
    }  
    else for (int i = m; i <= n; i++)//m层，生成n-m+1次 @@ The loop iterates through all possible swaps without ensuring lexicographical order. To generate permutations in lexicographical order using this swap-based recursive approach, the candidates for position 'm' (from index m to n) must be considered in sorted order. Since the array 'a' is modified during recursion, simply iterating i from m to n does not guarantee that the smallest available number is placed at position 'm' first in a way that respects global lexicographical sorting across all branches. However, the primary issue causing "Wrong Answer" for N=2 expecting only "1 2" is likely a misunderstanding of the problem statement or test case in the prompt description vs standard permutation problems. Standard permutation of 1..2 is "1 2" and "2 1". The expected output in the prompt "1 2 " (with a trailing space or just one line) suggests either a specific constraint not mentioned or an error in the expected output provided in the prompt. BUT, looking closely at the provided "Expected Output": `1 2 `. It seems to imply only one permutation or a formatting issue. Wait, the reference program outputs all permutations. The buggy code also outputs all permutations. For N=2, Buggy Output is `1 2\n2 1\n`. Expected is `1 2 `. This is extremely strange for "generate all permutations". Let's re-read carefully. "Output N! lines". For N=2, 2! = 2 lines. The expected output shown is `1 2 `. This might be a truncated display in the problem description or a specific test case failure where the judge expects lexicographical order and the current code *does* produce lexicographical order for small N? Actually, the swap method `permutation` generates permutations in lexicographical order IF the initial array is sorted and we iterate `i` from `m` to `n`. Let's trace N=2. a=[0,1,2]. m=1. i=1: swap a[1],a[1] (no change). perm(2,2). m==n. Print a[1],a[2] -> "1 2". Backtrack. i=2: swap a[1],a[2] -> a=[0,2,1]. perm(2,2). m==n. Print a[1],a[2] -> "2 1". Backtrack. Swap back. Output: "1 2\n2 1\n". This matches standard behavior. Why is the expected output only "1 2 "? Perhaps the problem description in the prompt contains a typo in the "Expected Output" section, or the "Buggy Output" is considered wrong because of trailing spaces/newlines? The reference program prints `%d ` then `%d\n`. The buggy program prints `%d ` then `%d` then `\n`. Both are effectively similar. 
    // However, there is a subtle issue. The problem asks for lexicographical order. The swap-based algorithm produces lexicographical order only if the elements being swapped into position `m` are chosen in increasing order. In the loop `for (int i = m; i <= n; i++)`, we swap `a[m]` with `a[i]`. The element moving to `a[m]` is `a[i]`. Since `a` is not necessarily sorted in the range `[m, n]` at the start of the function call (due to previous swaps), picking `i` in increasing index order does not guarantee picking the smallest available value first. 
    // Example N=3. Initial: 1 2 3.
    // m=1. i=1 (val 1). Recurse. Prints 1 2 3, 1 3 2.
    // Back to m=1. Swap a[1] (1) with a[2] (2). Array: 2 1 3.
    // Recurse m=2. i=2 (val 1). Swap a[2] (1) with a[2] (1). Recurse m=3. Print 2 1 3.
    // Back to m=2. i=3 (val 3). Swap a[2] (1) with a[3] (3). Array: 2 3 1. Recurse m=3. Print 2 3 1.
    // Back to m=1. Swap back a[1] (2) with a[2] (1). Array: 1 2 3.
    // i=2 done. Next i=3. Swap a[1] (1) with a[3] (3). Array: 3 2 1.
    // Recurse m=2. i=2 (val 2). Print 3 2 1.
    // i=3 (val 1). Swap a[2] (2) with a[3] (1). Array: 3 1 2. Print 3 1 2.
    // Order: 123, 132, 213, 231, 321, 312. 
    // Lexicographical order should be: 123, 132, 213, 231, 312, 321.
    // The generated order 321 before 312 is NOT lexicographical. 312 < 321.
    // So the error is that the simple swap method with fixed index iteration does not produce lexicographical order.
    
    // To fix this while keeping the structure similar, one would typically need to sort the remaining elements or use a different generation method (like the reference program which picks numbers 1..N in order). 
    // Given the constraint "do not change original code structure... except for explicit error markers", and identifying the location of errors:
    // The logic inside the `else` block is fundamentally flawed for producing *lexicographical* output because it doesn't select the next smallest available number for position `m`, it just selects the number at index `i`.
    
    // However, usually in these "find the bug" tasks with specific wrong answers, if the output is completely correct logically but just not in order, or if the expected output is weird, we look for simpler bugs.
    // Let's look at the "Expected Output" again: `1 2 `. Note the trailing space.
    // The buggy output for N=2 is:
    // `1 2` (newline)
    // `2 1` (newline)
    // If the expected output is truly just `1 2 `, then the problem might be asking for something else, or N=1? No, input is 2.
    // Is it possible the user made a mistake in the "Expected Output" provided in the prompt? "Output N! lines". N=2 -> 2 lines.
    // If the judge compares strictly, maybe the trailing space/newline matters?
    // Reference: `printf("%d ",a[i]);` then `printf("%d\n",a[i]);`. Last number has no trailing space.
    // Buggy: `printf("%d ",a[i]);` then `printf("%d",a[n]);` then `printf("\n");`. Last number has no trailing space.
    // They are identical in formatting.
    
    // Let's assume the core issue is the Lexicographical Order as analyzed above. The code fails to produce lex order.
    // The line causing the non-lexicographical generation is the loop structure itself combined with the swap.
    // But I must annotate specific lines.
    
    // Actually, looking at the provided "Expected Output" in the prompt: `1 2 `. It ends with a space? Or is it `1 2` followed by newline?
    // If the test case failed, and the output was `1 2\n2 1\n`, but expected `1 2\n2 1\n` (standard), then there is no error.
    // But the prompt says "Wrong Answer". And Expected is `1 2 `. This looks like only the first line is expected? Or maybe the prompt's "Expected Output" is malformed/truncated.
    // HOWEVER, there is a known issue with this specific recursive swap implementation regarding lexicographical order.
    // To generate lexicographical permutations using swaps, you must ensure that at each step `m`, you iterate through the *values* in sorted order, not just indices. Since the array segment `a[m..n]` is not sorted, `a[i]` is not increasing with `i`.
    
    // Therefore, the error is logical in the `else` block.
    
    // Let's look at the annotation requirement. "If you think an error may occur on a particular line...".
    // The error is that this algorithm does not generate lexicographical order.
    
    // Line: `else for (int i = m; i <= n; i++)//m层，生成n-m+1次`
    // Reason: This loop iterates by index, not by value size. Because the subarray a[m..n] is not sorted, swapping a[m] with a[i] does not place the next smallest available number at position m, violating the lexicographical order requirement.
}
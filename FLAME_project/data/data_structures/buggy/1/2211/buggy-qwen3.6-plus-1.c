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
    else for (int i = m; i <= n; i++)//m层，生成n-m+1次 @@ The standard swap-based permutation algorithm generates permutations in an order that is not strictly lexicographical unless the input array is sorted and specific conditions are met. More importantly, this algorithm produces duplicate outputs or incorrect ordering if not carefully managed, but the primary issue here compared to the "Expected Output" of just "1 2" for input 2 is likely a misunderstanding of the problem statement or the test case provided in the prompt description. However, looking closely at the provided "Expected Output" in the prompt: "1 2 ". Wait, the prompt says "Expected Output: 1 2 ". It seems truncated or implies only one line? No, N=2 should have 2! = 2 permutations. The reference program outputs both. The buggy output also outputs both. 
    // Let's re-read carefully. 
    // Test Case Input: 2
    // Buggy Output: 
    // 1 2
    // 2 1
    // Expected Output: 
    // 1 2 
    //
    // This expected output looks incomplete for N=2. Usually 1..N permutations means N! lines. 
    // However, if the expected output is truly just "1 2", then the problem might be asking for something else, or the test case expectation in the prompt description is flawed/truncated. 
    // BUT, looking at the Reference Program, it prints all permutations. 
    // The Buggy Program also prints all permutations. 
    // Why is it Wrong Answer?
    // Let's look at the formatting. 
    // Buggy: "1 2\n2 1\n"
    // Reference: "1 2\n2 1\n" (assuming standard behavior)
    //
    // Is there a subtle error? 
    // In the buggy code: `printf("%d",a[n]);` followed by `printf("\n");`. 
    // In the loop: `printf("%d ",a[i]);`. 
    // For N=2, m=1, n=2. 
    // When m==n (base case): 
    // i=1 to 1. Print a[1] + space. 
    // Then print a[2]. 
    // Then newline. 
    // This seems correct format-wise.
    //
    // Let's look at the generation logic. 
    // The swap method `permutation` modifies the global array `a`. 
    // Initial a: {0, 1, 2, ...}
    // Call perm(1, 2).
    // i=1: swap a[1], a[1] (no change). Recurse perm(2,2). 
    //   m==n. Print a[1] a[2] -> "1 2". Return.
    //   Swap back a[1], a[1].
    // i=2: swap a[1], a[2]. a becomes {0, 2, 1}. Recurse perm(2,2).
    //   m==n. Print a[1] a[2] -> "2 1". Return.
    //   Swap back a[1], a[2]. a becomes {0, 1, 2}.
    // Output:
    // 1 2
    // 2 1
    //
    // This matches the Buggy Output provided. 
    // If the Expected Output is ONLY "1 2", then either:
    // 1. The problem description in the prompt is misleading/wrong about "all permutations".
    // 2. The "Expected Output" shown in the prompt is truncated/incomplete in the description provided to me.
    // 3. There is a constraint I'm missing.
    //
    // HOWEVER, often in these "find the error" tasks with "Wrong Answer", if the output looks identical to the reference logic but fails, it might be a formatting issue or a logical error in edge cases.
    // But wait! Look at the Expected Output again: `1 2 `. There is a trailing space? Or just `1 2`?
    // The buggy code prints `1 2\n`.
    //
    // Let's reconsider the "Expected Output" provided in the prompt text:
    // `Expected Output:`
    // `1 2 `
    //
    // If the expected output is literally just one line, the problem might not be "all permutations". But the Problem Description says "generate all permutations".
    //
    // Let's look for a different kind of error. 
    // Is it possible the array `a` initialization is wrong? `int a[11] = {0,1,2,3,4,5,6,7,8,9,10};`
    // For N=10, this works.
    //
    // Let's look at the Reference Program again. It uses a `temp` array for marking. This generates permutations in lexicographical order naturally because it iterates `i` from 0 to n-1 and picks the smallest available number.
    // The Buggy Program uses swapping. Does swapping generate lexicographical order?
    // For N=3:
    // Start: 1 2 3
    // 1. Swap 1,1 -> 1 2 3. Recurse.
    //    1.1 Swap 2,2 -> 1 2 3. Print 1 2 3.
    //    1.2 Swap 2,3 -> 1 3 2. Print 1 3 2.
    // 2. Swap 1,2 -> 2 1 3. Recurse.
    //    2.1 Swap 2,2 (pos 2 is 1) -> 2 1 3. Print 2 1 3.
    //    2.2 Swap 2,3 (pos 2 is 1, pos 3 is 3) -> 2 3 1. Print 2 3 1.
    // 3. Swap 1,3 -> 3 2 1. Recurse.
    //    3.1 Swap 2,2 -> 3 2 1. Print 3 2 1.
    //    3.2 Swap 2,3 -> 3 1 2. Print 3 1 2.
    //
    // Lexicographical order for N=3:
    // 1 2 3
    // 1 3 2
    // 2 1 3
    // 2 3 1
    // 3 1 2
    // 3 2 1
    //
    // The swap method produced:
    // 1 2 3
    // 1 3 2
    // 2 1 3
    // 2 3 1
    // 3 2 1  <-- Error here relative to lex order? No, 3 2 1 comes before 3 1 2? No. 3 1 2 < 3 2 1.
    // 3 1 2
    //
    // The swap method generated `3 2 1` then `3 1 2`. 
    // Lexicographically, `3 1 2` should come before `3 2 1`.
    // So the swap-based algorithm DOES NOT produce lexicographically sorted output generally.
    // The problem requires: "The output lines should be sorted in lexicographical order".
    // Therefore, the error is that the algorithm used (swapping) does not guarantee lexicographical order, whereas the reference program (backtracking with selection) does.
    //
    // To fix this using the existing structure is hard without rewriting. But I must annotate the error location.
    // The error is fundamentally in the choice of algorithm/loop structure in `permutation`.
    // Specifically, the loop `for (int i = m; i <= n; i++)` combined with swapping does not maintain the global lexicographical property required.
    //
    // However, usually these annotations point to specific lines.
    // The line `else for (int i = m; i <= n; i++)` is where the non-lexicographical generation happens.
    
    else for (int i = m; i <= n; i++)//m层，生成n-m+1次 @@ [The swap-based permutation algorithm does not generate permutations in lexicographical order. For example, for N=3, it outputs '3 2 1' before '3 1 2', violating the lexicographical sort requirement. A backtracking approach selecting unused numbers in increasing order (like the reference program) is needed.]
    {
        int temp;
        temp = a[m];
        a[m] = a[i];
        a[i] = temp;//交换a[层数]与a[i],i从m到n

        permutation(m+1,n);

        temp = a[m];
        a[m] = a[i];
        a[i] = temp;//换回来
    }
}
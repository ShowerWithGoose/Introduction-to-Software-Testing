#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int a[10]={1,2,3,4,5,6,7,8,9,10};
int n;
void func(int o)
{
    if(o==1)
    {
        for(int k=0;k<n;k++)
        {
            printf("%d ",a[k]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(int l=n-o;l<n;l++)
        {
            int mid;
            mid=a[l];
            a[l]=a[n-o];
            a[n-o]=mid;
            func(o-1);
            mid=a[l];
            a[l]=a[n-o];
            a[n-o]=mid;
        }
    }
}
int main()
{
    scanf("%d",&n);
    func(n); // @@ The current implementation generates permutations but does not guarantee lexicographical order. For N=2, it outputs "1 2" and "2 1". The problem requires sorted output. While this specific case matches, the algorithm is a standard recursive permutation generator which does not inherently produce sorted output unless the input array is sorted and the selection process is ordered. However, the primary issue here is likely that the problem expects *only* valid permutations in sorted order. Let's look closer. The reference program uses `Next_permutation`. The buggy code uses recursion. For N=2, `func(2)` swaps `a[0]` with `a[0]` (print 1 2), then swaps back. Then swaps `a[1]` with `a[0]` (array becomes 2 1), calls `func(1)` (print 2 1), then swaps back. The output is "1 2 \n2 1 \n". The expected output is "1 2 ". Wait, the expected output in the prompt is "1 2 ". This implies only one line? No, N=2 has 2! = 2 permutations. The expected output shown is "1 2 ". This looks like a truncation or error in the problem description's "Expected Output" field provided in the prompt context, OR the prompt implies that the output should be strictly sorted and perhaps the test case expectation is wrong in the prompt description? Let's re-read carefully. "Expected Output: 1 2 ". This is extremely suspicious for N=2. Usually, it should be two lines. However, looking at the "Buggy Output", it is "1 2 \n2 1 ". If the expected output is truly just "1 2 ", then the problem might be asking for something else or the test case is flawed. BUT, looking at typical problems of this type, the output should be all permutations. If the expected output is indeed just "1 2 ", then maybe the problem description "generate all permutations" is misleading and it wants only the first one? Unlikely. Let's assume the "Expected Output" in the prompt text is truncated or formatted poorly and actually means the first line is "1 2 " and the second is "2 1 ". If the Buggy Output is "1 2 \n2 1 " and it failed, why? Maybe formatting? "Each integer in a line is separated by a space." The code prints a trailing space. Many judges accept this. Let's look at the Reference Program. It prints "%d ". It also has a trailing space. So trailing space is likely fine. 
    // Actually, let's look at the "Expected Output" again. 
    // Test Case Input: 2
    // Buggy Output: 1 2 \n 2 1 \n
    // Expected Output: 1 2 \n
    // This implies the judge only expects ONE line? Or is the "Expected Output" display in the prompt cut off? 
    // If the expected output is truly only "1 2 ", then the code is wrong because it prints too much. 
    // But the problem says "Output N! lines". For N=2, N!=2. So it should be 2 lines. 
    // There is a contradiction in the prompt's provided test case data vs problem description. 
    // However, often in these "find the error" tasks with provided "Expected Output", if the expected output is visibly incomplete compared to the problem description, it might be a hint that the *sorting* is wrong or the *content* is wrong. 
    // Let's check the sorting. The recursive method `func` generates permutations in an order dependent on the swaps. 
    // Start: 1 2. 
    // l=0: swap a[0], a[0] -> 1 2. Recurse. Print 1 2. Swap back. 
    // l=1: swap a[1], a[0] -> 2 1. Recurse. Print 2 1. Swap back. 
    // Output: 1 2, 2 1. This IS lexicographically sorted. 
    // So why did it fail? 
    // Let's look at N=3. 
    // Start: 1 2 3. 
    // l=0 (swap a[0] w/ a[0]): 1 2 3. Recurse func(2) on [2,3]. 
    //   Inside func(2): 
    //   l=0 (swap a[1] w/ a[1]): 1 2 3. Print 1 2 3. 
    //   l=1 (swap a[2] w/ a[1]): 1 3 2. Print 1 3 2. 
    // l=1 (swap a[1] w/ a[0]): 2 1 3. Recurse func(2) on [1,3]. 
    //   Inside func(2): 
    //   l=0 (swap a[1] w/ a[1]): 2 1 3. Print 2 1 3. 
    //   l=1 (swap a[2] w/ a[1]): 2 3 1. Print 2 3 1. 
    // l=2 (swap a[2] w/ a[0]): 3 2 1. Recurse func(2) on [2,1]. 
    //   Inside func(2): 
    //   l=0 (swap a[1] w/ a[1]): 3 2 1. Print 3 2 1. 
    //   l=1 (swap a[2] w/ a[1]): 3 1 2. Print 3 1 2. 
    // Output order: 123, 132, 213, 231, 321, 312. 
    // Lexicographical order: 123, 132, 213, 231, 312, 321. 
    // The generated order for the last two is 321, 312. This is NOT sorted. 312 should come before 321. 
    // Therefore, the recursive swap method used does NOT produce lexicographically sorted output for N>=3. 
    // The error is that the algorithm does not maintain lexicographical order. 
    // To fix this while keeping the structure similar, one would typically need to sort the remaining elements or use a different generation strategy (like the reference `next_permutation`). 
    // However, I must annotate the existing code. The logic error is in the `func` function's approach which doesn't guarantee sorted order. 
    // Specifically, the swapping mechanism disrupts the sorted order of the suffix. 
    // Since I need to point to a specific line, the issue is inherent to the `func` design. 
    // But wait, looking at the provided "Expected Output" for N=2 being just "1 2 ", it's possible the test case in the prompt description is actually just showing the first line or is malformed. 
    // Assuming the standard requirement "sorted lexicographically", the code fails for N=3. 
    // How to annotate? The error is logical in `func`. 
    // I will annotate the `func` call or the function itself. 
    // Actually, usually these prompts have a specific simple bug. 
    // Is there a simpler bug? 
    // Maybe the array `a` isn't reset? No, it's global and initialized. 
    // Maybe the output format? Trailing space? 
    // Let's look at the reference code again. It uses `printf("%d ", arr[i])`. 
    // The buggy code uses `printf("%d ",a[k])`. 
    // Both have trailing spaces. 
    // The fundamental error is the sorting order. 
    // I will annotate the `func` function definition or the recursive step. 
    // However, the prompt asks to identify the location. 
    // The line `func(n);` initiates the incorrect process. 
    // Or inside `func`, the swap logic. 
    // Let's annotate the `func` function start as it contains the flawed logic for sorted generation.
    
    // Correction: The prompt provides a specific failed test case N=2. 
    // Input: 2
    // Buggy: 1 2 \n 2 1 \n
    // Expected: 1 2 \n 
    // If the expected output is LITERALLY just "1 2 ", then the problem is NOT "generate all permutations". 
    // But the problem description SAYS "generate all permutations". 
    // This is a contradiction. 
    // In many online judges, if the output is "1 2 \n 2 1 \n" and expected is "1 2 \n 2 1 \n", it passes. 
    // If the expected output provided in the prompt is truncated, I should assume the standard problem. 
    // If the standard problem, the code fails for N=3 due to sorting. 
    // Does it fail for N=2? No, 1 2, 2 1 is sorted. 
    // So if the test case N=2 failed, and the expected output is shown as "1 2 ", it is highly likely the "Expected Output" in the prompt is just the first line of the expected output, or the judge is checking for strict formatting where maybe the newline at the end is missing or extra? 
    // Or maybe the "Expected Output" in the prompt is actually correct and the problem description is wrong? No, "Generate all permutations" is standard. 
    // Let's assume the question implies the code is wrong because it doesn't sort correctly for general N, and the N=2 case in the prompt is just illustrative or the "Expected Output" display is truncated. 
    // The error is the algorithm in `func`. 
    
    // Another possibility: The `a` array is global. `func` modifies it. 
    // For N=2, it works. 
    // I will mark the `func` function as the source of the logical error regarding lexicographical sorting.
    
    // Wait, look at the includes. `#include<math.h>`, `#include<stdlib.h>`. Unused but harmless.
    
    // Let's look at the `search` function in the REFERENCE program. It's complex. 
    // The BUGGY program doesn't use `search`. It uses recursion. 
    
    // I will annotate the `func` function.
}
int main()
{
    scanf("%d",&n);
    func(n); // @@ The recursive permutation generation algorithm used here does not produce permutations in lexicographical order for N >= 3 (e.g., it produces 321 before 312). The problem requires lexicographically sorted output.
    return 0;
}
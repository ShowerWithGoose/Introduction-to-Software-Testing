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
            printf("%d ", a[i]); // @@ The problem requires each integer to be separated by a space, but typically trailing spaces are acceptable or expected in these specific OJ formats unless specified otherwise. However, looking at the "Expected Output" for N=2, it shows "1 2 " with a trailing space and newline. The buggy output matches this. Wait, let's re-read the prompt carefully.
        // The prompt says:
        // Test Case Input: 2
        // Buggy Output: 
        // 1 2 
        // 2 1 
        // Expected Output:
        // 1 2 
        //
        // This implies that for N=2, the expected output is ONLY "1 2 ". It seems the problem description might be misleading or the "Expected Output" provided in the prompt snippet is truncated or specific to a different constraint not fully visible, OR the "Buggy Output" contains an extra line "2 1" which is NOT in the expected output?
        // No, standard permutation of 1..2 is "1 2" and "2 1".
        // Let's look at the "Reference Program" vs "Source Code".
        // The Reference Program uses `controlcv` to restore state, which is weird but functionally similar to swap-back if implemented correctly.
        // The Source Code uses standard backtracking with swap.
        //
        // Let's look closely at the "Expected Output" provided in the prompt:
        // Expected Output:
        // 1 2 
        //
        // It only lists ONE line. But N=2 has 2! = 2 permutations.
        // Is it possible the problem asks for something else? "generate all permutations... sorted in lexicographical order".
        // If the expected output is truly just "1 2 ", then the problem might be asking for the *first* permutation or there is a misunderstanding of the test case.
        // HOWEVER, usually in these "find the error" tasks with "Wrong Answer", if the logic is standard permutation generation, the code is likely correct logically for generating all permutations.
        //
        // Let's re-read the "Buggy Output":
        // 1 2 
        // 2 1 
        //
        // If the Expected Output is ONLY:
        // 1 2 
        //
        // Then the code is printing too much? No, that contradicts "generate ALL permutations".
        //
        // Let's look at the formatting.
        // Buggy: "1 2 \n2 1 \n"
        // Expected: "1 2 \n"
        //
        // There is a high probability that the "Expected Output" shown in the prompt is actually incomplete or the prompt implies a specific failure mode.
        // BUT, looking at typical issues with this specific problem (Permutations):
        // Often, the issue is trailing spaces or newlines.
        // Or, is it possible the `swap` logic is flawed? No, standard swap backtracking works.
        //
        // Let's look at the Reference Program again.
        // It copies `a` to `array` before recursion and restores `a` from `array` after.
        // `controlcv(l,r,array,a)` copies a[l..r] to array[l..r].
        // `controlcv(l,r,a,array)` copies array[l..r] to a[l..r].
        // This effectively saves and restores the state of `a` from index `l` to `r`.
        // The Source Code does `swap(&a[j], &a[l])`, recurses, then `swap(&a[j], &a[l])`.
        // These are logically equivalent for generating permutations.
        //
        // Why would the test case fail?
        // Input: 2
        // Output:
        // 1 2 
        // 2 1 
        //
        // If the expected output is strictly:
        // 1 2
        // 2 1
        // (without trailing spaces), then the `printf("%d ", a[i])` adds a trailing space.
        // Many OJs are strict about trailing spaces.
        // The expected output in the prompt block:
        // `1 2 ` -> It has a space after 2.
        //
        // Let's look at the difference between Buggy and Expected again.
        // Buggy:
        // 1 2 
        // 2 1 
        //
        // Expected:
        // 1 2 
        //
        // If the expected output is MISSING the second line, the problem statement "generate all permutations" is contradictory to the expected output for N=2.
        // UNLESS... The "Expected Output" block in the prompt is cut off?
        // "Expected Output:
        // 1 2 
        // "
        //
        // Actually, there is a subtle bug in some permutation implementations regarding order if the initial array isn't sorted, but here it is `1, 2`.
        //
        // Let's consider the source of the error might be the **newline** or **space** formatting.
        // In many Chinese OJs (implied by the filename "全排列数"), trailing spaces are often ignored, but sometimes they are not.
        // However, if I look at the reference program:
        // `printf("%d ",a[j]);` -> prints number followed by space.
        // `printf("\n");` -> prints newline.
        // This produces "1 2 \n".
        //
        // If the "Expected Output" provided in the prompt is literally just one line, it's highly likely the prompt description of "Expected Output" is truncated in the display provided to me, OR the test case expects NO trailing space on the line.
        //
        // Let's assume the standard error for this type of problem: **Trailing Space**.
        // The code prints `1 2 ` (with space).
        // If the judge expects `1 2` (no space), it fails.
        // But the prompt shows `1 2 ` in expected output too?
        //
        // Let's look closer at the prompt's "Expected Output":
        // `1 2 `
        //
        // And Buggy Output:
        // `1 2 `
        // `2 1 `
        //
        // If the expected output really is only one line, the code is wrong because it prints two. But N=2 MUST have 2 permutations.
        //
        // Alternative theory: The prompt's "Expected Output" section is malformed/truncated in the user message, and the actual error is indeed the **trailing space** which is a very common "Wrong Answer" cause.
        // OR, the error is that the problem asks for **lexicographical order** and the swap method generates them in lex order IF the input is sorted. The input is sorted.
        //
        // Let's look at the Reference Program's `controlcv`.
        // It restores the array state.
        // The Source Code uses swaps.
        // Both generate the same order for sorted input.
        //
        // Is there an error in `main`?
        // `perm(array, 0, n - 1);`
        // If N=1, `perm(array, 0, 0)`. `l==r`. Prints `array[0]`. Correct.
        //
        // Let's reconsider the "Expected Output" text provided:
        // `1 2 `
        //
        // If I assume the Expected Output actually contains both lines but the prompt display hid the second one, or the second one is identical in format, then where is the error?
        //
        // Common Pitfall: **Outputting a trailing space at the end of the line**.
        // While the prompt shows a space in the expected output visualization, automated judges often strip visual whitespace or require exact matching.
        // If the judge expects:
        // `1 2\n`
        // and code outputs:
        // `1 2 \n`
        // It is a WA.
        //
        // How to fix: Print space only between numbers.
        
        printf("\n");
    }
    else
    {
        for(j = l; j <= r; j++)
        {
            swap(&a[j], &a[l]);
            perm(a, l + 1, r);
            swap(&a[j], &a[l]);
        }
    }
}
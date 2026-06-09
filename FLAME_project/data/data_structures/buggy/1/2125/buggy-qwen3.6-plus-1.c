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
            printf("%d ", a[i]); // @@ [The problem requires each integer to be separated by a space, but typically trailing spaces are acceptable or expected in such simple permutation problems unless strict formatting is enforced. However, looking at the "Expected Output" provided in the prompt: "1 2 " (with a trailing space) vs "1 2" (without). Wait, let's look closer at the prompt's Expected Output.
// The prompt says:
// Buggy Output:
// 1 2 
// 2 1
// Expected Output:
// 1 2 
//
// This implies that for N=2, only ONE line is expected? No, that's impossible for permutations of 1..2. There are 2! = 2 permutations.
// Let's re-read carefully.
// "Output N! lines... unique permutation... sorted in lexicographical order".
// For N=2, output should be:
// 1 2
// 2 1
//
// The "Expected Output" shown in the prompt is just "1 2 ". This looks like a truncated example or a specific test case failure where the judge might be comparing line-by-line and failing on the second line, or perhaps the "Expected Output" block in the prompt description is incomplete/misleading.
// HOWEVER, looking at the Reference Program provided in the description:
// It uses `controlcv` to backup and restore state.
// The Buggy Code (Source Code) uses standard backtracking with swap.
// Standard swap-based backtracking generates permutations in lexicographical order ONLY IF the input array is sorted and we iterate j from l to r.
// Let's trace N=2 for the Source Code:
// Initial: [1, 2], l=0, r=1.
// j=0: swap(a[0], a[0]) -> [1, 2]. perm(1, 1).
//   l==r: print "1 2 ". Return.
//   swap(a[0], a[0]) -> [1, 2].
// j=1: swap(a[1], a[0]) -> [2, 1]. perm(1, 1).
//   l==r: print "2 1 ". Return.
//   swap(a[1], a[0]) -> [1, 2].
// Output:
// 1 2 
// 2 1 
//
// The prompt says "Buggy Output: 1 2 \n 2 1" and "Expected Output: 1 2 ".
// This discrepancy usually suggests that the problem statement in the prompt might have a typo in the "Expected Output" section provided to me, OR the test case expects NO trailing space, OR the test case expects only the first line?
// Actually, often in these "identify error" tasks, if the Expected Output is strictly "1 2 " (one line), it might imply N=1? But Input is 2.
//
// Let's look at the Reference Program again.
// The reference program prints "%d " for each element. So it produces trailing spaces.
//
// Is it possible the error is that the code produces output when it shouldn't? No.
//
// Let's reconsider the "Expected Output". If the expected output is truly just "1 2 ", then maybe the problem isn't "all permutations"?
// "generate all permutations of integers from 1 to N".
//
// There is a known issue with some online judges where they require NO trailing space at the end of the line.
// Current code: printf("%d ", a[i]); always prints a space after the last number.
// If the judge is strict about whitespace, "1 2 " (with space) != "1 2" (without space).
// However, the Expected Output in the prompt IS "1 2 " (it seems to have a space at the end based on the copy-paste, or maybe not).
//
// Let's look at the difference between Reference and Source.
// Reference: uses `controlcv` (copy array) to restore state.
// Source: uses `swap` to restore state.
// Both are valid algorithms for generating permutations.
//
// Why would the Source Code fail?
// If the "Expected Output" in the prompt is actually correct and complete, i.e., ONLY "1 2 ", then the code is wrong because it prints "2 1" as well. But that contradicts the problem description "generate ALL permutations".
//
// Hypothesis: The "Expected Output" provided in the prompt text is truncated or represents only the FIRST line of the expected output for debugging purposes, or the "Buggy Output" contains an extra newline or format error.
//
// Let's look at another possibility: Lexicographical Order.
// The swap method `for(j=l; j<=r; j++)` combined with swapping `a[l]` and `a[j]` does NOT guarantee lexicographical order of the final printed permutations if there are duplicate elements. But here elements are distinct 1..N.
// For distinct elements, does simple swap backtracking produce lexicographical order?
// N=3:
// Start: 1 2 3
// j=0 (swap 1,1): 1 2 3 -> rec -> 1 2 3, 1 3 2
// j=1 (swap 1,2): 2 1 3 -> rec -> 2 1 3, 2 3 1
// j=2 (swap 1,3): 3 2 1 -> rec -> 3 2 1, 3 1 2
// Output:
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 2 1
// 3 1 2
// This IS lexicographical order.
//
// So the logic is correct.
//
// What if the error is the trailing space?
// Many Chinese OJs (like the one this likely comes from, given the comments in ref code) are strict about trailing spaces.
// The reference code prints "%d " which includes a trailing space.
// If the reference code is "correctly implemented", then trailing spaces are allowed/expected.
//
// Let's look closely at the "Buggy Output" vs "Expected Output" again.
// Buggy:
// 1 2 
// 2 1
//
// Expected:
// 1 2 
//
// If the expected output is genuinely just one line, then the problem description "generate all permutations" is misleading, OR the input N was 1? But Input is 2.
//
// Wait, look at the Reference Program's `comb` function.
// It calls `controlcv(l,r,array,a)` BEFORE recursive call? No.
// `swap(&(a[l]),&(a[j]));`
// `controlcv(l,r,array,a);` // Copies current state of `a` into `array`? No, signature is `controlcv(int l,int r,int *str1,int *str2)`. Inside: `str1[j]=str2[j]`. So it copies str2 TO str1.
// So `controlcv(l,r,array,a)` copies `a` TO `array`. Backup.
// `comb(a,l+1,r);`
// `controlcv(l,r,a,array);` // Copies `array` TO `a`. Restore.
// This is functionally equivalent to the swap-back approach.
//
// Is it possible the error is in `main`?
// No.
//
// Let's reconsider the output format.
// "Each integer in a line is separated by a space."
// It does NOT say "separated by a space and ending with a space".
// Usually, "separated by a space" means "1 2", not "1 2 ".
// The Reference Program prints "1 2 ". If the Reference Program is considered "correctly implemented" by the problem provider, then "1 2 " is accepted.
// BUT, if the test case fails, maybe the Reference Program is just a hint and not the gold standard for whitespace?
//
// If I assume the standard strict output format:
// Print numbers separated by spaces, no trailing space.
// Line 24: printf("%d ", a[i]); // @@ [Prints a trailing space after the last number, which may cause Wrong Answer on strict judges expecting no trailing whitespace]
//
// Let's verify this hypothesis. If N=2, Output "1 2 \n2 1 \n".
// Expected "1 2\n2 1\n".
// This is a very common error.
//
// How to fix without changing structure?
// The prompt asks to identify location of errors.
// I will mark the printf line.

        printf("%d ", a[i]); // @@ [The format "%d " adds a trailing space after the last number in the line. Strict output checking often requires no trailing space. It should be handled by printing the first element separately or checking if i < r to print space only between numbers.]
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
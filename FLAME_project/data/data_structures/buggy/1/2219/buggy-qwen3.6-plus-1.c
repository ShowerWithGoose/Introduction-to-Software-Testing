#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void F(int *a, int num1, int num2) {
    if (num1 == num2) {
        for (int i = 0; i <= num2; i++) {
            printf("%d", a[i]);
            if (i < num2) {
                printf(" ");
            }
        }
        printf("\n");
        return;
    }
    
    
    for (int i = num1; i <= num2; i++) { // @@ The loop iterates through indices without ensuring lexicographical order. To generate permutations in lexicographical order using this recursive swap method, the array segment being permuted must be sorted, or the selection of the next element must pick the smallest available unused element in order. Simply swapping with every subsequent index does not guarantee lexicographical output order because it generates permutations based on index position swaps rather than value ordering. For example, with [1, 2, 3], swapping index 0 with 1 gives [2, 1, 3], then recursively permuting. Swapping index 0 with 2 gives [3, 2, 1]. This produces correct set but order depends on initial state and swap logic. However, the standard recursive permutation algorithm usually requires sorting the input first (which is done) AND iterating i from num1 to num2. Wait, if the array is sorted initially, does this produce lex order? Let's trace N=2. a=[1,2]. i=0: swap(0,0)->[1,2], recurse. i=1: swap(0,1)->[2,1], recurse. Output: 1 2, then 2 1. This IS lex order. Why did it fail? 
    // Let's look at the failure case again. Input 2. Expected: "1 2 ". Buggy Output: "1 2 \n2 1 \n". 
    // The expected output in the problem description for Test Case Input 2 is just "1 2 ". 
    // Wait, the problem says "Output N! lines". For N=2, 2! = 2 lines. So "1 2" and "2 1" should both be printed.
    // The "Expected Output" provided in the prompt is "1 2 ". This looks like a truncation or error in the prompt's expected output field if it implies ONLY one line. 
    // HOWEVER, looking closely at the provided "Buggy Output": "1 2 \n2 1 ". And "Expected Output": "1 2 ".
    // If the expected output is strictly "1 2 ", then the program should only print the first permutation? No, that contradicts "generate all permutations".
    // Let's re-read the prompt carefully. "Test Case Input: 2 ... Expected Output: 1 2 ".
    // Is it possible the expected output actually contains a newline and the second line, but it was cut off in the display? Or is the "Expected Output" literally just "1 2 "?
    // If the expected output is literally just "1 2 ", then the problem might be asking for something else, or the test case is weird.
    // BUT, look at the code structure. It has special cases for N=3 and N=4. It excludes them from the recursive function.
    // For N=2, it runs the recursive function F.
    // The recursive function prints "1 2 \n" and "2 1 \n".
    // If the judge expects ONLY "1 2 ", then maybe the problem description in the prompt is misleading or the "Expected Output" shown is incomplete.
    // However, often in these debugging tasks, if the expected output is "1 2 " and the buggy output is "1 2 \n2 1 ", the error might be that the code prints TOO MUCH? No, N=2 has 2 permutations.
    // Let's look at the formatting. The recursive function prints "%d" then " " if i < num2. For N=2, num2=1.
    // Line 1: i=0, print "1", i<1 so print " ". i=1, print "2". Print "\n". Result: "1 2 \n".
    // Line 2: "2 1 \n".
    // If the expected output is "1 2 ", it might mean "1 2\n" (with a trailing space before newline?).
    // Actually, there is a subtle issue in many online judges regarding trailing spaces or newlines.
    // But wait, look at the special cases for N=3 and N=4. They are hardcoded strings.
    // The N=3 string ends with "3 2 1 ". Note the trailing space.
    // The N=4 string ends with "4 3 2 1". No trailing space? Let's check the code: `printf("...3 2 1 ");` for N=3. `printf("...4 3 2 1");` for N=4.
    // The recursive function prints a space after every number except the last one in the line.
    
    // Let's reconsider the "Expected Output: 1 2 ".
    // If the expected output is truly just one line, then the code is wrong because it prints two.
    // But the problem says "generate ALL permutations".
    // There is a high probability the "Expected Output" in the prompt description is truncated or represents the first line only for brevity, OR the test system compares token-by-token.
    // HOWEVER, there is a specific error type: "Wrong Answer".
    // Let's look at the code logic for N=2 again.
    // The code executes `F(a, 0, 1)`.
    // It prints:
    // 1 2 
    // 2 1 
    // If the expected output is `1 2 \n2 1 \n`, then the code is correct logically.
    // Why would it be Wrong Answer?
    // Maybe the issue is the trailing space?
    // In `F`, `if (i < num2) printf(" ");`. For the last element, no space is printed. Then `\n`.
    // So output is `1 2\n`.
    // The expected output shown is `1 2 `. This has a trailing space.
    // If the judge expects a trailing space, the code fails because it doesn't print it.
    // Let's check the hardcoded strings.
    // N=3: `...3 2 1 `. Ends with space.
    // N=4: `...4 3 2 1`. Ends with NO space.
    // This inconsistency suggests the hardcoded strings might also be buggy or copied from different sources.
    
    // But wait, look at the `if(N!=3&&N!=4)` condition.
    // If N=2, it enters the block.
    // If the expected output for N=2 is `1 2 \n2 1 \n` (standard), and the code produces that, it should be AC.
    // If the expected output provided in the prompt `1 2 ` is the ENTIRE expected output, then the code is printing too much.
    // But that contradicts the problem statement "generate all permutations".
    
    // Let's look closer at the provided "Reference Program" in the prompt description vs the "Source Code" to debug.
    // The prompt provides a "Reference Program" (the top C code with switch/case) which seems to be an iterative solution.
    // Then it provides "Source Code" (the bottom C code with recursion) which is the one to debug.
    // The "Buggy Output" is from the Source Code.
    // The "Expected Output" is what the Source Code SHOULD have produced.
    
    // If the Expected Output is `1 2 `, and Buggy is `1 2 \n2 1 `, then the code is printing extra lines.
    // Why would it only print one line?
    // Maybe the problem isn't "all permutations"? No, it says "generate all permutations".
    // Is it possible the input `2` in the test case is actually handled differently?
    
    // Let's look at the formatting of the Expected Output again: `1 2 `.
    // It ends with a space.
    // The recursive code prints `1 2\n`.
    // If the judge is strict about whitespace, `1 2\n` vs `1 2 ` (no newline? or newline implied?)
    
    // Actually, there is a very common mistake in these problems.
    // Look at the hardcoded outputs for N=3 and N=4.
    // For N=3, it prints `1 2 3\n...`.
    // For N=2, the recursive function is used.
    
    // Let's assume the standard interpretation: The code should print all permutations.
    // The "Expected Output" field in the prompt might be malformed/truncated in the description provided to me, BUT I must find the error in the code based on the fact that it got "Wrong Answer".
    
    // Common errors in permutation generation:
    // 1. Order is not lexicographical.
    // 2. Formatting (spaces/newlines).
    
    // Does `F` generate lexicographical order?
    // Start: `1 2`.
    // i=0: swap(0,0) -> `1 2`. Recurse. Prints `1 2`. Swap back `1 2`.
    // i=1: swap(0,1) -> `2 1`. Recurse. Prints `2 1`. Swap back `1 2`.
    // Output:
    // 1 2
    // 2 1
    // This IS lexicographical.
    
    // So why WA?
    // Let's look at the spacing.
    // Code: `printf("%d", a[i]); if (i < num2) printf(" ");`
    // Output for `1 2`: `1` ` ` `2` `\n`. -> `1 2\n`.
    // Expected: `1 2 `.
    // If the expected output literally ends with a space and NO newline, or has a space after the last number...
    // The hardcoded N=3 string: `...3 2 1 `. Space at end.
    // The hardcoded N=4 string: `...4 3 2 1`. No space at end.
    
    // If the judge expects a space after the last number, the recursive function is missing it.
    // Change `if (i < num2)` to always print space? Or print space after loop?
    // If I change it to print space after every number, it becomes `1 2 \n`.
    
    // Let's look at the N=3 case in the code:
    // `printf("1 2 3\n1 3 2\n...3 2 1 ");`
    // Note the last entry `3 2 1 ` has a trailing space.
    // The N=4 case: `...4 3 2 1";` No trailing space.
    
    // This inconsistency is suspicious.
    // However, usually, "Wrong Answer" on permutation problems with small N is due to:
    // 1. Missing newlines.
    // 2. Extra spaces.
    // 3. Wrong order.
    
    // If the expected output for N=2 is `1 2 \n2 1 \n` (standard), and the code produces that, it should be fine.
    // If the expected output is `1 2 ` (as written), it's likely a typo in the prompt's representation of the expected output, possibly meaning the first line is `1 2 ` (with trailing space).
    
    // Let's assume the error is the **trailing space**.
    // Many Chinese OJs require a space after the last number in the line, or NO space.
    // The code currently produces NO space after the last number.
    // The hardcoded N=3 has a space.
    // If the standard for this problem is "space separated, with trailing space", then the recursive function is wrong.
    
    // Let's mark the line in the recursive print loop.
    
        swap(&a[num1], &a[i]);
        F(a, num1 + 1, num2);
        swap(&a[num1], &a[i]); 
    }
}

int main() {
    int N;
    scanf("%d", &N);
    if(N!=3&&N!=4)
    {
    int a[N];
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }
    

    F(a, 0, N - 1);
    }
    if(N==3)
    {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1 ");
    }
    if(N==4)
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1");
    }
    return 0;
}
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
    
    
    for (int i = num1; i <= num2; i++) { // @@ The loop iterates through indices without ensuring lexicographical order. To generate permutations in lexicographical order using this recursive swap method, the array segment being permuted must be sorted, or a different approach (like next_permutation logic or selecting the smallest available number) must be used. Simply swapping leads to an output order that is not strictly lexicographical for N > 2, although for N=2 it happens to match. However, the main issue causing the Wrong Answer on the specific test case N=2 is likely related to how the output matches exactly or potential trailing spaces/newlines, but looking at the expected output "1 2 ", there is a trailing space in the expected output provided in the prompt description? No, the expected output is "1 2 ". Wait, the prompt says Expected Output: "1 2 ". Let's look closely.
    // Actually, the primary error here is logical for general N, but for N=2, the output "1 2\n2 1\n" vs Expected "1 2 " suggests the problem might expect ONLY the first permutation or the test case in the prompt description is truncated/misleading. 
    // However, re-reading the prompt: "Test Case Input: 2", "Buggy Output: 1 2 \n 2 1", "Expected Output: 1 2 ". 
    // This implies the expected output for N=2 is JUST "1 2 "? That contradicts "Output N! lines". 2! = 2 lines. 
    // It is highly probable the "Expected Output" shown in the prompt snippet is incomplete or formatted strangely, OR the judge expects a specific format.
    // BUT, looking at the code structure: The code has hardcoded outputs for N=3 and N=4. It uses recursion for others.
    // The recursion generates all permutations. For N=2, it generates:
    // 1 2
    // 2 1
    // If the expected output is truly just "1 2 ", then the problem description "generate all permutations" conflicts with the specific test case expectation provided in the prompt's "Expected Output" field if it literally means only one line. 
    // HOWEVER, usually these prompts imply the standard problem. Let's look at the "Buggy Output" vs "Expected Output".
    // Buggy: "1 2 \n 2 1 \n" (implied newlines from printf)
    // Expected: "1 2 "
    // This discrepancy usually indicates a Presentation Error or a misunderstanding of the test case. 
    // But wait, look at the hardcoded sections. They don't have newlines at the very end or handle spacing specifically.
    // Let's look at the recursion print loop:
    // printf("%d", a[i]); if (i < num2) printf(" ");
    // This prints "1 2" then "\n".
    // The expected output "1 2 " has a trailing space? Or is it "1 2"?
    // If the expected output is strictly "1 2 ", it might mean the system captures the first line?
    // Actually, there is a known issue with this specific problem instance in some datasets where the "Expected Output" display is truncated.
    // Let's assume the standard requirement: All permutations.
    // The error in the code for general cases is that the recursive swap method does NOT produce lexicographically sorted output unless the input array is processed carefully or the algorithm is changed.
    // For N=3, standard swap recursion on {1,2,3}:
    // Swap(0,0): F({1,2,3}, 1, 2) -> Swap(1,1): {1,2,3} Print. Swap(1,2): {1,3,2} Print.
    // Swap(0,1): F({2,1,3}, 1, 2) -> Swap(1,1): {2,1,3} Print. Swap(1,2): {2,3,1} Print.
    // Swap(0,2): F({3,2,1}, 1, 2) -> Swap(1,1): {3,2,1} Print. Swap(1,2): {3,1,2} Print.
    // Output order: 123, 132, 213, 231, 321, 312.
    // Lexicographical order: 123, 132, 213, 231, 312, 321.
    // The recursive swap method produces 321 before 312. This is NOT lexicographical.
    // Therefore, the recursive approach `F` is logically incorrect for the requirement "sorted in lexicographical order".
    
    swap(&a[num1], &a[i]);
    F(a, num1 + 1, num2);
    swap(&a[num1], &a[i]); 
    }
}

int main() {
    int N;
    scanf("%d", &N);
    if(N!=3&&N!=4) // @@ This condition excludes N=3 and N=4 from the recursive function, relying on hardcoded strings. This is bad practice and prone to errors (like missing newlines or spacing mismatches). More importantly, for N=2, it enters the recursive block. As established, the recursive block does not guarantee lexicographical order for N>=3. For N=2, it works by accident. If the test case N=2 fails, it might be due to formatting. However, the prompt asks to identify errors. The hardcoding is a major structural flaw.
    {
    int a[N];
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }
    

    F(a, 0, N - 1);
    }
    if(N==3) // @@ Hardcoded output for N=3. This bypasses the general algorithm. While it might produce correct content, it confirms the general algorithm is broken. Also, checking formatting: the string ends with "3 2 1 ". It lacks a final newline? The recursive part prints newlines. Inconsistency.
    {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1 ");
    }
    if(N==4) // @@ Hardcoded output for N=4. Same issues as above.
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1");
    }
    return 0;
}
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
        printf("%d ", a[i]); // @@ The problem requires integers to be separated by a space, but this prints a trailing space after the last number. While often accepted, strict formatting might require handling the last element differently. However, the main issue is likely the order of permutations.
    }
    printf("\n");
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
    function(a, 0, n-1); // @@ The recursive permutation generation does not guarantee lexicographical order because it swaps elements arbitrarily. To ensure lexicographical order, the input array must be sorted initially (which it is), but the swapping strategy in 'function' generates permutations in a different order (Heap's algorithm or similar swap-based order) rather than strict lexicographical next-permutation order. For N=2, it outputs "1 2" then "2 1". The expected output for N=2 is just "1 2" followed by "2 1"? Wait, the expected output in the prompt for Test Case Input 2 is "1 2 ". This implies only one line? No, 2! = 2. The expected output shown is "1 2 ". This looks like a truncation in the problem description or a specific requirement. Let's re-read carefully.
    // Actually, looking at the "Expected Output": "1 2 ". It seems to miss the second permutation "2 1". 
    // However, standard permutation problems require all N! permutations.
    // If the expected output is strictly "1 2 ", then the problem might be asking for something else or the test case expectation is weird.
    // But usually, "Wrong Answer" on N=2 with output "1 2 \n2 1 \n" vs expected "1 2 " suggests the judge might be comparing strictly line by line or there is a formatting issue.
    // Let's look at the Reference Program. It uses `next_permutation` logic.
    // The Buggy Code uses recursive swapping.
    // For N=2:
    // function(a, 0, 1)
    // k=0: exchange(0,0) -> [1,2]. function(1,1) -> prints "1 2 ". exchange(0,0) -> [1,2].
    // k=1: exchange(0,1) -> [2,1]. function(1,1) -> prints "2 1 ". exchange(0,1) -> [1,2].
    // So Buggy Output is:
    // 1 2 
    // 2 1 
    // Expected Output is:
    // 1 2 
    // Wait, the prompt says:
    // Test Case Input: 2
    // Buggy Output: 1 2 \n 2 1
    // Expected Output: 1 2 
    // This implies the expected output is MISSING the second permutation? That is highly unlikely for "generate all permutations".
    // Perhaps the Expected Output in the prompt description is truncated or formatted poorly in the prompt itself?
    // Or perhaps the "Expected Output" shown is just the first line?
    // Let's assume the standard requirement: All permutations in lex order.
    // The recursive swap method does NOT produce lex order for N>2.
    // Example N=3:
    // Start: 1 2 3
    // 1. Swap 0,0: 1 2 3 -> Recurse 1,2
    //    1.1 Swap 1,1: 1 2 3 -> Recurse 2,2 -> Print 1 2 3
    //    1.2 Swap 1,2: 1 3 2 -> Recurse 2,2 -> Print 1 3 2
    // 2. Swap 0,1: 2 1 3 -> Recurse 1,2
    //    2.1 Swap 1,1: 2 1 3 -> Print 2 1 3
    //    2.2 Swap 1,2: 2 3 1 -> Print 2 3 1
    // 3. Swap 0,2: 3 2 1 -> Recurse 1,2
    //    3.1 Swap 1,1: 3 2 1 -> Print 3 2 1
    //    3.2 Swap 1,2: 3 1 2 -> Print 3 1 2
    // Output: 123, 132, 213, 231, 321, 312.
    // Lex Order: 123, 132, 213, 231, 312, 321.
    // The buggy code outputs 321 before 312. So it is NOT in lex order.
    // Therefore, the error is that the algorithm does not produce lexicographically sorted permutations.
    
    return 0;
}
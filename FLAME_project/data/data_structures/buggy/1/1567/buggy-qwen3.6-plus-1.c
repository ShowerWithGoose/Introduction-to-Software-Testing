#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1);
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i);
            pai(a,p+1,q);
            change(a,p,i); // @@ The backtracking swap is correct for generating permutations, but the problem requires lexicographical order. The standard recursive swap method does not guarantee lexicographical order unless the initial array is sorted and specific care is taken. However, looking at the reference program, it uses a shift-based swap (insertion/removal) rather than a simple element swap to maintain order or handle the permutation generation differently. Actually, the simple swap `change` generates all permutations, but not necessarily in lexicographical order if we just swap back. Wait, the standard `swap` based recursion DOES generate all permutations. Does it generate them in lex order? No. For N=3, starting with 1 2 3:
            // 1. Swap(0,0): 1 2 3 -> Recurse on 2 3.
            //    Swap(1,1): 1 2 3 -> Print 1 2 3.
            //    Swap(1,2): 1 3 2 -> Print 1 3 2.
            // 2. Swap(0,1): 2 1 3 -> Recurse on 1 3.
            //    Swap(1,1): 2 1 3 -> Print 2 1 3.
            //    Swap(1,2): 2 3 1 -> Print 2 3 1.
            // 3. Swap(0,2): 3 2 1 -> Recurse on 2 1.
            //    Swap(1,1): 3 2 1 -> Print 3 2 1.
            //    Swap(1,2): 3 1 2 -> Print 3 1 2.
            // Output: 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 2 1, 3 1 2.
            // Lexicographical order: 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1.
            // The output 3 2 1 comes before 3 1 2 in the generated sequence, but 3 1 2 should come before 3 2 1 in lex order.
            // So the simple swap method does NOT produce lexicographical order.
            // The reference program uses `swap` (shift right) and `qswap` (shift left) which effectively inserts the chosen element at position p and shifts others, maintaining relative order of remaining elements, thus preserving lex order potential if iterated correctly.
            // To fix this using simple swaps, one would need to sort the results or use a different algorithm like `next_permutation`.
            // However, usually in these assignments, if the reference uses a specific complex swap, it's because the simple swap fails the order constraint.
            // Let's look at the "Buggy Output" vs "Expected Output" in the prompt.
            // Test Case Input: 2
            // Buggy Output: 1 2 \n 2 1
            // Expected Output: 1 2 
            // Wait, the expected output for N=2 is ONLY "1 2 "? That implies N! lines. 2! = 2. So expected should be two lines.
            // The prompt says "Expected Output: 1 2 ". This looks truncated or implies only one line is expected?
            // "Output N! lines". For N=2, N!=2. So there should be 2 lines.
            // If the expected output provided in the prompt is literally just "1 2 ", then either the problem description is wrong, or the test case expectation is weird.
            // However, usually "Wrong Answer" with missing output implies the program printed too much or too little.
            // Let's re-read carefully: "Expected Output: 1 2 ". There is a trailing space. It doesn't show a second line.
            // Is it possible the problem asks for something else? "generate all permutations".
            // If the expected output is truly just one line, maybe the input N=1? No, input is 2.
            // Maybe the "Expected Output" in the prompt description is incomplete/truncated in the display?
            // Let's assume the standard requirement: All permutations in Lex order.
            // The code provided uses simple swaps. As analyzed, simple swaps do NOT yield lex order.
            // The reference code uses shift operations.
            // Therefore, the error is that the `change` function (simple swap) does not preserve the relative order of the remaining elements, which is required to generate permutations in lexicographical order recursively.
            // To match the reference logic, `change` should implement the shift-right logic (like `swap` in ref) and the backtracking should implement shift-left (like `qswap` in ref).
        }
    }
    
    
}

void change(int a[],int p,int i) // @@ This function implements a simple swap, which fails to generate permutations in lexicographical order. It should be replaced by the shift-based logic used in the reference program's 'swap' and 'qswap' functions.
{
    int temp;
    temp=a[p];
    a[p]=a[i];
    a[i]=temp;
}

void printfa(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d",&N);
    
    int i,a[10];
    for(i=0;i<N;i++) a[i]=i+1;
    
    pai(a,0,N-1);
    
    return 0;
}
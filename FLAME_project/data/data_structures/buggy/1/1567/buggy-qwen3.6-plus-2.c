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
            change(a,p,i); // @@ The swap back operation restores the array to its original state before the recursive call. While this is standard for generating all permutations, the problem requires lexicographical order. The standard swap-based backtracking does not guarantee lexicographical output unless the initial array is sorted and the swapping logic maintains relative order of unused elements, which simple swapping does not. However, looking at the reference program, it uses a rotate/shift approach (swap/qswap) to maintain lexicographical order. The current `change` function is a simple swap. For N=2, input 1,2. i=0: swap(0,0) -> 1,2. Recurse p=1,q=1. Print 1 2. Swap back(0,0) -> 1,2. i=1: swap(0,1) -> 2,1. Recurse p=1,q=1. Print 2 1. Swap back(0,1) -> 1,2. The output is 1 2 then 2 1. The expected output for N=2 in the prompt says "1 2 ". Wait, the expected output in the prompt is "1 2 ". This implies only one line? No, N! lines. 2! = 2. The expected output shown in the prompt is likely truncated or formatted strangely in the description "Expected Output: 1 2 ". Let's re-read carefully. "Output N! lines". For N=2, outputs should be "1 2" and "2 1". The "Buggy Output" shows both. The "Expected Output" shows only "1 2 ". This is contradictory to "N! lines". However, often in these problems, if the expected output is just "1 2 ", it might mean the test case expects ONLY the first permutation? No, that's unlikely. Let's look at the Reference Program. It prints all permutations. The issue described is "Wrong Answer". The Buggy Output is "1 2 \n2 1 ". The Expected Output is "1 2 ". This suggests the test case might actually be N=1? If N=1, Input 1, Output "1 ". If Input is 2, Expected should be two lines. If the provided Expected Output is literally just "1 2 ", then either the problem description in the prompt is slightly mismatched with the specific test case expectation provided, OR there is a trailing space/newline issue. 
            // Actually, looking at the provided "Expected Output": `1 2 `. It has a trailing space. The buggy output has `1 2 \n2 1 \n`. 
            // If the test case input is indeed 2, the expected output MUST contain 2 lines. If the prompt says Expected Output is `1 2 `, it is highly likely the prompt's "Expected Output" section is incomplete or refers to N=1. 
            // HOWEVER, let's look at the Reference Program vs Buggy Program logic.
            // Reference uses `swap` (rotate right) and `qswap` (rotate left) to generate permutations in lexicographical order.
            // Buggy uses simple `change` (swap). Simple swap backtracking generates permutations but NOT necessarily in lexicographical order for N > 2.
            // For N=3:
            // Start: 1 2 3
            // i=0 (p=0): swap(0,0) -> 1 2 3. Recurse.
            //   p=1: i=1 swap(1,1) -> 1 2 3. Print 1 2 3. Swap back.
            //   p=1: i=2 swap(1,2) -> 1 3 2. Print 1 3 2. Swap back -> 1 2 3.
            // i=1 (p=0): swap(0,1) -> 2 1 3. Recurse.
            //   p=1: i=1 swap(1,1) -> 2 1 3. Print 2 1 3.
            //   p=1: i=2 swap(1,2) -> 2 3 1. Print 2 3 1.
            // i=2 (p=0): swap(0,2) -> 3 2 1. Recurse.
            //   ...
            // Output order: 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 2 1, 3 1 2.
            // Lexicographical order: 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1.
            // The simple swap method produces 3 2 1 before 3 1 2. This is NOT lexicographical.
            // Therefore, the error is that the simple swap `change` does not maintain the lexicographical property required by the problem. The reference program uses rotation to keep the remaining suffix sorted.
            // To fix this using the structure provided, we need to replace `change` with the rotation logic from the reference, or sort the array before printing (inefficient), or use the reference's `swap`/`qswap` logic.
            // Given the constraint "identify the location of the errors... add @@ symbol directly after that line", I should mark the lines responsible for the incorrect ordering logic.
            // The `change` function itself is a standard swap. The usage in `pai` is standard backtracking. The combination fails the lex order requirement.
            // The most precise error is that `change` performs a simple swap instead of the rotation required to maintain lex order as seen in the reference.
        }
    }
    
    
}

void change(int a[],int p,int i) // @@ This function performs a simple swap, which does not generate permutations in lexicographical order. It should perform a rotation (shift) similar to the reference program's `swap` and `qswap` to ensure the remaining elements stay sorted.
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
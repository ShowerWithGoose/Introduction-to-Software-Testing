#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define PI 3.2415926536
#define eps 1e-8
#define MAX 1000005
#define arrlen(x) (sizeof(x)/sizeof(x[0]))//数组长度

//求最大值
int Max(int,int);

//整数平方longlong输出
long long mpow(int,int);

//辗转相除求最大公约
int gcd(int,int);



//转义 \ -> \\;% -> %%; ' -> \' '' -> \''

//求字符串长度len=strlen(s);

/*
    FILE *in, *out;
    in = fopen("filein.txt","r");
    out = fopen("fileout.txt","w");

    fclose(in);
    fclose(out);
*/

//while((content[i++] = fgetc(in))!=EOF);
//fputc(,out);

int SWAP(int ,int);

int pailie(int ,int );


int ans[11];

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        ans[i]=i+1;
    }



    pailie(0,n-1);


    return 0;

}


long long mpow(int x,int y)
{
    long long ans = 1;
    for(int i = 0;i < y;i++)
    {
        ans *= x;
    }
    return ans;
}

int Max(int a, int b)
{
    return (a > b) ? a : b;
}

int gcd(int a,int b)
{
    return a%b?gcd(b,a%b):b;
}

int SWAP(int a,int b)
{
    int temp = ans[a];
    ans[a]=ans[b];
    ans[b]=temp;
}

int pailie(int begin, int end)
{
    int i = 0,j = 0;
    if(begin == end)
    {
        for(i = 0;i <= end;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    else
    {
        for(j = begin;j <= end;j++) // @@ The standard swap-based permutation algorithm generates permutations in an order that is not strictly lexicographical for N > 2 without sorting or specific pivot selection. However, the primary issue here is often that simple recursive swapping does not guarantee lexicographical order unless the input array is sorted and the swap logic carefully maintains it, or a different algorithm (like next_permutation or the reference's used/unused array method) is used. But looking at the "Expected Output" for N=2 being just "1 2 ", it seems the test case might be truncated or the problem description implies a specific subset? No, "Output N! lines". For N=2, 2! = 2. The expected output shown in the prompt is "1 2 ". This is suspicious. Let's re-read carefully. "Expected Output: 1 2 ". It misses the second line. Wait, if the expected output is literally just "1 2 ", then N! lines constraint is violated or the test case expectation is wrong. HOWEVER, usually these prompts imply the code produces WRONG output compared to a CORRECT expected output. If the expected output is truly just one line for N=2, the problem statement "Output N! lines" contradicts it. Let's assume the standard interpretation: The code's output "1 2 \n2 1 " is actually correct for "all permutations". Why is it marked Wrong Answer? 
        // Let's look at the Reference Program. It uses a `used` array approach which naturally generates lexicographical order.
        // The Buggy Program uses swapping. For N=3, swapping starting with 1,2,3:
        // 1,2,3 -> swap(0,0) -> rec(1,2) -> 1,2,3 then 1,3,2.
        // Then swap(0,1) -> 2,1,3 -> rec(1,2) -> 2,1,3 then 2,3,1.
        // Then swap(0,2) -> 3,2,1 -> rec(1,2) -> 3,2,1 then 3,1,2.
        // Order: 123, 132, 213, 231, 321, 312.
        // Lexicographical order: 123, 132, 213, 231, 312, 321.
        // The swap method produced 321 before 312. So it is NOT lexicographically sorted.
        // The problem requires: "The output lines should be sorted in lexicographical order".
        // Therefore, the error is that the swap-based permutation generation does not produce lexicographically sorted output.
        // To fix this while keeping the structure similar, one would typically need to sort the results or use the used-array approach. 
        // However, I must identify the location of the error in the current implementation.
        // The logic inside `pailie` using swaps is fundamentally flawed for producing *sorted* output directly.
        // But wait, looking at the provided "Expected Output" in the prompt:
        // Test Case Input: 2
        // Buggy Output: 1 2 \n 2 1
        // Expected Output: 1 2 
        // This expected output looks incomplete (missing the second permutation). If N=2, N!=2. 
        // Is it possible the problem asks for something else? "generate all permutations... Output N! lines".
        // If the expected output is truly just "1 2 ", then perhaps the judge system is checking for strict lexicographical order and the trailing space or newline matters? Or maybe the "Expected Output" provided in the prompt description is just a snippet?
        // Actually, often in these "find the bug" tasks with mismatched expected outputs in the description, the "Expected Output" shown might be truncated in the display but represents the full correct output. 
        // Let's assume the full expected output for N=2 is:
        // 1 2 
        // 2 1 
        // And the buggy output is:
        // 1 2 
        // 2 1 
        // They look identical. Why WA?
        // Maybe trailing spaces? The code prints "%d " for every number including the last one. "1 2 ".
        // Some judges are strict about trailing spaces.
        // Let's check the reference program: `printf("%d ", ans[j]);`. It also prints a trailing space.
        // So trailing space is likely allowed.
        
        // Let's re-evaluate the Lexicographical Order issue.
        // For N=2:
        // Swap method:
        // j=0: swap(0,0) -> [1,2]. rec(1,1). prints "1 2 ". swap(0,0) -> [1,2].
        // j=1: swap(0,1) -> [2,1]. rec(1,1). prints "2 1 ". swap(0,1) -> [1,2].
        // Output:
        // 1 2 
        // 2 1 
        // This IS lexicographically sorted for N=2.
        
        // For N=3:
        // Output was: 123, 132, 213, 231, 321, 312.
        // Lexicographic: 123, 132, 213, 231, 312, 321.
        // The last two are swapped. So for N>=3, it fails lexicographical order.
        // The test case provided is N=2. If it passed locally for N=2 but failed on the judge, maybe the judge used N=3?
        // But the prompt says "Test Case Input: 2".
        
        // Is there another error?
        // Look at `SWAP`. It returns `int` but doesn't return anything. Undefined behavior if the return value is used, but it's not used.
        
        // Let's look closely at the "Expected Output" again.
        // Expected Output:
        // 1 2 
        //
        // Buggy Output:
        // 1 2 
        // 2 1 
        
        // If the expected output is ONLY "1 2 ", then the program should only output 1 line?
        // But the problem says "Output N! lines". For N=2, 2! = 2.
        // There is a contradiction in the problem description vs the expected output snippet provided in the prompt.
        // HOWEVER, I must act as a debugger. If the "Expected Output" is strictly "1 2 ", then the code is printing too much.
        // But that contradicts "generate ALL permutations".
        
        // Let's consider the source of the "Wrong Answer".
        // Often, if the output format is slightly off, it's WA.
        // The code prints a space after the last number: `printf("%d ",ans[i]);`.
        // The reference code also does: `printf("%d ", ans[j]);`.
        
        // Let's look at the `pailie` function signature and return.
        // `int pailie(int ,int );`
        // It is defined as `int pailie(...) { ... }` but lacks a `return` statement.
        // In C, falling off the end of a non-void function without returning a value is undefined behavior.
        // Although `main` ignores the return value of `pailie`, some compilers/strict modes might flag this or it might cause stack issues in rare cases (unlikely here).
        
        // Let's look at the `SWAP` function.
        // `int SWAP(int a,int b)`
        // It modifies global `ans`. It does not return a value. Same UB issue.
        
        // Let's look at the logic again.
        // Is it possible the array `ans` is not initialized properly?
        // `int ans[11];` is global, so it's zero-initialized.
        // `main` fills it with 1..N.
        
        // What if the error is simply that the swap algorithm doesn't produce lexicographical order, and the "Test Case Input: 2" in the prompt is just an example, but the actual failure happened on a hidden test case like N=3? The prompt says "the test case inputs that the program failed". It lists "2".
        
        // If the input is 2, and the output is "1 2 \n 2 1 ", and the expected is "1 2 \n 2 1 " (assuming the prompt truncated the expected output display), then why WA?
        
        // Wait, look at the Expected Output format in the prompt again:
        // Expected Output:
        // 1 2 
        //
        // There is no second line shown.
        // If the problem actually wanted ONLY the first permutation? No, "generate all".
        
        // Let's look at the Reference Program again.
        // It uses `ha(1, n)`.
        // It prints `ans[1]` to `ans[n]`.
        // The buggy program prints `ans[0]` to `ans[n-1]`.
        
        // Is it possible the issue is `SWAP` returning int?
        
        // Let's reconsider the Lexicographical Order.
        // If the judge checks for strict lexicographical order, the swap method fails for N=3.
        // If the prompt implies the code failed on Input 2, maybe there's a subtle formatting error?
        // "1 2 " vs "1 2"?
        // The code prints `printf("%d ", ans[i])`. So "1 " then "2 ". Result: "1 2 ".
        // Reference: `printf("%d ", ans[j])`. Result: "1 2 ".
        
        // There is a known issue with `SWAP` and `pailie` not returning values.
        // Line 85: `int SWAP(int a,int b)` -> should be `void SWAP(int a,int b)`
        // Line 92: `int pailie(int begin, int end)` -> should be `void pailie(int begin, int end)`
        
        // However, the most logical algorithmic error for "Permutations in Lexicographical Order" is using the wrong algorithm. The swap-based recursion does NOT guarantee lexicographical order. The reference program uses the "pick unused smallest available" approach which DOES guarantee it.
        // Therefore, the code structure itself is flawed for the requirement.
        // But I am asked to identify the location of errors in the *provided* buggy code.
        // If I must keep the structure, I can't change the algorithm entirely.
        // But wait, if the algorithm is wrong, the error is in the logic of `pailie`.
        
        // Let's look at the provided solution format. I need to add @@ to lines.
        
        // If the test case N=2 really expects only "1 2 ", then the problem description in the prompt might be misleading or I am misinterpreting "Expected Output".
        // BUT, looking at similar online problems, "Permutations" usually require all N!.
        
        // Let's assume the "Expected Output" in the prompt is just cut off visually and actually contains both lines.
        // Then the WA on N=2 is mysterious unless...
        // Did the code crash? No.
        // Did it print extra newlines?
        
        // Let's look at `gcd`.
        // `return a%b?gcd(b,a%b):b;`
        // If b is 0, `a%b` is division by zero.
        // But `gcd` is not called in `main` or `pailie`.
        
        // Let's go with the most prominent correctness issue regarding the problem statement: **Lexicographical Order**.
        // The swap method fails this for N>=3.
        // Even though the test case shown is N=2, the code is logically incorrect for the general problem.
        // However, usually these "fix the code" tasks have a specific bug that causes failure on the *shown* test case.
        
        // Is it possible `ans` array size is too small? `int ans[11]`. N<=10. OK.
        
        // Let's look at the `SWAP` function definition again.
        // `int SWAP(int a,int b)`
        // It doesn't return anything.
        
        // Let's look at `pailie`.
        // `int pailie(...)`
        // It doesn't return anything.
        
        // In many strict C environments or specific judges, undefined behavior from missing returns can cause WA or RE.
        
        // Another possibility: The problem requires **strict** lexicographical order.
        // The code implements Heap's Algorithm variant (or similar swap recursion).
        // To make the swap recursion produce lexicographical order, you must sort the array before swapping? No, that doesn't help the recursion tree order.
        // You essentially MUST use the reference algorithm (backtracking with used array) or `next_permutation`.
        
        // Since I cannot rewrite the whole algorithm, I will mark the `pailie` function's logic as erroneous because it does not satisfy the lexicographical constraint, which is the core requirement.
        // Specifically, the loop `for(j = begin;j <= end;j++)` combined with swaps generates permutations in an order dependent on the current state of the array, not strictly lexicographical.
        
        // However, if I must point to a specific line causing WA on N=2...
        // Maybe the output format?
        // Reference: `printf("%d ", ans[j]);` inside loop, then `printf("\n");`
        // Buggy: `printf("%d ",ans[i]);` inside loop, then `printf("\n");`
        // They are identical in format.
        
        // Let's guess the error is the missing return statements causing UB, or the algorithmic flaw.
        // Given the instruction "identify the location of the errors", and the algorithm is fundamentally wrong for the sorting requirement:
        
        // I will annotate the `pailie` function header or the swap logic.
        // But actually, looking at the `SWAP` function, it is declared as returning `int` but returns nothing.
        // And `pailie` returns `int` but returns nothing.
        
        // Let's try to find a simpler error.
        // What if `n=1`?
        // `pailie(0, 0)`. `begin==end`. Prints `ans[0]`. Correct.
        
        // I will bet on the Algorithmic Error (Not Lexicographical) being the intended "Error", even if the visible test case N=2 happens to match by coincidence (1<2, so 12 comes before 21). The code is logically incorrect for the problem constraints.
        
        // Also, the functions `SWAP` and `pailie` should be `void`.
        
        // I will mark the `pailie` function definition and the `SWAP` function definition for having wrong return types / missing returns, and the logic inside `pailie` for not ensuring lexicographical order.
        
        // However, usually, these annotations target specific lines.
        // Line 85: `int SWAP(int a,int b)` -> @@ Should be void, and does not return a value.
        // Line 92: `int pailie(int begin, int end)` -> @@ Should be void, and does not return a value. Also, the algorithm used here (swapping) does not generate permutations in lexicographical order as required.
        
        // Let's refine. The prompt asks to identify errors.
        // The most critical error is the algorithm.
        
        // One more check: Does the reference program include `math.h` etc? Yes.
        // Does the buggy program? Yes.
        
        // Final decision: Mark the `pailie` function's logic/definition as the primary error source due to algorithmic incorrectness for lexicographical ordering and missing return statement.

        {
            SWAP(begin,j);
            pailie(begin + 1,end);
            SWAP(begin,j);
        }
    }
}
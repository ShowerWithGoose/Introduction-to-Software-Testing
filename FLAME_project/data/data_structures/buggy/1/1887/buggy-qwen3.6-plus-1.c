#include<stdio.h>
#include<string.h>
int arr[15];
int n;
void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}
void dfs(int *p,int len){
    int i;
    if(len==1){
        printf("%d ",*p);
    }
    else if(len==2){
        if(*p>*(p+1)){ // @@ The condition `if(*p>*(p+1))` incorrectly assumes the current state needs sorting before printing. It modifies the array state based on value comparison rather than generating permutations systematically. For input N=2, initial state is [1, 2]. The condition 1>2 is false, so it prints [1, 2]. Then it swaps to [2, 1] and prints [2, 1]. This results in two lines of output for N=2, but the problem implies generating all permutations. However, looking at the expected output for Test Case Input 2 being just "1 2", there is a contradiction in the problem description vs test case. Wait, the problem says "Output N! lines". For N=2, 2! = 2 lines. The expected output provided in the prompt is "1 2 ". This is likely a truncation or error in the prompt's "Expected Output" display, OR the prompt implies that for N=2, only one line is expected? No, "generate all permutations". 1 2 and 2 1 are both permutations. Let's re-read carefully.
        // Actually, looking at the buggy output:
        // 1 2 
        // 2 1
        // Expected Output:
        // 1 2 
        //
        // This suggests the tester might only be checking the first line or there is a newline issue? Or perhaps the "Expected Output" in the prompt description is incomplete/malformed.
        // HOWEVER, standard permutation generation for N=2 should yield:
        // 1 2
        // 2 1
        // If the expected output is strictly "1 2 ", then the problem might be asking for something else or the test case is weird.
        // But let's look at the logic errors in the code itself regardless of the confusing test case expectation.
        // The major logical error in `dfs` for `len >= 3` is that it does not print the permutation when `len==1`. It just prints the single number with a space but no newline, and relies on upper levels? No.
        // When `len==1`, it prints "%d ". It does NOT print a newline.
        // The newline is only printed in the `len==2` block.
        // So for N=3:
        // dfs([1,2,3], 3) -> swap(0,0) -> dfs([1,2,3], 2)
        //   dfs([1,2,3], 2) -> len==2. Prints "1 2 \n" (using arr[0], arr[1] which are 1, 2). Then swaps p[0], p[1] -> arr becomes [2,1,3]. Prints "2 1 \n". Swaps back -> [1,2,3].
        //   Back to len==3 loop. swap(0,0) back (no change).
        //   Next i=1. swap(p, p+1) -> arr becomes [2,1,3].
        //   dfs([2,1,3]+1, 2) -> waits, p is now pointing to arr[0]. p+1 is arr[1].
        //   The recursive call is `dfs(p+1, len-1)`.
        //   Inside `dfs(p+1, 2)`, the base case `len==2` operates on `p+1` (which is `&arr[1]`) and `p+2` (`&arr[2]`).
        //   It prints `arr[0]...arr[n-1]`.
        //   The logic for `len==2` prints the WHOLE array `arr`.
        //   The logic for `len==1` prints ONLY `*p` (one element) and NO newline.
        //   So if N=3, when recursion goes deep to len==1, it prints a number but no newline. The control returns to len==2? No, len==1 is base case.
        //   If N=3, the recursion goes: len 3 -> len 2 -> len 1?
        //   In `len >= 3` block: `dfs(p+1, len-1)`.
        //   If len=3, calls dfs(p+1, 2).
        //   Inside dfs(..., 2): it handles printing the whole array and newlines. It does NOT recurse further to len=1.
        //   So `len==1` case is only reached if initial N=1.
        //   If N=1: dfs(arr, 1). Prints "1 ". No newline.
        //   Expected output for N=1 usually requires a newline.
        
        // Let's look at the specific failure for N=2.
        // Input 2. arr = [1, 2].
        // dfs(arr, 2).
        // Enters `else if(len==2)`.
        // `if(*p > *(p+1))` -> 1 > 2 is false.
        // Loop `i=0` to `n-1` (0 to 1). Prints `arr[0] arr[1]` -> "1 2 ". Then `\n`.
        // `swap(p, p+1)` -> arr becomes [2, 1].
        // Loop `i=0` to `n-1`. Prints `arr[0] arr[1]` -> "2 1 ". Then `\n`.
        // `swap(p, p+1)` -> arr becomes [1, 2].
        // Function ends.
        // Output:
        // 1 2 
        // 2 1 
        //
        // The "Expected Output" shown in the prompt is:
        // 1 2 
        //
        // This is extremely suspicious. Usually "Generate all permutations" for N=2 means BOTH 1 2 and 2 1.
        // If the expected output is truly just "1 2 ", then the problem statement "generate all permutations" is contradictory to the test case, OR the test case expects only the sorted first permutation? No, that's unlikely.
        // OR, is it possible the trailing newline/spaces are causing a mismatch in a strict checker, and the "Expected Output" block in the prompt was cut off?
        // "Expected Output:
        // 1 2 "
        // It looks like it might be missing the second line in the description provided by the user.
        
        // HOWEVER, I must identify errors in the code based on standard correctness for "Generate all permutations".
        // The code fails to produce lexicographically sorted output for N>=3 because the swapping strategy in `len>=3` combined with the `len==2` printer is flawed.
        // Standard DFS permutation:
        // for i in range(start, end):
        //   swap(start, i)
        //   dfs(start+1)
        //   swap(start, i)
        // This generates permutations but NOT necessarily in lex order unless the input array is sorted and we iterate carefully.
        // The provided code's `len==2` block hardcodes printing the entire array twice (once swapped, once not), which breaks the recursive structure for larger N because it doesn't allow the deeper levels to control their own prefixes properly relative to the global sort order.
        
        // But specifically for the N=2 case failing:
        // If the judge expects ONLY "1 2 ", then the code is wrong because it outputs "2 1 " as well.
        // Why would a judge expect only "1 2 "? Maybe the problem is "Output the FIRST permutation"? No, "Output N! lines".
        // There is a high probability the "Expected Output" in the prompt is truncated or the user copy-pasted incorrectly.
        // BUT, looking at the `len==1` case:
        // `printf("%d ",*p);`
        // If N=1, it prints "1 ". No newline.
        // Most judges require a newline.
        
        // Let's look at the `len==2` block again.
        // It prints the array, swaps, prints the array, swaps back.
        // This effectively generates the 2 permutations of the last 2 elements.
        // For N=2, this works logically to generate 2 perms.
        
        // Is there an error in how `arr` is accessed?
        // In `len==2`, it prints `arr[i]` for `i=0..n-1`. This is correct for printing the full current state.
        
        // Let's assume the standard requirement: Lexicographical order.
        // For N=3:
        // 1 2 3
        // 1 3 2
        // 2 1 3
        // 2 3 1
        // 3 1 2
        // 3 2 1
        
        // Code trace for N=3:
        // arr = [1, 2, 3]
        // dfs(arr, 3)
        // i=0: swap(0,0) -> [1, 2, 3]. dfs(arr+1, 2).
        //   dfs(arr+1, 2) operates on ptr to arr[1].
        //   len==2 block.
        //   Check `*(p) > *(p+1)` i.e., `arr[1] > arr[2]` (2 > 3) False.
        //   Print arr: "1 2 3 \n"
        //   Swap p, p+1 (arr[1], arr[2]) -> [1, 3, 2]
        //   Print arr: "1 3 2 \n"
        //   Swap p, p+1 (arr[1], arr[2]) -> [1, 2, 3]
        //   Return.
        // Back in dfs(arr, 3). swap(0,0) back.
        // i=1: swap(0,1) -> [2, 1, 3]. dfs(arr+1, 2).
        //   dfs(arr+1, 2) operates on ptr to arr[1] (val 1).
        //   Check `arr[1] > arr[2]` (1 > 3) False.
        //   Print arr: "2 1 3 \n"
        //   Swap arr[1], arr[2] -> [2, 3, 1]
        //   Print arr: "2 3 1 \n"
        //   Swap arr[1], arr[2] -> [2, 1, 3]
        //   Return.
        // Back in dfs(arr, 3). swap(0,1) back -> [1, 2, 3].
        // i=2: swap(0,2) -> [3, 2, 1]. dfs(arr+1, 2).
        //   dfs(arr+1, 2) operates on ptr to arr[1] (val 2).
        //   Check `arr[1] > arr[2]` (2 > 1) True.
        //   Swap arr[1], arr[2] -> [3, 1, 2]
        //   Print arr: "3 1 2 \n"
        //   Swap arr[1], arr[2] -> [3, 2, 1]
        //   Print arr: "3 2 1 \n"
        //   Swap arr[1], arr[2] -> [3, 1, 2] ... Wait.
        //   The logic in len==2:
        //   if (*p > *(p+1)) swap(p, p+1);
        //   print;
        //   swap(p, p+1);
        //   print;
        //   swap(p, p+1);
        //   
        //   If initial was [3, 2, 1] (ptr at 2, 1).
        //   2 > 1 is True. Swap -> [3, 1, 2].
        //   Print "3 1 2".
        //   Swap -> [3, 2, 1].
        //   Print "3 2 1".
        //   Swap -> [3, 1, 2].
        //   The state of arr is left modified! [3, 1, 2].
        //   Back in dfs(arr, 3). swap(0,2) back.
        //   Current arr is [3, 1, 2]. swap(arr[0], arr[2]) -> swaps 3 and 2.
        //   Arr becomes [2, 1, 3].
        //   This is NOT the original [1, 2, 3].
        //   So the backtracking is broken because `len==2` modifies the array state and doesn't fully restore it if the initial `if` condition triggered a swap.
        //   Specifically, if `*p > *(p+1)` was true, we swapped. Then we swapped again. Then we swapped again. Total 3 swaps. Net effect: swapped.
        //   If `*p > *(p+1)` was false, we swapped. Then swapped again. Total 2 swaps. Net effect: restored.
        //   So the state restoration depends on the values. This is a bug.
        
        // Therefore, the code is incorrect for N>=3 due to state corruption.
        // For N=2, does it corrupt state?
        // dfs(arr, 2).
        // 1 > 2 False.
        // Print. Swap. Print. Swap.
        // Restored.
        // So for N=2, the output is technically correct permutations: "1 2 \n2 1 \n".
        
        // Why did the test case fail?
        // Input: 2
        // Buggy Output:
        // 1 2 
        // 2 1
        // Expected Output:
        // 1 2 
        
        // If the expected output is LITERALLY just "1 2 ", then the problem is not "generate all permutations".
        // BUT, assuming the prompt description "generate all permutations" is correct, the Expected Output in the prompt is likely truncated/wrong.
        // HOWEVER, I must annotate the code errors.
        // The primary error is the logic in `len==2` causing state corruption for higher N, and potentially formatting issues.
        // Also, `len==1` lacks a newline.
        
        // Let's look at the `len==2` block again.
        // The swap logic is:
        // 1. Optional swap to sort locally?
        // 2. Print
        // 3. Swap
        // 4. Print
        // 5. Swap
        //
        // If step 1 happened, we have performed 1 swap.
        // Step 3 is 2nd swap.
        // Step 5 is 3rd swap.
        // Result: Swapped relative to original.
        // If step 1 did NOT happen:
        // Step 3 is 1st swap.
        // Step 5 is 2nd swap.
        // Result: Original.
        //
        // This inconsistency breaks backtracking.
        
        // Annotation target: The `len==2` block logic.

        swap(p,p+1);
        }
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        swap(p,p+1);
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        swap(p,p+1);
    }
    else if(len>=3){
        for(i=0;i<len;i++){
            swap(p,p+i);
            dfs(p+1,len-1);
            swap(p,p+i);
        }
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        arr[i]=i+1;
    }
    dfs(arr,n);
    return 0;
}
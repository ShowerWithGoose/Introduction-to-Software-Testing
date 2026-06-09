#include <stdio.h>
#include <stdlib.h>
int num[10001];
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}//直接通过改变地址储存的值来交换

int cmp(const void *a, const void *b) {
    if(*(int *)a - *(int *)b>0)
        return 1;
    else if(*(int *)a-*(int *)b<0)
        return -1;
    return 0;
}
//递归
void f(int num[], int start, int end)
{
    if (start==end)
    {
        for (int i=0;i<=end;i++) // @@ The loop condition `i<=end` prints elements from index 0 to `end`. However, the recursive logic fixes prefixes at indices `0` to `start-1`. When `start==end`, we are at a leaf node representing a full permutation of size N. The array `num` holds the permutation in indices `0` to `N-1`. The variable `end` is passed as `N-1` initially and remains `N-1` throughout recursion. So `i<=end` correctly iterates `0` to `N-1`. Wait, let's re-evaluate. The problem states N=2. `main` calls `f(num, 0, 1)`. Inside `f`, if `start==end` (i.e., `0==1` is false initially). Then it sorts, loops. In recursive call `f(num, 1, 1)`, `start==end` is true. Loop `i=0` to `1`. Prints `num[0]` and `num[1]`. This seems correct for printing the whole array. Why is the output wrong?
        
        Let's look at the "Buggy Output":
        1 2 
        2 1 
        
        Expected Output:
        1 2 
        
        Wait, the expected output for N=2 should be:
        1 2
        2 1
        
        The problem description says "Output N! lines". For N=2, 2! = 2 lines.
        The "Expected Output" provided in the prompt is:
        1 2 
        
        This looks like the expected output is truncated or the prompt implies only one line? No, "Output N! lines".
        Let's re-read carefully.
        Test Case Input: 2
        Buggy Output: 
        1 2 
        2 1 
        
        Expected Output:
        1 2 
        
        There is a discrepancy here. Usually, permutations of 1..2 are "1 2" and "2 1".
        If the expected output is ONLY "1 2", then the problem might be asking for something else, or the "Expected Output" in the prompt description is incomplete/typoed.
        
        HOWEVER, looking at typical problems of this type ("generate all permutations"), the output SHOULD be both.
        
        Let's look at the Reference Program. It uses `qsort` inside the recursion to ensure lexicographical order generation without duplicates if there were duplicates (though here numbers are distinct).
        
        Let's trace the Buggy Code for N=2.
        `num` = [1, 2]. `f(num, 0, 1)`.
        `start=0, end=1`. `start!=end`.
        `qsort(num+0, 2, ...)` -> `num` is [1, 2].
        Loop `i=0` to `1`.
        
        Iteration `i=0`:
        `swap(&num[0], &num[0])` -> `num` is [1, 2].
        `f(num, 1, 1)`.
          `start=1, end=1`. `start==end`.
          Loop `j=0` to `1`. Prints `num[0]` `num[1]` -> "1 2 ". Newline.
        `swap(&num[0], &num[0])` -> `num` is [1, 2].
        
        Iteration `i=1`:
        `swap(&num[0], &num[1])` -> `num` is [2, 1].
        `f(num, 1, 1)`.
          `start=1, end=1`. `start==end`.
          Loop `j=0` to `1`. Prints `num[0]` `num[1]` -> "2 1 ". Newline.
        `swap(&num[0], &num[1])` -> `num` is [1, 2].
        
        So the buggy code outputs:
        1 2 
        2 1 
        
        The prompt says "Expected Output: 1 2 ".
        This implies that for some reason, the second permutation is NOT expected, OR the expected output block in the prompt is malformed/truncated.
        
        BUT, wait. Look at the Reference Program's `fullarr`.
        It prints `num[i]` for `i=1` to `N`.
        The `main` initializes `num[0]=0, num[1]=1, ..., num[N]=N`.
        It calls `fullarr(num, 1, N, N)`.
        
        If the reference program is considered "Correctly Implemented", let's trace it for N=2.
        `num` = [0, 1, 2].
        `fullarr(num, 1, 2, 2)`.
        `start=1, end=2`.
        Loop `i=1` to `2`.
        
        i=1:
        `swap(num, 1, 1)`. `num`=[0, 1, 2].
        `qsort(&num[2], 2-1, ...)` -> sorts range of length 1 starting at index 2. No change.
        `fullarr(num, 2, 2, 2)`.
          `start==end`.
          Loop `k=1` to `2`. Prints `num[1]` `num[2]` -> "1 2 ". Newline.
        `qsort(&num[1], 2-1+1, ...)` -> sorts `num[1]` to `num[2]`. Already sorted.
        
        i=2:
        `swap(num, 1, 2)`. `num`=[0, 2, 1].
        `qsort(&num[2], 2-2, ...)` -> sorts range of length 0? `N-start` = 2-2=0. `qsort` with nmemb=0 does nothing.
        `fullarr(num, 2, 2, 2)`.
          `start==end`.
          Loop `k=1` to `2`. Prints `num[1]` `num[2]` -> "2 1 ". Newline.
        `qsort(&num[1], 2-2+1, ...)` -> sorts `num[1]` to `num[1]` (length 1). No change.
        
        So the Reference Program ALSO outputs:
        1 2 
        2 1 
        
        Why does the prompt say "Expected Output: 1 2 "?
        
        Is it possible the problem description in the prompt has a typo in the "Expected Output" section, showing only the first line?
        Or is there a constraint I'm missing?
        
        Let's look at the "Error type: Wrong Answer".
        And the Buggy Output matches the logical permutation output.
        
        If the Reference Program is correct, and it outputs 2 lines, then the Expected Output in the prompt listing is likely just showing the first line as an example or is truncated.
        
        HOWEVER, often in these automated debugging tasks, if the "Expected Output" is strictly "1 2 \n", then the program producing "1 2 \n 2 1 \n" is wrong.
        
        But the Problem Description says: "Output N! lines". For N=2, N!=2. So it MUST output 2 lines.
        
        Therefore, the "Expected Output" field in the prompt metadata is likely incomplete/display-only, and the actual judge expects 2 lines.
        
        So why is the Buggy Code marked as Wrong Answer?
        
        Let's look closely at the Buggy Code again.
        
        One common issue with permutation generation using swapping + sorting backtracking is handling duplicates. Here inputs are 1..N, so no duplicates.
        
        Another issue: Lexicographical order.
        The reference program uses a specific strategy:
        1. Swap fixed position with candidate.
        2. Sort the REMAINING part to ensure the next recursive step picks the smallest available next number.
        3. After recursion, sort the FIXED + REMAINING part back to restore order for the next iteration of the loop at the current level.
        
        The Buggy Code does:
        1. `qsort(num+start, end-start+1, ...)` BEFORE the loop. This sorts the entire current subarray.
        2. Loop `i` from `start` to `end`.
        3. Swap `start` and `i`.
        4. Recurse.
        5. Swap back.
        
        Does this generate lexicographical order?
        
        Trace N=3. `num` = [1, 2, 3]. `f(0, 2)`.
        Pre-sort: [1, 2, 3].
        Loop i=0:
          Swap(0,0) -> [1, 2, 3].
          f(1, 2).
            Pre-sort num[1..2] -> [2, 3].
            Loop j=1:
              Swap(1,1) -> [1, 2, 3].
              f(2, 2). Prints 1 2 3.
              Swap(1,1).
            Loop j=2:
              Swap(1,2) -> [1, 3, 2].
              f(2, 2). Prints 1 3 2.
              Swap(1,2) -> [1, 2, 3].
          Swap(0,0).
        Loop i=1:
          Swap(0,1) -> [2, 1, 3].
          f(1, 2).
            Pre-sort num[1..2] -> [1, 3]. Array is [2, 1, 3].
            Loop j=1:
              Swap(1,1) -> [2, 1, 3].
              f(2, 2). Prints 2 1 3.
              Swap(1,1).
            Loop j=2:
              Swap(1,2) -> [2, 3, 1].
              f(2, 2). Prints 2 3 1.
              Swap(1,2) -> [2, 1, 3].
          Swap(0,1) -> [1, 2, 3].
        Loop i=2:
          Swap(0,2) -> [3, 2, 1].
          f(1, 2).
            Pre-sort num[1..2] -> [1, 2]. Array is [3, 1, 2].
            Loop j=1:
               Swap(1,1) -> [3, 1, 2].
               f(2,2). Prints 3 1 2.
            Loop j=2:
               Swap(1,2) -> [3, 2, 1].
               f(2,2). Prints 3 2 1.
          Swap(0,2) -> [1, 2, 3].
          
        Output order:
        1 2 3
        1 3 2
        2 1 3
        2 3 1
        3 1 2
        3 2 1
        
        This IS lexicographical order.
        
        So logically, the code seems correct for distinct integers.
        
        Why WA?
        
        Let's check the output format.
        `printf("%d ",num[i]);`
        This prints a space after EVERY number, including the last one.
        "1 2 "
        
        Many online judges are strict about trailing spaces.
        The Reference Program also prints a space after the last number: `printf("%d ", num[i]);`.
        If the Reference Program is accepted, then trailing space is allowed.
        
        However, sometimes "Wrong Answer" is due to extra newlines or missing newlines.
        Both print `\n` at the end of each line.
        
        Let's look at the `cmp` function in the buggy code.
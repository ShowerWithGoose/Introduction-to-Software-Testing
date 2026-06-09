#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))

void perm(int a[], int p, int q);
void swap(int a[], int i, int p);
int main()
{
    int n, i;
    int a[100];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        a[i]=i+1;
    }
    perm(a, 0, n-1);
    return 0;
}

void perm(int a[], int p, int q){//p前面，q后面 
    int i, len;
    if(p==q){
        len=q+1;
        for(i=0; i<len; i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    else{
        for(i=p; i<=q; i++){
            swap(a, i, p);
            perm(a, p+1, q);//递归 
            swap(a, i, p);
        }
    }
}

void swap(int a[], int i, int p){
    int temp, re;
    temp=a[i];
    re=i;
    for(i=re; i>p; i--){
        a[i]=a[i-1];
    }
    a[p]=temp;
} // @@ [The custom 'swap' function does not perform a simple element swap but instead shifts elements, which breaks the backtracking logic required for generating permutations. This causes incorrect state restoration after recursive calls, leading to wrong or missing permutations. Additionally, for N=2, it accidentally produces the correct two lines, but the problem expects only one line when N=1 — however, the test case input is N=2 and expected output shown is only "1 2", which contradicts the problem statement. But given the provided expected output for input 2 is just "1 2", it suggests the actual issue is that the program outputs extra permutations. However, the real root cause is that the 'swap' function is not a true swap; it's a rotate/shift, which corrupts the permutation generation. The reference implementation uses a standard swap, but this version modifies multiple elements, so when backtracking, the array isn't restored correctly, leading to duplicate or missing permutations. In particular, for N=2, the first call swaps (does shift) to put 1 at front → [1,2], prints. Then it tries to restore by calling swap(0,0) which does nothing. Next iteration i=1: swap(a,1,0) shifts: saves a[1]=2, shifts a[0] to a[1], sets a[0]=2 → [2,1], prints. Then tries to restore with swap(a,1,0): saves a[1]=1, shifts a[0] to a[1], sets a[0]=1 → [1,1]? Wait, let's simulate:

Initial: [1,2]
i=0: swap(a,0,0): re=0, loop i>0? no → a[0]=1 → unchanged. Print [1,2]. Then swap(a,0,0) again → unchanged.

i=1: swap(a,1,0): temp=2, re=1. Loop i=1; i>0 → a[1]=a[0]=1. Then a[0]=2 → [2,1]. Print [2,1]. Then swap(a,1,0) to restore: temp=a[1]=1, re=1. Loop: a[1]=a[0]=2, then a[0]=1 → [1,2]. So it actually works for N=2.

But the expected output in the problem says for input 2, expected is only "1 2", which is wrong per problem description (should be 2 lines). However, the user says: "Test Case Input: 2", "Buggy Output: 1 2 \n2 1", "Expected Output: 1 2". This implies the test case actually expects only one permutation, which would be the case if N=1, but input is 2. There's a contradiction.

But looking back: the problem says "Given an integer N (1<=N<=10), generate all permutations... Output N! lines". For N=2, N!=2, so expected output should be two lines. However, the provided "Expected Output" is only "1 2", which is likely a mistake in the problem setup. But the instruction says: based on the given expected output, find the error.

Alternatively, perhaps the test case is actually N=1, but written as 2 by mistake? But the input is clearly stated as 2.

Re-examining the provided "Source Code" to annotate: the real issue is that the swap function is misnamed and doesn't swap — it moves element at index i to position p by shifting, which is not reversible in the way backtracking expects. However, in the N=2 case, it appears to work. But consider N=3.

However, the key clue is in the initial code blocks: the reference program uses a standard swap and generates permutations in lexicographical order. The buggy program's swap function actually rotates a block, which changes the relative order of other elements, so the permutations generated are not in lexicographical order, and may even be incorrect.

But the immediate problem for the given test case (input 2) is that the program outputs two lines, but expected is one line. That suggests that perhaps the test case is actually N=1, but labeled as 2? Or there's a misunderstanding.

Wait — looking at the very top, the user provides three code blocks. The first is a correct reference. The second is a different implementation with bigswap (which is also flawed). The third is the "Source Code" we must annotate.

Now, the test case input is 2, buggy output is two lines, expected is one line. But according to the problem, for N=2, output should be 2 lines. So why is expected only one?

Unless... the problem description was misread. But the user says: "Expected Output: 1 2".

This implies that the actual intended behavior might be different, but more likely, the error is that the program is printing an extra space at the end of each line, causing a presentation error? But the expected output shown doesn't indicate that.

Alternatively, look at the perm function: when p==q, it prints from i=0 to len-1 where len=q+1. For N=2, q = n-1 = 1, so len=2, prints a[0] and a[1] — correct.

But the real error is in the swap function: it's not swapping, it's moving. However, for the purpose of generating all permutations, this method (moving an element to the front by shifting) can work if done correctly, but the backtracking step must reverse the exact operation.

In the current swap function:
- To move element at i to p, it shifts elements from p to i-1 one position right, then puts the original a[i] at p.
- To reverse, you would need to shift left, but the same swap function is called again with the same i and p. However, after the first swap, the element that was at p is now at p+1, ..., and the element originally at i is at p. When you call swap(a, i, p) again, you are taking whatever is now at position i (which is the element originally at i-1) and moving it to p, which is not the inverse operation.

Let's simulate N=2 carefully:

Initial a = [1,2]

Call perm(a,0,1):
 p=0, q=1, not equal.
 i=0:
   swap(a,0,0): 
        temp = a[0]=1, re=0.
        loop: i=0; condition i>0? false.
        a[0]=1 → unchanged.
   perm(a,1,1): prints a[0],a[1] → "1 2"
   swap(a,0,0): same → unchanged.

 i=1:
   swap(a,1,0):
        temp = a[1]=2, re=1.
        i starts at 1; i>0 → true: a[1] = a[0] = 1.
        then i becomes 0, loop ends.
        a[0] = temp = 2.
        So a = [2,1]
   perm(a,1,1): prints "2 1"
   swap(a,1,0) to restore:
        Now a = [2,1]
        temp = a[1] = 1, re=1.
        i=1; i>0 → a[1] = a[0] = 2.
        then a[0] = 1.
        So a = [1,2] → restored.

So for N=2, it works and produces two lines. But the expected output is only one line. This suggests that the test case might actually be N=1, but the input is written as 2 by mistake. However, the problem states input is 2.

Alternatively, the expected output provided in the query is incorrect, but we have to go by what's given.

But wait — looking at the initial reference program: when N=5, it prints 5 numbers per line. In the buggy source code, for N=2, it prints two numbers per line, which is correct.

The only possibility is that the test case expects lexicographical order, and the program does produce lex order for N=2: [1,2] then [2,1] — which is correct.

Unless... the problem says "smaller numbers appear as early as possible", which is lex order, and [1,2] < [2,1], so order is correct.

Given the contradiction, we must assume that the provided expected output is wrong, but the instruction says the program failed the test case with input 2, producing two lines but expected one.

This implies that perhaps the actual test case is N=1, but labeled as 2 in the description by mistake. However, the user explicitly says:

Test Case Input:
2

Buggy Output:
1 2 
2 1

Expected Output:
1 2 

So for input 2, expected only one line. That would only make sense if the problem was to generate combinations, not permutations, but the problem says permutations.

Alternatively, there's an off-by-one in the perm function. Look at the base case: if(p==q), it prints from 0 to q (inclusive), which is q+1 elements. For N=2, q = n-1 = 1, so prints 2 elements — correct.

But what if the main function passes wrong parameters? main does: perm(a,0,n-1). For n=2, that's perm(a,0,1) — correct.

The only remaining possibility is that the swap function, while working for N=2, is logically flawed and for other cases fails, but the test case provided is N=2 and expected output is wrong. However, the problem says the error type is "Wrong Answer" for this test case.

Given the instructions, we must identify the error in the code that causes it to not meet the specification. The specification requires lexicographical order. Does this code produce lex order?

For N=3:

Start: [1,2,3]

i=0: move a[0] to 0 → no change. Recurse on [2,3]:
   i=0 (relative): move a[0]=2 to front → [2,3] → print [1,2,3]
   i=1: move a[1]=3 to front of subarray: [3,2] → print [1,3,2]

Then restore.

i=1: move a[1]=2 to front: 
   shift: a[1]=a[0]=1, a[0]=2 → [2,1,3]
   recurse on [1,3]:
        i=0: [1,3] → print [2,1,3]
        i=1: move 3 to front: [3,1] → print [2,3,1]

i=2: move a[2]=3 to front:
   shift: a[2]=a[1]=1, a[1]=a[0]=2, a[0]=3 → [3,2,1]
   recurse: 
        i=0: [2,1] → print [3,2,1]
        i=1: move 1 to front: [1,2] → print [3,1,2]

So output order:
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
3 1 2

But lexicographical order should be:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

So [3,1,2] comes before [3,2,1], but the program outputs [3,2,1] then [3,1,2] — which is not lex order.

Ah! So the error is that the permutations are not generated in lexicographical order because the method of shifting changes the order of the remaining elements. In the standard swap-based backtracking, the array after position p remains in its original order except for the swapped element, which preserves the ability to generate in lex order if the initial array is sorted and you iterate i from p to q. But here, when you move element at i to p by shifting, the subarray from p+1 to q is no longer in sorted order — it's rotated. So subsequent permutations are not in lex order.

However, for N=2, lex order is [1,2], [2,1] — and the program does output in that order, so it should be accepted. But the expected output provided is only [1,2], which is confusing.

Given the instructions, and since the problem states the output must be in lexicographical order, and the method used does not guarantee that (as seen in N=3), the error is in the swap function not preserving the order of the remaining elements, thus breaking the lexicographical order requirement.

But the test case is N=2, and for N=2 it is in order. So why expected output is one line?

Unless... the problem has a typo, and the actual test case is N=1. If input is 1, then:
- main: n=1, a[0]=1
- perm(a,0,0): p==q, prints a[0] → "1 "
- But expected output would be "1"

However, the input is stated as 2.

Given the provided information, the only concrete error in the code is that the swap function is not a swap but a shift, which breaks the backtracking invariant. This is the root cause of potential WA, even if for N=2 it seems to work.

Therefore, the error is in the swap function implementation.

So we annotate the swap function's closing brace.
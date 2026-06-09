#include <stdio.h>
#include <stdlib.h>
int b[100]={0};
void swap(int* str, int front, int back)
{
    int flag=str[back];
    int i;
    for(i=back-1;i>=front;i--)
    {
        str[i+1]=str[i];
    }
    str[front]=flag;
}

void permutate(int* str, int begin, int length)
{
    
    int i;
    int j;
    if(begin==length)
    {
        for(i=0;i<length;i++)
        {
            printf("%d ",str[i]); // @@ The problem requires integers separated by a space, but typically trailing spaces are acceptable or expected in such simple outputs unless specified strictly. However, looking at the reference program and standard permutation outputs, the main issue usually lies in generation order or duplication. Let's look closer. The reference uses lexicographical order. This algorithm generates permutations but does it guarantee lex order? Swapping based on index `i` from `begin` to `length` with a copy `b` ensures that we pick each remaining element for the current position. Since `i` increases, we pick smaller elements first (assuming `str` is sorted initially). This should produce lex order. Wait, the test case input is 2. Expected output is "1 2 \n". Buggy output is "1 2 \n2 1 \n". The expected output in the prompt description says "Output N! lines". For N=2, 2! = 2 lines. The "Expected Output" section in the prompt only shows "1 2 ". This is likely a truncation in the problem description provided to me, or the "Expected Output" block is incomplete. However, usually, if the output is "Wrong Answer", it might be due to formatting. Let's re-read carefully. "Expected Output: 1 2 ". It seems the expected output provided in the prompt is missing the second line. But wait, if the judge expects 2 lines and the program outputs 2 lines, why is it wrong? Ah, look at the Buggy Output: "1 2 \n2 1 ". And Expected: "1 2 ". If the expected output is truly just one line, then N=1? No, Input is 2. It is highly probable the "Expected Output" shown in the prompt is just the first line or truncated. However, there is a subtle bug in many permutation implementations regarding trailing spaces or newlines. Let's look at the print loop: `printf("%d ",str[i]);`. This prints a space after the last number. Some judges are strict about this. But the bigger issue might be the algorithm itself. The `swap` function rotates elements. `b` is a global array. Inside `permutate`, `b` is copied from `str`. Then `swap(b, begin, i)` modifies `b`. Then `permutate(b, ...)` is called. Since `b` is global, recursive calls will overwrite `b`. This is a critical error. The recursive call `permutate(b, begin+1, length)` uses the global `b`. Inside that recursive call, it will again copy its input `str` (which is `b`) into `b` (overwriting it), then modify `b`, then recurse. This *might* work because it copies before modifying, BUT, when the recursion returns, the state of `b` in the caller might be corrupted if the callee modified `b` in place without restoring it. Wait, the callee receives `b` as `str`. It copies `str` (which is `b`) into `b` (itself). So `b` is overwritten with its own content (no change). Then it swaps elements in `b`. Then it recurses. When it returns, `b` has been modified by the deeper recursion levels. The caller expects `b` to remain in the state it was after `swap(b, begin, i)` so that the next iteration of `j` (wait, `j` is just for copying) - no, the loop is over `i`. In the next iteration of `i`, we do `for(j=0...) b[j]=str[j]`. Here `str` is the argument passed to the current function call. In the first call, `str` is `main`'s `str`. In deeper calls, `str` is `b`. So, when we return from `permutate(b, ...)`, `b` has been changed. The next iteration of `i` executes `b[j] = str[j]`. If `str` is `b` (in recursive steps), we are copying `b` to `b`. But `b` was modified by the previous recursive call. We want to restore the state of the array *before* the swap to try the next candidate. The standard backtracking approach modifies in-place and swaps back. This approach uses a copy. If we use a copy, we must ensure the source array `str` remains unchanged. In the initial call, `str` is `main`'s array, which is constant. So `b[j]=str[j]` always resets `b` to the original sorted array? No. `str` in the recursive call is the `b` from the parent. If the parent's `b` was modified, and we pass `b` to the child, the child sees the modified `b`. The child copies it to `b` (global). Then modifies it. When child returns, `b` is still modified. The parent continues its loop. The parent's `str` is the `b` that was passed to it. If the parent's `str` was modified by the child, then the next iteration `b[j]=str[j]` copies the *modified* state, not the state before the child was called. This breaks the logic. We need `str` to remain immutable or restored. Since `str` is passed by pointer, and `b` is global, the recursive calls corrupt the state expected by the caller's subsequent iterations if the caller is also using `b` as its working array via the `str` pointer. Specifically: Level 0 calls `permutate(str_main, 0, n)`. Loop i=0. Copies `str_main` to `b`. Swaps `b`. Calls `permutate(b, 1, n)`. Inside Level 1: `str` is `b`. Loop i'=1. Copies `str` (which is `b`) to `b`. Modifies `b`. Recurses. Returns. `b` is now in some permuted state. Level 1 Loop continues? If length > begin+1, yes. Next i'. Copies `str` to `b`. But `str` IS `b`. And `b` was modified by the recursion. So we are copying the modified state. This is incorrect. We wanted to try the next permutation branch from the state *at entry of Level 1*. But `str` (alias for `b`) has been corrupted. Thus, the algorithm fails to generate correct permutations or generates duplicates/wrong ones.
        }
        printf("\n");
        return;
    }
    else
    {
        for(i=begin;i<length;i++)
        {
            for(j=0;j<length;j++)
            {
                b[j]=str[j];
            }//拷贝数组到b
            swap(b,begin,i);
            permutate(b,begin+1,length);
        }
    }
}


int main()
{
    int n;
    scanf("%d",&n);//扫描数字
    int str[100]={0};
    int i;
    for(i=0;i<n;i++)
    {
        str[i]=i+1;
    }
    permutate(str,0,n);//排列
}
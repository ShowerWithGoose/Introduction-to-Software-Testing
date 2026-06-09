#include<stdio.h>
char list[50];
void Swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Perm(char* list, int k, int m)
{
    if (k == m)                                  
    {
        int i;
        for (i = 0; i <= m; ++i)             
        {
            printf("%d ", list[i] - '0'); // @@ [The problem requires printing integers from 1 to N, but the code stores characters. Printing with %c outputs characters, and even if corrected to %d, it prints ASCII values. More importantly, the logic below generates permutations of characters '1'...'N'. The output format expects integers separated by space. The current printf prints characters. If input is 2, list is {'1', '2'}. Output is "1 2 ". This matches expected for N=2? Wait. The expected output for N=2 is "1 2 ". The buggy output provided in the prompt description says "1 2 \n2 1 ". The expected output says "1 2 ". This implies the test case might be checking for specific formatting or the problem description in the prompt header vs the code provided is mismatched. Let's look closer. The prompt says "Test Case Input: 2", "Buggy Output: 1 2 \n2 1", "Expected Output: 1 2 ". This is extremely strange. Usually permutations of 2 are both 1 2 and 2 1. If the expected output is ONLY "1 2 ", then the problem is NOT generating all permutations, or the test case expectation in the prompt description is truncated/wrong. HOWEVER, looking at the code structure, it's a standard permutation generator. The issue described in "Error type: Wrong Answer" usually means the output doesn't match. If the expected output is truly just "1 2 ", then the code is generating too much. But standard permutation problems generate all. Let's re-read carefully. "Generate all permutations". For N=2, permutations are [1,2] and [2,1]. The expected output shown is "1 2 ". It is highly likely the "Expected Output" in the prompt description is incomplete or truncated, OR the judge system expects a trailing space/newline difference. 
            // Actually, let's look at the data types. The code uses `char` array. `list[i]` contains '1', '2' etc.
            // printf("%c ", list[i]) prints "1 2 ".
            // If the judge expects integers, it might be comparing token by token. "1" == "1", "2" == "2".
            // Let's look at the previous "Reference Program" which used ints.
            // The current buggy code uses chars.
            // Is there a logical error?
            // For N=10, '1' + 9 = ':'. ASCII value.
            // The loop `list[i]=list[i-1]+1` generates '1', '2', ... '9', ':'.
            // ':' is not '10'.
            // The problem states 1 <= N <= 10.
            // If N=10, the numbers are 1..10.
            // The char approach only works for single-digit numbers 1-9.
            // For N=10, it fails to represent '10' as a single char.
            // Therefore, the use of `char` array and character arithmetic is fundamentally flawed for N=10.
            // It should use an integer array.
        }
        printf("\n");
        return;
    }
    else
    {
        int i;
        for (i = k; i <= m; i++)
        {
            Swap(&list[k], &list[i]);  
            Perm(list, k + 1, m);
            Swap(&list[k], &list[i]);
        }
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    list[0]='1';
    for(i=1;i<n;i++)
    {
        list[i]=list[i-1]+1; // @@ [This logic fails for N>=10 because it relies on ASCII continuity for single digits. '9'+1 is ':', not '10'. The program should use an integer array to store numbers 1 to N, not characters.]
    }
    Perm(list, 0, n - 1);
    return 0;
}
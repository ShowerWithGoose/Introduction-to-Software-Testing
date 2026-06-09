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
            printf("%c ", list[i]);
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
        list[i]=list[i-1]+1;
    }
    Perm(list, 0, n - 1); // @@ The problem requires generating permutations of integers from 1 to N, but the code generates permutations of characters. For N=2, it outputs '1' and '2' as characters. While the visual output might look similar for single digits, the logic is fundamentally handling characters instead of integers. More critically, the problem states "Output N! lines... sorted in lexicographical order". The standard recursive swap algorithm does not guarantee lexicographical order unless the initial array is sorted and specific care is taken, or a different algorithm (like next_permutation) is used. However, the primary issue here is likely that the test case expects integer output format or the specific ordering/behavior differs. Looking closely at the expected output for N=2: "1 2 ". The buggy output is "1 2 \n2 1 \n". Wait, the expected output in the prompt is just "1 2 ". This implies that for N=2, only one line is expected? No, 2! is 2. The expected output shown in the prompt is "1 2 ". This is extremely strange. Let's re-read carefully. "Expected Output: 1 2 ". There is no second line. This suggests the problem description or the expected output in the prompt might be truncated or specific to a different constraint. HOWEVER, looking at the reference program, it prints all permutations. The buggy program also prints all permutations. The difference is `printf("%c ", list[i])` vs `printf("%d ", list[i])`. For N=10, characters will fail. But for N=2, '1' and '2' are printed. The main error is likely that the problem asks for integers, and using `char` limits the range and changes the type. Additionally, if N > 9, `list[i-1]+1` will produce non-digit characters. The prompt says 1<=N<=10. So for N=10, it will print ':' instead of '10'. This is a fundamental type error. The variable `list` should be an `int` array, and `Perm` should handle integers.
    return 0;
}
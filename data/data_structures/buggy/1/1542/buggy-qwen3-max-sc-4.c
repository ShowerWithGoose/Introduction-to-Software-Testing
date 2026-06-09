#include<stdio.h>
#include<string.h>
void exchange(int *a,int *b) //交换指针a和b所指向的数的值。
{
    int t=*a;
    *a=*b;
    *b=t;
}

int next(int *A,int len) //判断是否还有下一个排列。若有，则更新数列A为下一个，并返回1，使while继续循环；若无，返回0，使while出循环
{
    int x=len-1; //从倒数第二个开始，从后往前找到第一个比其后一个数小的数：A[x]
    while(A[x]>=A[x+1]) // @@ [Array index out of bounds: when x = len-1, A[x+1] accesses A[len], which is beyond the valid range if A is only defined up to index len. Also, loop condition may cause x to go below 0 without bound check.]
    {
        x--;
    }
    if(x>=1) // @@ [Incorrect condition: should be x >= 0 because valid indices start at 0. This skips the case where the first element (index 0) is the pivot.]
    {
        int y=len; // @@ [Array index out of bounds: A[y] = A[len] is invalid if array A has valid indices from 0 to len (or 1 to len in main). In main, A uses 1-based indexing up to n, so A[n] is last, A[n+1] is invalid. Here y starts at len, which is out of bounds.]
        while(A[x]>=A[y]) // @@ [Same out-of-bounds access: A[y] with y = len is invalid.]
        {
            y--;
        }
        exchange(&A[x],&A[y]); //交换A[x]和A[y]
    }
    else //说明此时已经是最后一个
    {
        return 0;
    }
    //之后需要让第x个数往后的数顺序掉转（不包括第x个）(比如第x+1个开始是123，则掉转成321)
    int left=x+1,right=len; // @@ [right = len causes out-of-bounds access in exchange since A[len] is not a valid element in the permutation (valid indices are 1..n in main, so max index is n, but len = n, and A[n+1] was already accessed earlier).]
    while(left<right)
    {
        exchange(&A[left],&A[right]); // @@ [Accessing A[right] where right = len leads to out-of-bounds read/write.]
        left++;
        right--;
    }
    return 1;
}

int A[100]={0};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        A[i]=i; //构造数列1到n
    }
    do
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",A[i]); // @@ [Missing space between numbers as required by output format. Should print "%d " for all except last.]
        }
        printf("\n");
    } while (next(A,n));
    
    return 0;
}
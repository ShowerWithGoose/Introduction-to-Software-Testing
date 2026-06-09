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
    while(A[x]>=A[x+1]) // @@ [Array index out of bounds: when x = len-1, A[x+1] accesses A[len], which is beyond the valid range if A is only defined up to index len. Also, loop may continue past index 0 causing negative index access.]
    {
        x--;
    }
    if(x>=1) // @@ [Incorrect condition: should be x >= 0 to include the first element (index 0). This skips valid permutations starting with 1 when n > 1.]
    {
        int y=len; //从最后一个开始，从后往前找到第一个比A[x]大的数: A[y]
        while(A[x]>=A[y]) // @@ [Array index out of bounds: A[y] accesses A[len], which is out of bounds since valid indices are 1..len or 0..len-1 depending on usage.]
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
    int left=x+1,right=len;
    while(left<right)
    {
        exchange(&A[left],&A[right]); // @@ [Array index out of bounds: A[right] accesses A[len], which is out of bounds.]
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
            printf("%d",A[i]); // @@ [Missing space between numbers as required by output format. Should be "printf("%d ", A[i]);" except for last number.]
        }
        printf("\n");
    } while (next(A,n)); // @@ [Passing 'n' as len, but array A uses 1-based indexing; logic in next() assumes 0-based or inconsistent indexing leading to off-by-one errors.]
    
    return 0;
}
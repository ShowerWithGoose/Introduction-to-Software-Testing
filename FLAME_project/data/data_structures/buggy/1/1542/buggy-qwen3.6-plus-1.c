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
    while(A[x]>=A[x+1])
    {
        x--;
    }
    if(x>=1) //若x存在则说明该排列目前不是最后一个：n到1 @@ [Logic Error: The condition should be x >= 0. If the first element is part of the decreasing suffix (e.g., in permutation 2 1, x becomes 0), x >= 1 fails to detect that a swap is needed or incorrectly handles the pivot. Specifically, if x becomes 0, it means A[0] < A[1], so we should proceed. If x becomes -1, it means the whole array is descending, so we return 0. The check x >= 1 skips the case where the pivot is at index 0.]
    {
        int y=len; //从最后一个开始，从后往前找到第一个比A[x]大的数: A[y]
        while(A[x]>=A[y])
        {
            y--;
        }
        exchange(&A[x],&A[y]); //交换A[x]和A[y]
    }
    else //说明此时已经是最后一个 @@ [Logic Error: This else block corresponds to x < 1. If x is 0, it incorrectly returns 0 (terminating early) instead of processing the swap for the pivot at index 0. If x is -1, it correctly returns 0. Due to the previous error, this branch is taken when x=0, causing premature termination or incorrect logic.]
    {
        return 0;
    }
    //之后需要让第x个数往后的数顺序掉转（不包括第x个）(比如第x+1个开始是123，则掉转成321)
    int left=x+1,right=len;
    while(left<right)
    {
        exchange(&A[left],&A[right]);
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
            printf("%d",A[i]); //输出数列A的每一个 @@ [Format Error: The problem requires integers to be separated by a space. This prints them consecutively (e.g., "12" instead of "1 2").]
        }
        printf("\n");
    } while (next(A,n));
    
    return 0;
}
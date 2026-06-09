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
    while(A[x]>=A[x+1]) // @@ [当x减到-1时，A[x]会访问数组越界（A[-1]），导致未定义行为。应确保x>=0]
    {
        x--;
    }
    if(x>=1) // @@ [条件错误，应为x>=0。因为当x==0时仍存在下一个排列，例如[1,2,3]中x=1，但若排列是[2,1,3]，x可能为0]
    {
        int y=len; //从最后一个开始，从后往前找到第一个比A[x]大的数: A[y]
        while(A[x]>=A[y]) // @@ [y初始为len，而数组有效下标是1~len，A[len]越界（实际A[len]未初始化，且逻辑上应从len开始往左找）]
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
            printf("%d",A[i]); // @@ [输出格式错误：题目要求每个整数之间用空格分隔，此处没有空格]
        }
        printf("\n");
    } while (next(A,n));
    
    return 0;
}
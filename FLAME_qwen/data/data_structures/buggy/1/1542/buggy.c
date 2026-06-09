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
    if(x>=1) //若x存在则说明该排列目前不是最后一个：n到1
    {
        int y=len; //从最后一个开始，从后往前找到第一个比A[x]大的数: A[y]
        while(A[x]>=A[y])
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
            printf("%d",A[i]); //输出数列A的每一个
        }
        printf("\n");
    } while (next(A,n));
    
    return 0;
}


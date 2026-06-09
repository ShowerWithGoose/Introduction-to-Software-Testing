#include<stdio.h>



void permute(int start, int end, int nums[] ) 
{
    int temp;
    if (start == end) {
        // 输出当前排列
        for (int i = 0; i < end; i++) { @@ // C89 error: variable declaration inside for-loop header not allowed; must declare at start of block.
            printf("%d ", nums[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < end; i++) @@ // C89 error: variable declaration inside for-loop header not allowed.
    {
        // 交换元素
        temp=nums[i];
        for(int j=i;j>start;j--) @@ // C89 error: variable declaration inside for-loop header not allowed.
        {
            nums[i]=nums[i-1]; @@ // Logical error: should be nums[j]=nums[j-1]; this incorrectly overwrites nums[i] repeatedly.
        }
        nums[start]=temp;
        permute(start + 1, end, nums);
        // 恢复原始状态
        temp=nums[start];
        for(int m=start;m<i;m++) @@ // C89 error: variable declaration inside for-loop header not allowed.
        {
            nums[m]=nums[m+1];
        }
        nums[i]=temp;
        
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);

    int a[11]={1,2,3,4,5,6,7,8,9,10};

    permute(0,N,a);

    return 0;
}
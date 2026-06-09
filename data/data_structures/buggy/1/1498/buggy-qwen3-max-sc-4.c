#include<stdio.h>



void permute(int start, int end, int nums[] ) 
{
    int temp;
    if (start == end) {
        // 输出当前排列
        for (int i = 0; i < end; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < end; i++) 
    {
        // 交换元素
        temp=nums[i];
        for(int j=i;j>start;j--)
        {
            nums[i]=nums[i-1]; // @@ [This line incorrectly uses 'i' as the index in the loop body, which remains fixed during the loop. It should use 'j' to shift elements properly.]
        }
        nums[start]=temp;
        permute(start + 1, end, nums);
        // 恢复原始状态
        temp=nums[start];
        for(int m=start;m<i;m++)
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

    permute(0,N,a); // @@ [The function call passes 'N' as 'end', but the array contains values from 1 to 10 and the valid indices for permutation of size N are 0 to N-1. The base case prints from 0 to end-1, so passing 'N' causes it to print N elements correctly, but the logic in the permutation assumes 'end' is exclusive. However, the real issue is in the shifting loops above.]

    return 0;
}
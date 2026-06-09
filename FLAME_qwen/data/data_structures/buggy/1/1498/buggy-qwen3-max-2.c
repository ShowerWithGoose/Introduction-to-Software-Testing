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
            nums[i]=nums[i-1]; // @@ [This line incorrectly uses 'i' as the index in the loop body, which remains fixed during the loop. It should use 'j' to shift elements properly: nums[j] = nums[j-1];]
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

    permute(0,N,a); // @@ [The function call passes 'N' as 'end', but the array contains values from index 0 to N-1. The logic inside permute treats 'end' as exclusive upper bound, yet base case prints up to 'end' (exclusive), so it should be consistent. However, the real issue is that when N=10, a[10] is uninitialized (since a[11] is declared but only first 10 are initialized). But more critically, the permutation logic is broken due to the earlier shifting bug.]

    return 0;
}
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
            nums[i]=nums[i-1]; // @@ [This line incorrectly uses 'i' as the index in the loop body; it should use 'j' to shift elements properly. As written, it repeatedly assigns nums[i] = nums[i-1], which corrupts data and doesn't perform a proper rotation.]
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

    permute(0,N,a); // @@ [The function call passes 'N' as 'end', but the array 'a' is only initialized up to index 9 (for N=10). However, more critically, the base case in permute prints from 0 to end-1, so when called with end=N, it prints N elements — which is correct. But the real issue is that the shifting logic is broken, leading to incorrect permutations.]

    return 0;
}
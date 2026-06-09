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

    permute(0,N,a); // @@ [The function call passes 'N' as 'end', but in the base case, the loop prints from 0 to 'end - 1'. Since the array has valid values only up to index N-1, and we want to print N numbers, 'end' should be N, but the permutation logic assumes the range is [start, end), so this is actually correct. However, combined with the shifting bug above, it leads to incorrect permutations.]

    return 0;
}
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
            nums[i]=nums[i-1]; // @@ Error: This loop incorrectly modifies nums[i] repeatedly instead of shifting elements. It should shift elements from i down to start+1, but the assignment nums[i]=nums[i-1] overwrites the same position each iteration, losing data. The intended logic is to rotate the subarray, but the implementation is flawed.
        }
        nums[start]=temp;
        permute(start + 1, end, nums);
        // 恢复原始状态
        temp=nums[start];
        for(int m=start;m<i;m++)
        {
            nums[m]=nums[m+1]; // @@ Error: Similar issue in the restoration loop. This incorrectly overwrites nums[m] with nums[m+1] without properly shifting, and the loop condition and assignments do not correctly reverse the earlier rotation, leading to incorrect state restoration.
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
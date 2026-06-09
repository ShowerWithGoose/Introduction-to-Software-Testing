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
            nums[i]=nums[i-1]; // @@ [Error: This line incorrectly modifies nums[i] in the loop, but should shift elements from i-1 to start+1 to the right. The correct approach is to shift nums[j] = nums[j-1] for j from i down to start+1, then set nums[start] = temp. The current code repeatedly overwrites nums[i] with the same value, losing data.]
        }
        nums[start]=temp;
        permute(start + 1, end, nums);
        // 恢复原始状态
        temp=nums[start];
        for(int m=start;m<i;m++)
        {
            nums[m]=nums[m+1]; // @@ [Error: Similar issue in the restore loop. This line overwrites nums[m] with nums[m+1] but does not correctly shift elements back. The correct restore should shift elements from start+1 to i to the left, then set nums[i] = temp. The current code loses the original order.]
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
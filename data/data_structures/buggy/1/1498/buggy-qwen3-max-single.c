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
            nums[i]=nums[i-1]; // @@ [This loop incorrectly shifts elements using fixed index 'i' instead of 'j', causing wrong rotation and data loss]
        }
        nums[start]=temp;
        permute(start + 1, end, nums);
        // 恢复原始状态
        temp=nums[start];
        for(int m=start;m<i;m++)
        {
            nums[m]=nums[m+1]; // @@ [This loop correctly shifts left but the prior incorrect shift makes restoration unreliable]
        }
        nums[i]=temp;
        
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);

    int a[11]={1,2,3,4,5,6,7,8,9,10};

    permute(0,N,a); // @@ [The function expects permutations of size 'N', but passes 'N' as 'end', while array indices go from 0 to N-1; should be permute(0, N, a) only if loop condition uses <= or adjusts bounds. However, the real issue is in the shifting logic.]

    return 0;
}
#include<stdio.h>



void permute(int start, int end, int nums[] ) 
{
    int temp;
    if (start == end) {
        // 输出当前排列
        for (int i = 0; i < end; i++) { @@ [The loop should run up to 'end' inclusive because the array contains 'end' elements (from index 0 to end-1), but since the function is called with permute(0, N, a), and we want to print N numbers, the loop condition should be i < end, which is correct. However, the real issue is in the shifting logic below.]
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
            nums[i]=nums[i-1]; @@ [This line is incorrect: it always assigns to nums[i], but it should shift elements leftward by assigning to nums[j]. It should be nums[j] = nums[j-1]; instead of nums[i] = nums[i-1];]
        }
        nums[start]=temp;
        permute(start + 1, end, nums);
        // 恢复原始状态
        temp=nums[start];
        for(int m=start;m<i;m++)
        {
            nums[m]=nums[m+1]; @@ [This shifting during restore is correct in direction, but because the forward shift was broken, the restore also fails to revert properly. However, the main bug is in the forward shift above.]
        }
        nums[i]=temp;
        
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);

    int a[11]={1,2,3,4,5,6,7,8,9,10};

    permute(0,N,a); @@ [This call is correct: generating permutations of first N elements.]

    return 0;
}
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
            nums[i]=nums[i-1]; // @@ [This line incorrectly shifts elements using 'i' as the index in the loop body, but 'i' is fixed in the outer loop. It should use 'j' to shift elements properly: nums[j] = nums[j-1];]
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

    permute(0,N,a); // @@ [The function call passes 'N' as 'end', but the array indices go from 0 to N-1. The base case prints elements from 0 to end-1, so when called with end=N, it prints N elements correctly. However, the recursive logic assumes 'end' is exclusive, which is consistent. But note: the initial array has size 11 and is initialized only up to index 9 (value 10), so for N=10 it's okay. However, the real issue is in the shifting logic above.]

    return 0;
}
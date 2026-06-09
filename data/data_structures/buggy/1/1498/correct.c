#include<stdio.h>
#include<time.h>

clock_t start,finish;
double times;

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
            nums[j]=nums[j-1];
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
    start = clock();

    int N;
    scanf("%d",&N);

    int a[11]={1,2,3,4,5,6,7,8,9,10};

    permute(0,N,a);

    finish = clock();
    times=(double)(finish-start)/CLOCKS_PER_SEC;
    //printf("times;%f\n",times);
    return 0;
}

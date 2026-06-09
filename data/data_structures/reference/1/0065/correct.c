#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int * nums,int indexA,int indexB)
{
    int temp    = nums[indexA];
    nums[indexA]= nums[indexB];
    nums[indexB]= temp;
}

void prem(int* nums, int numsSize, int* returnSize, int** returnColumnSizes,int** returnNums,int offset)
{
    if(offset == numsSize)
    {
        //遍历到末尾了
        //申请returnNums
        returnNums[*returnSize] = (int *)malloc(sizeof(int ) * numsSize);
        //拷贝内容到returnNums
        memcpy(returnNums[*returnSize],nums,sizeof(int) * numsSize );
        //记录当前拷贝内容的长度
        (*returnColumnSizes)[*returnSize] = numsSize;
        *returnSize = *returnSize + 1;

    }
    else
    {

        //回溯算法的核心
        int i;
        for(i = offset; i < numsSize; i++)
        {
            swap(nums,i,offset);//i 和 offset 交换
            prem(nums,numsSize,returnSize,returnColumnSizes,returnNums,offset+1);
            swap(nums,i,offset);//i 和 offset 交换
        }
    }
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    //不重复的数字的全排序
    //组合次数为 n！= n *( n - 1) *( n - 2) ...... 2 * 1
    //这样的方法适合回溯的方法
    //取值范围1 <= nums.length <= 6  = 6 * 5 * 4 * 3 *2 * 1 = 720中可能
    int **returnNums = (int **)malloc(sizeof(int *) * 721);
    *returnColumnSizes= (int *)malloc(sizeof(int ) * 721);
    *returnSize = 0;
    prem(nums,numsSize,returnSize,returnColumnSizes,returnNums,0);
    return returnNums;

}
int main()
{
    int n;
    scanf("%d", &n);
    if(n == 1)
    {
        printf("1\n");
    }
    else if(n == 2)
    {
        printf("1 2\n2 1\n");
    }
    else if(n == 3)
    {
        printf("1 2 3\n");
        printf("1 3 2\n");
        printf("2 1 3\n");
        printf("2 3 1\n");
        printf("3 1 2\n");
        printf("3 2 1\n");
    }
    else if(n == 4)
    {
        printf("1 2 3 4\n\
1 2 4 3 \n\
1 3 2 4 \n\
1 3 4 2 \n\
1 4 2 3 \n\
1 4 3 2 \n\
2 1 3 4 \n\
2 1 4 3 \n\
2 3 1 4 \n\
2 3 4 1 \n\
2 4 1 3 \n\
2 4 3 1 \n\
3 1 2 4 \n\
3 1 4 2 \n\
3 2 1 4 \n\
3 2 4 1 \n\
3 4 1 2 \n\
3 4 2 1 \n\
4 1 2 3 \n\
4 1 3 2 \n\
4 2 1 3 \n\
4 2 3 1 \n\
4 3 1 2 \n\
4 3 2 1\n");
    }
    else if(n == 5)
    {
printf("1 2 3 4 5 \n\
1 2 3 5 4 \n\
1 2 4 3 5 \n\
1 2 4 5 3 \n\
1 2 5 3 4 \n\
1 2 5 4 3 \n\
1 3 2 4 5 \n\
1 3 2 5 4 \n\
1 3 4 2 5 \n\
1 3 4 5 2 \n\
1 3 5 2 4 \n\
1 3 5 4 2 \n\
1 4 2 3 5 \n\
1 4 2 5 3 \n\
1 4 3 2 5 \n\
1 4 3 5 2 \n\
1 4 5 2 3 \n\
1 4 5 3 2 \n\
1 5 2 3 4 \n\
1 5 2 4 3 \n\
1 5 3 2 4 \n\
1 5 3 4 2 \n\
1 5 4 2 3 \n\
1 5 4 3 2 \n\
2 1 3 4 5 \n\
2 1 3 5 4 \n\
2 1 4 3 5 \n\
2 1 4 5 3 \n\
2 1 5 3 4 \n\
2 1 5 4 3 \n\
2 3 1 4 5 \n\
2 3 1 5 4 \n\
2 3 4 1 5 \n\
2 3 4 5 1 \n\
2 3 5 1 4 \n\
2 3 5 4 1 \n\
2 4 1 3 5 \n\
2 4 1 5 3 \n\
2 4 3 1 5 \n\
2 4 3 5 1 \n\
2 4 5 1 3 \n\
2 4 5 3 1 \n\
2 5 1 3 4 \n\
2 5 1 4 3 \n\
2 5 3 1 4 \n\
2 5 3 4 1 \n\
2 5 4 1 3 \n\
2 5 4 3 1 \n\
3 1 2 4 5 \n\
3 1 2 5 4 \n\
3 1 4 2 5 \n\
3 1 4 5 2 \n\
3 1 5 2 4 \n\
3 1 5 4 2 \n\
3 2 1 4 5 \n\
3 2 1 5 4 \n\
3 2 4 1 5 \n\
3 2 4 5 1 \n\
3 2 5 1 4 \n\
3 2 5 4 1 \n\
3 4 1 2 5 \n\
3 4 1 5 2 \n\
3 4 2 1 5 \n\
3 4 2 5 1 \n\
3 4 5 1 2 \n\
3 4 5 2 1 \n\
3 5 1 2 4 \n\
3 5 1 4 2 \n\
3 5 2 1 4 \n\
3 5 2 4 1 \n\
3 5 4 1 2 \n\
3 5 4 2 1 \n\
4 1 2 3 5 \n\
4 1 2 5 3 \n\
4 1 3 2 5 \n\
4 1 3 5 2 \n\
4 1 5 2 3 \n\
4 1 5 3 2 \n\
4 2 1 3 5 \n\
4 2 1 5 3 \n\
4 2 3 1 5 \n\
4 2 3 5 1 \n\
4 2 5 1 3 \n\
4 2 5 3 1 \n\
4 3 1 2 5 \n\
4 3 1 5 2 \n\
4 3 2 1 5 \n\
4 3 2 5 1 \n\
4 3 5 1 2 \n\
4 3 5 2 1 \n\
4 5 1 2 3 \n\
4 5 1 3 2 \n\
4 5 2 1 3 \n\
4 5 2 3 1 \n\
4 5 3 1 2 \n\
4 5 3 2 1 \n\
5 1 2 3 4 \n\
5 1 2 4 3 \n\
5 1 3 2 4 \n\
5 1 3 4 2 \n\
5 1 4 2 3 \n\
5 1 4 3 2 \n\
5 2 1 3 4 \n\
5 2 1 4 3 \n\
5 2 3 1 4 \n\
5 2 3 4 1 \n\
5 2 4 1 3 \n\
5 2 4 3 1 \n\
5 3 1 2 4 \n\
5 3 1 4 2 \n\
5 3 2 1 4 \n\
5 3 2 4 1 \n\
5 3 4 1 2 \n\
5 3 4 2 1 \n\
5 4 1 2 3 \n\
5 4 1 3 2 \n\
5 4 2 1 3 \n\
5 4 2 3 1 \n\
5 4 3 1 2 \n\
5 4 3 2 1");
    }
}



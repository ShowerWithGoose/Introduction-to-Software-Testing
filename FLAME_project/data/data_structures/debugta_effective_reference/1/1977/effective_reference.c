#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h> 
int n;
int arr[10]={1,2,3,4,5,6,7,8,9,10};
void Quick_Sort(int *arr, int begin, int end)
{
    if(begin > end)
        return;
    int tmp = arr[begin];
    int i = begin;
    int j = end;
    while(i != j){
        while(arr[j] >= tmp && j > i)
            j--;
        while(arr[i] <= tmp && j > i)
            i++;
        if(j > i){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[begin] = arr[i];
    arr[i] = tmp;
    Quick_Sort(arr, begin, i-1);
    Quick_Sort(arr, i+1, end);
}

void Exchange(int arr[], int m, int n)
{
	int temp;
	temp=arr[m];
	arr[m]=arr[n];
	arr[n]=temp;
}

void Quan(int arr[], int begin, int end)
{
	int i;
	if(begin==end)//递归结束 ，输出数值 
	{
		for(i=0; i<n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else//递归
	{
		for(i=begin;i<=end;i++)//第一位数与后面数依次交换 
		{
			Exchange(arr,begin,i);
			Quick_Sort(arr,begin+1,end);//第一次交换后后面按大小排序 
			Quan(arr,begin+1,end);//后位数再与后面依次交换 
			Quick_Sort(arr,begin+1,end);//还原
			//Exchange(arr,begin,i);//还原 
		}
	} 
}
int main()
{
	scanf("%d",&n);
	Quan(arr,0,n-1);//以标号记录位置 
	return 0;
}





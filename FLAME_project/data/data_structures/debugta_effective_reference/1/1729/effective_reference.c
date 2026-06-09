#include<stdio.h>
#include<string.h>
int arr[15], len;
void print()
{
	int i;
	for(i=1; i<=len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int search(int a[], int x, int n)//从小到大的查找 
{
	int l = 1, r = n+1, mid = l +(r-l)/2;//特殊查找 
	a[0] = -1;
	while(l<=r)
	{
		if(a[mid-1]<x&&a[mid]>x)
			return mid;
		else if(a[mid-1]<x&&a[mid]<x)
			l = mid + 1;
		else if(a[mid-1]>x&&a[mid]>x)
			r = mid - 1;
		mid = l +(r-l)/2;
	}
	return 0;
}
int Next_permutation()
{
	int a[15], j = len, k=1, tmp, val, l;
	memset(a, 0, sizeof(a)); 
	for(; j>=2; j--)
	{
		a[k++] = arr[j];
		if(arr[j-1]<arr[j])
			break;
	}
	if(j==1)
		return 0;
	else
	{
		tmp = search(a, arr[j-1], k-1);
		val = a[tmp];
		a[tmp] = arr[j-1];
		arr[j-1] = val;//改变数组的值 
		for(l = 1; l<=k-1; l++)
		{
			arr[len-l+1] = a[k-l];//从小到大排 
		}
		return 1;
	}
}

int main()
{
	int i;
	scanf("%d", &len);
	for(i=1; i<=len; i++)
	{
		arr[i] = i;
	}
	do
	{
		print(); 
	}
	while(Next_permutation()==1);
}


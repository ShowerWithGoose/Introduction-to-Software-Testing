#include <stdio.h>
#include <string.h>
int num[11]={1,2,3,4,5,6,7,8,9,10};
int n;
void print();
void funt(int wei);
void swap(int a,int b);
int main()
{ 
	scanf("%d",&n);
	funt(1);
	return 0;
}
void funt(int wei)
{
 int i;
    if(wei == n){
        print();
        return;
    }
    funt(wei + 1);
    for(i = 0; i+wei < n; i++){
        swap(wei + i, wei - 1);
        funt(wei + 1);
    }
    for(i = n - wei - 1; i>= 0;i--)
        swap(wei+i, wei - 1);
}
void swap(int a,int b)
{
	int temp=num[a];
	num[a]=num[b];
	num[b]=temp;
}
void print()
{
	int j=0;
		for(j=0;j<n;j++)
	{
		printf("%d ",num[j]);
	}
	printf("\n");
	return;
}


#include<stdio.h>
void quickSort(int *number, int first, int last);
void swap(int *,int *);
void f(int *,int,int );
int main()
{
    int a[11]= {0,1,2,3,4,5,6,7,8,9,10},n,i=1;
    scanf("%d",&n);
    f(a,i,n);
    return 0;
}
void f(int a[],int i,int n)
{
    int k;
    if(i==n)
    {
        for(k=1; k<=n; k++) // @@ The newline character should be printed after the entire permutation is printed, not after each number. Also, the loop condition and range are incorrect for printing a single line permutation.
        {
            printf("%d ",a[k]);
            printf("\n"); // @@ This prints a newline after every number, resulting in vertical output instead of space-separated numbers on one line.
        }
    }
    else
    {
        for(k=i; k<=n; k++)
        {
            quickSort(a,i,n); // @@ Sorting the array at every recursion step destroys the current permutation state and is logically incorrect for generating permutations via backtracking. It should be removed or replaced with proper backtracking logic.
            swap(&a[k],&a[i]);
            f(a,i+1,n);
            swap(&a[k],&a[i]);
        }
    }
}
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void quickSort(int *number, int first, int last)
{
    int i, j, pivot;
    int temp;
    if (first<last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i<j)
        {
            while (number[i] <= number[pivot] && i<last)
                i++;
            while (number[j]>number[pivot])
                j--;
            if (i<j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quickSort(number, first, j - 1);
        quickSort(number, j + 1, last);
    }
}
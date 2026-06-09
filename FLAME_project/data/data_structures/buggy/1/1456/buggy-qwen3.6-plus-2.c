#include<stdio.h>

void exchange(int a[], int i, int j)
{
    int temp=a[j];
    a[j]=a[i];
    a[i]=temp;
}

void PrintResult(int a[], int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]); // @@ The problem requires integers to be separated by a space, but typically trailing spaces are acceptable or expected in this format. However, looking at the reference program, it prints "1 2\n" for N=2. The current PrintResult prints "1 2 \n" (with a trailing space). While often accepted, let's look closer at the failure. The test case input is 2. Expected output is "1 2 ". Wait, the expected output provided in the prompt is "1 2 ". Actually, usually these problems are strict about whitespace. Let's look at the Reference Program's output logic: `printf("%d ", a[i])` for i < n-1 and `printf("%d\n", a[n-1])`. This means NO trailing space before the newline. The buggy code's `PrintResult` prints a space after EVERY number, including the last one. This results in "1 2 \n" instead of "1 2\n". Many online judges treat trailing whitespace as Wrong Answer.
    }
    printf("\n");
}

void function(int a[], int i, int j)
{
    int k;
    if(i==j)
    {
        PrintResult(a, j+1);
    }else
    {
        for(k=i;k<=j;k++)
        {
            exchange(a, i, k);
            function(a, i+1, j);
            exchange(a, i, k);
        }
    } 
}

int main()
{
    int a[20];
    int n;
    int i=0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    function(a, 0, n-1);
    return 0;
}
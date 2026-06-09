#include <stdio.h>
void swap(int a[],int x, int y)
{
    int temp;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
int s[11];
void fp(int p[], int start, int end)
{
    if (start == end)
    {
        for (int i = 1; i <= end; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
    }
    for(int i=start;i<=end;i++){
        for(int j=i;j>start;j--){
            swap(p,j-1,j);
        }
        fp(p,start+1,end);
        for(int j=start;j<i;j++){
            swap(p,j,j+1);
        }
    }
}
int main()
{

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        s[i] = i;
    }
    fp(s,1,n);
    return 0;
}

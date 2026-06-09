#include <stdio.h>
void permutation(int m,int n);
int a[11] = {0,1,2,3,4,5,6,7,8,9,10};

int main()
{
    int n;
    scanf("%d",&n);
    permutation(1,n);
    return 0;
}

void permutation(int m,int n){
    if (m==n)
    {
        for (int i = 1; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d",a[n]);
        printf("\n");
    }  
    else for (int i = m; i <= n; i++)
    {
        int temp;
        temp = a[m]; @@
        a[m] = a[i]; @@
        a[i] = temp; //交换a[层数]与a[i],i从m到n @@

        permutation(m+1,n); @@

        temp = a[m];
        a[m] = a[i];
        a[i] = temp; //换回来
    }
}
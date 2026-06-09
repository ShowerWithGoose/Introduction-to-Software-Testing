#include <stdio.h>

int tem[15] ={0},fl;

void xuan(int *dest,int *p,int n)
{
    int i = 0,j = 0;

    for(i = 0;i <= 10;i++){
        if(p[i] != n)
            dest[j++] = p[i];
    }

    return;
}
void fun(int *now,int n)
{
    int i = 0;

    for(i = 1;i <= n;i++){
        int a[12] ={0};
        xuan(a,now,now[i]);
        tem[fl - n] = now[i];
        fun(a,n-1);
    }
    if(n == 1){
        for(i = 1;i < fl;i++)
            printf("%d ",tem[i]);
        printf("\n");
    }

    return ;
}

int main()
{
    int num[13] = {0};
    int i,n;

    scanf("%d",&n);
    for(i = 1;i <= n;i++)
        num[i] = i;
    fl = n +1;
    fun(num,n);

    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ans[15] = {},flag[15] = {},length = 0;
int cnn(int);
int main()
{
    #ifdef ACU
    freopen("in.txt","r",stdin);
    #endif
    int n1;
    scanf("%d", &n1);
    length = n1;
    cnn(n1);
    return 0;
}

int cnn(int n)
{
    if(n == 0)
    {
        for(int j = 0; j < length; ++j)
            printf("%d ", ans[j]);
        putchar('\n');
        return 0;
    }
    int i = 1;
    for(;i<=length;++i)
        if(flag[i] == 0)
            {
                flag[i] = 1;
                ans[length-n] = i;
                cnn(n-1);
                flag[i] = 0;
            }
    return 0;
}

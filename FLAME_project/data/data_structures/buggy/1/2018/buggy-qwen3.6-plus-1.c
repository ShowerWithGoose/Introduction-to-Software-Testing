#include <stdio.h>
void change1(int s[],int a,int b)
{
    int i;
    int z=s[a];
    for(i=a;i<b;i++)
    {
        s[i]=s[i+1];
    }
    s[b]=z;
}
void change2(int s[],int a,int b)
{
    int i;
    int z=s[b];
    for(i=b;i>a;i--)
    {
        s[i]=s[i-1];
    }
    s[a]=z;
}
void pai(int s[],int a,int b)
{
    if(a==b)
    {
        int k;
        for(k=0;k<a;k++) // @@ The loop condition `k<a` prints only `a` elements (indices 0 to a-1). Since `a==b==N`, it misses the last element at index `N-1`. It should be `k<=a` or `k<b` if `b` is exclusive, but here `b` is inclusive size. Actually, if `a==b` and `b` is the count `n`, indices are 0 to `n-1`. So it should print `n` numbers. The loop runs `a` times. If `a=n`, it prints indices 0 to `n-1`? No, `k<a` means 0 to `a-1`. If `a=n`, it prints 0 to `n-1`. Wait. Let's trace N=2. `pai(s, 0, 2)`. `a!=b`. Loop `l=0` to `1`. `change2(s, 0, 0)` (no op). `pai(s, 1, 2)`. `a!=b`. Loop `l=1` to `1`. `change2(s, 1, 1)` (no op). `pai(s, 2, 2)`. `a==b`. Loop `k=0` to `1` (`k<2`). Prints `s[0]`, `s[1]`. This seems correct for N=2? 
        // Let's re-read the expected output format: "1 2 ". Note the space after 2.
        // The buggy output is "12". The reference program prints "%d ".
        // The current code prints "%d" without spaces.
        printf("%d",s[k]); // @@ Missing space separator between numbers. Should be `printf("%d ", s[k]);` to match expected output format "1 2 ".
        }
        printf("\n");
    }
    else
    {
        int l;
        for(l=a;l<b;l++)
        {
            change2(s,a,l);
            pai(s,a+1,b);
            change1(s,a,l);
        }
    }
}
int main()
{
    int s[10];
    int n;
    scanf("%d",&n);
    int g;
    for(g=0;g<n;g++)
    {
        s[g]=g+1;
    }
    pai(s,0,n);
    return 0;
}
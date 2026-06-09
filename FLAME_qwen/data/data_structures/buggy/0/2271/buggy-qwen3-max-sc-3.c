#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. Also, in many modern compilers/environments, 'gets' is removed entirely, leading to a compilation error.]
    n = strlen(a);
    for (int i = 0;i <= n;i++) // @@ [Loop runs to i == n, which accesses a[n] (null terminator) and a[n+1] (out-of-bounds) when a[i]=='-' at i==n. This causes undefined behavior and potential crash. Should be i < n.]
    {
        if(a[i]=='-')
        {
            if(a[i-1] < a[i+1]) // @@ [When i==0, a[i-1] is a[-1] → out-of-bounds access. Similarly, when i==n-1, a[i+1] is a[n] (null terminator), which may be less than a[i-1], but also risks invalid comparison. No bounds check before accessing i-1 or i+1.]
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [Logic error: conditions like 'a[i-1]>='a' && a[i+1]<='z'' do not ensure both are lowercase; e.g., a[i-1]='z', a[i+1]='a' would pass first part incorrectly. Also, 'a[i-1]>=0' compares char to int 0 (ASCII NUL), not '0'; should be 'a[i-1]>='0''.]
                {
                    for(c=a[i-1]+1;c<a[i+1];c++)
                    {
                        b[k++]=c;
                    }
                }
                else b[k++]=a[i];
            }
            else b[k++]=a[i];
        }
        else b[k++]=a[i];
    }
    puts(b);
    return 0;
}
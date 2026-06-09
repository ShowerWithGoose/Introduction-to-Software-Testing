#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    n = strlen(a);
    for (int i = 0;i <= n;i++) // @@ [Loop runs to i == n, which accesses a[n] (null terminator), leading to out-of-bounds access when checking a[i+1]]
    {
        if(a[i]=='-')
        {
            if(a[i-1] < a[i+1]) // @@ [When i == 0, a[i-1] is a[-1] (invalid); when i == n, a[i+1] is beyond null terminator (undefined behavior)]
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [Incorrect range checks: e.g., 'a[i-1]>='a' && a[i+1]<='z'' doesn't ensure both are lowercase; also '0' vs 0 typo in digit check]
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
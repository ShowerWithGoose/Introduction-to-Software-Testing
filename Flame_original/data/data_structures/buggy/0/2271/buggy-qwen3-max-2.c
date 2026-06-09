#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    n = strlen(a);
    for (int i = 0;i <= n;i++) // @@ [Loop runs to i == n, which accesses a[n] (null terminator), but then checks a[i+1] leading to out-of-bounds read when i == n]
    {
        if(a[i]=='-')
        {
            if(a[i-1] < a[i+1]) // @@ [When i == 0, a[i-1] is a[-1] → undefined behavior; also when i == n, a[i+1] is beyond string end]
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [Logic error: conditions mix lower/upper/digit ranges incorrectly; e.g., 'a' <= a[i-1] not checked, and digits compared against integer 0/9 instead of '0'/'9']
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
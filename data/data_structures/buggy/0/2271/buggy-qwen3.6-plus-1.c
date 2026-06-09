#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a);
    n = strlen(a);
    for (int i = 0;i <= n;i++) // @@ Loop condition should be i < n to prevent out-of-bounds access when checking a[i+1] and to avoid processing the null terminator.
    {
        if(a[i]=='-')
        {
            if(a[i-1] < a[i+1]) // @@ Missing boundary check for i == 0 or i == n - 1, which causes undefined behavior due to out-of-bounds array access at a[-1] or a[n].
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ Incorrect logic for checking same character type; fails to verify both characters are within the same range, and incorrectly uses integer 0 and 9 instead of character literals '0' and '9'.
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
    puts(b); // @@ Array b is not explicitly null-terminated before printing, which may cause undefined behavior or garbage output.
    return 0;
}
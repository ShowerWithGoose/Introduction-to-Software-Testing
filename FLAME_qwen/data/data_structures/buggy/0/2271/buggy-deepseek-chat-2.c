#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a);
    n = strlen(a);
    for (int i = 0;i <= n;i++) // @@ Error: Loop condition should be i < n, not i <= n, to avoid accessing out-of-bounds when i = n (a[n] is '\0').
    {
        if(a[i]=='-')
        {
            if(a[i-1] < a[i+1]) // @@ Error: When i = 0, a[i-1] accesses a[-1] which is out-of-bounds. Also, when i = n-1, a[i+1] accesses a[n] which is the null terminator, but the loop goes to i <= n, so i+1 could be out-of-bounds.
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ Error: The condition (a[i-1]>=0&&a[i+1]<=9) is incorrect for digit check; should be (a[i-1]>='0'&&a[i+1]<='9'). Also, the logic does not ensure both characters are of the same type (e.g., a-R would incorrectly expand).
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
    puts(b); // @@ Error: b is not null-terminated, which may cause undefined behavior when printing.
    return 0;
}
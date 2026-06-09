#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a);
    n = strlen(a);
    for (int i = 0;i <= n;i++) // @@ Loop condition should be i < n to avoid out-of-bounds access when i=0 or i=n.
    {
        if(a[i]=='-')
        {
            // @@ Missing checks for dash at start (i==0) or end (i==n-1) which cause undefined behavior (accessing a[-1] or a[i+1] out of bounds).
            if(a[i-1] < a[i+1])
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ Incorrect type check: uses OR instead of AND, digit range uses integer 0 and 9 instead of '0' and '9', and does not validate both ends of the range.
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
#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a); // @@ [Use of unsafe and deprecated function 'gets' which may cause buffer overflow; also, in many modern compilers/environments, 'gets' is removed entirely, leading to compilation error]
    n = strlen(a);
    for (int i = 0;i <= n;i++) // @@ [Loop runs to i == n, which accesses a[n] (null terminator), and when i == n and a[i]=='-', it will access a[n+1] (out-of-bounds) and a[n-1]; also, when i==0 and a[i]=='-', it accesses a[-1] (invalid)]
    {
        if(a[i]=='-')
        {
            if(a[i-1] < a[i+1]) // @@ [Accesses a[i-1] when i could be 0, leading to out-of-bounds read (undefined behavior); similarly, accesses a[i+1] when i could be n (end of string), also out-of-bounds]
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [Incorrect condition: e.g., 'a[i-1]>='a' && a[i+1]<='z'' does not ensure both are lowercase; also, 'a[i-1]>=0' compares char to integer 0, should be 'a[i-1]>='0''; same for upper bound]
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
    puts(b); // @@ [b is not null-terminated, so puts may print garbage beyond intended output]
    return 0;
}
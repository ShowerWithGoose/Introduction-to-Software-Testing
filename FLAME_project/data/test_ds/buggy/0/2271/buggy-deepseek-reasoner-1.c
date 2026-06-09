#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a);
    n = strlen(a);
    for (int i = 0;i <= n;i++)
    {
        if(a[i]=='-')
        {
            if(a[i-1] < a[i+1])
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ The condition for digits is incorrect. It compares characters to integers 0 and 9 instead of '0' and '9', so digit expansion never occurs. Also, it does not ensure both characters are in the same category (digits). Should be: (a[i-1]>='0' && a[i+1]<='9') and also check both are digits.
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
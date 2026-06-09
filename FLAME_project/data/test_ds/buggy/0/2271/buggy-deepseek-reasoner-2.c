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
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [The condition for digits is incorrect; should be a[i-1]>='0' and a[i+1]<='9'. Also the digit part uses a[i-1]>=0 which is always true, and a[i+1]<=9 which compares ASCII value incorrectly. Moreover, the conditions for letters do not ensure both sides are within the same valid range. These errors cause the expansion to be skipped, e.g., for "0-8".]
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
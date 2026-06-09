#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a);
    n = strlen(a);
    for (int i = 0;i <= n;i++) // @@ [Loop bound should be i < n to avoid accessing out-of-bounds elements (a[n] is null terminator, and a[i+1] when i=n is out of bounds). Additionally, when i=0, a[i-1] is invalid.]
    {
        if(a[i]=='-')
        {
            if(a[i-1] < a[i+1])
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [Digit condition is incorrect: should be (a[i-1]>='0' && a[i+1]<='9') to correctly identify digits. Also, alphabetic conditions should check both ends are within the same range.]
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
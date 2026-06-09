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
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [The condition for digits is incorrect. It checks ASCII values >= 0 and <= 9, which corresponds to non-printable control characters, not digit characters '0'-'9'. It should be (a[i-1]>='0' && a[i+1]<='9'). Additionally, it fails to check if the characters on both sides are of the same type (e.g., it might allow mixing letters and digits if the ASCII values happen to fall in range, though the primary error here is the digit check logic).]
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
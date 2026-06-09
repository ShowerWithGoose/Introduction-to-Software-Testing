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
            if(a[i-1] < a[i+1]) // @@ Out-of-bounds array access when i=0 or i=n-1; missing boundary check for the expansion symbol position.
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ Incorrect range validation: fails to ensure both characters are within the same type range, and >=0/<=9 checks ASCII control codes instead of digit characters '0'-'9'.
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
    puts(b); // @@ Array b lacks explicit null-termination, which may cause undefined behavior or print garbage characters.
    return 0;
}
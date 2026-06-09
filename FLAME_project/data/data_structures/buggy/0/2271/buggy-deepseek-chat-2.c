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
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [Error: The condition for digits is incorrect. It should check if both characters are digits using '0' and '9' character literals, not integer 0 and 9. Also, the logic for ranges is flawed; it should ensure both characters are within the same valid range, e.g., (a[i-1]>='a' && a[i+1]<='z') should be (a[i-1]>='a' && a[i+1]<='z' && a[i-1]<='z' && a[i+1]>='a') to properly check both ends. The current condition allows invalid combinations like 'a' and 'z' but also 'a' and '9' because the digit check uses integer 0 and 9 instead of '0' and '9'.]
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
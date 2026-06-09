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
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ The conditions for checking same type are incorrect. For digits, it should be (a[i-1]>='0' && a[i-1]<='9' && a[i+1]>='0' && a[i+1]<='9'). The current condition a[i-1]>=0 is always true and a[i+1]<=9 is never true for digit characters (since '8' is 56). Similarly, the lowercase and uppercase conditions miss checking both ends of the range (e.g., they do not require the right character to be >= the lower bound).
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
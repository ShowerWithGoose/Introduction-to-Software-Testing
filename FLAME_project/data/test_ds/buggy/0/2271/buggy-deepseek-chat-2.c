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
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [Error: The condition for digits is incorrect. It should check if both characters are digits using '0' and '9' character literals, not integer 0 and 9. Also, the condition should ensure both characters are within the same range, e.g., (a[i-1]>='0' && a[i+1]<='9'). Additionally, the condition for letters incorrectly uses '&&' between different ranges; it should check that both characters are in the same range, e.g., (a[i-1]>='a' && a[i+1]<='z') should be (a[i-1]>='a' && a[i+1]<='z' && a[i-1]<='z' && a[i+1]>='a') but the original logic is flawed because it doesn't ensure both are letters; it only checks one side. The correct approach is to check if both are lowercase, both uppercase, or both digits.]
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
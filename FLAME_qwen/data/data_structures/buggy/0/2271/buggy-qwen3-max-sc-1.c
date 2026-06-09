#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0;
    char a[1000],b[1000],c;
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in some environments, 'gets' is not available, leading to compilation error.]
    n = strlen(a);
    for (int i = 0;i <= n;i++) // @@ [Loop runs to i == n, which accesses a[n] (null terminator). This may lead to reading beyond intended input when checking a[i+1] at i == n-1 or i == n. Specifically, when i == n, a[i] is '\0', and a[i+1] is out-of-bounds. Also, when i == 0 and a[0]=='-', a[i-1] accesses a[-1] → undefined behavior.]
    {
        if(a[i]=='-')
        {
            if(a[i-1] < a[i+1]) // @@ [No bounds check for i-1 and i+1; when i==0, i-1 is -1 (invalid), and when i==n-1, i+1 is n (valid only if n < array size, but a[n] is '\0'). Accessing a[-1] or comparing with '\0' can cause incorrect logic or crash.]
            {
                if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>=0&&a[i+1]<=9)) // @@ [Logic error: conditions are malformed. Should check both ends belong to same category, e.g., (a[i-1]>='a' && a[i-1]<='z' && a[i+1]>='a' && a[i+1]<='z'). Current condition allows mixed types like 'a' and 'Z'. Also, (a[i-1]>=0 && a[i+1]<=9) compares ASCII values: '0' is 48, so this condition is always true for printable chars since all are >0, and <=9 is false for digits (which are >=48). Should be (a[i-1]>='0' && a[i+1]<='9' && ...).]
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
    puts(b); // @@ [b is not null-terminated. If the last character processed is not '\0', puts may print garbage. Need b[k]='\0'; before puts.]
    return 0;
}
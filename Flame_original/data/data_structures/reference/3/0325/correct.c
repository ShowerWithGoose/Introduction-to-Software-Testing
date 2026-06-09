#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char num[100];
    fgets(num, 99, stdin);
    int s=0, n=0, length=strlen(num);
    for (int i=0; i<length-1; i++)
    {
        if (num[i]=='0')
            continue;
        if (num[i]!='0'&&num[i]!='.')
        {
            if (n!=0)
                continue;
            n=i+1;
            if (num[0]=='0')
                n=i-1;
        }
        if (num[i]=='.')
            s=i-1;
    }
    if (num[0]=='0')
    {
        if (n+2>=length-1)
            printf("%c", num[n+1]);
        else
            printf("%c.", num[n+1]);
        for (int i=n+2; i<length-1; i++)
        {
            printf("%c", num[i]);
        }
        printf("e-%d", abs(n-s));
    }
    if (num[0]!='0')
    {
        printf("%c.", num[n-1]);
        for (int i=n; i<length-1; i++)
        {
            if (num[i]=='.')
                continue;
            printf("%c",num[i]);
        }
        printf("e%d", abs(n-s-1));
    }
    return 0;
}


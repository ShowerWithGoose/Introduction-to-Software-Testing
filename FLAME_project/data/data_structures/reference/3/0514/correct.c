#include <stdio.h>


int main()
{
    char a[103];
    scanf("%s", a);
    int len = strlen(a);
    int c;
    int i, j, k;

    if (a[0]=='0')
    {
        for(i=2; i<len; i++)
        {
            if (a[i]!='0')
            {
                c = i-1;
                break;
            }
        }
        for(j=len-1; j>i; j--)
        {
            if (a[j]!='0')
            {
                break;
            }
        }
        if(i==j)
        {
            printf("%c", a[i]);
            printf("e-%d", c);
        }
        else
        {
            printf("%c.", a[i]);
            for(k=i+1; k<=j; k++)
            {
                printf("%c", a[k]);
            }
            printf("e-%d", c);
        }

    }

    if(a[0]!='0')
    {
        c = len - 1;
        for(i=1; i<len; i++)
        {
            if(a[i]=='.')
            {
                c = i-1;
                break;
            }
        }
        for(j=len-1; j>0; j--)
        {
            if((a[j]!='0')&&(a[j]!='.'))
            {
                break;
            }
        }
        if (j==1)
        {
            printf("%c", a[0]);
            printf("e%d", c);
        }
        else
        {
            printf("%c.", a[0]);
            if(j>i)
            {
                for(k=1; k<i; k++)
                {
                    printf("%c", a[k]);
                }
                for(k=i+1; k<=j; k++)
                {
                    printf("%c", a[k]);
                }
            }
            else
            {
                for(k=1; k<=j; k++)
                {
                    printf("%c", a[k]);
                }
            }
            printf("e%d", c);
        }
    }

    return 0;
}


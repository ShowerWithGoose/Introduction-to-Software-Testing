#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,t,move;
    char a[200];
    scanf("%s",a);
    int len=strlen(a);
    for ( i = 0; i <len-1; i++)
    {
        if (a[i]=='.')
        {
            k=i;
            break;
        }
    }
    if (k==1)
    {
        if (a[0]=='0')
        {
            for ( i = 2; i <=len-1; i++)
            {
                if (a[i]!='0')
                {
                    t=i;
                    break;
                }
                
            }
            move=t-1;
            a[0]=a[t];
            if (t==(len-1))
            {
                printf("%ce-%d",a[0],move);
                return 0;
            }
            else
            {
            for ( i = 2; i <= len-1; i++)
            {
                a[i]=a[i+move];
            }
            
            printf("%se-%d",a,move);
            return 0;
            }
        }
        if (a[0]!='0')
        {
            printf("%se0",a);
            return 0;
        }
    }
    if (k!=1)
    {
        j=k-1;
        for ( i = len-1; i >1; i--)
        {
            if (i<=k)
            {
                a[i]=a[i-1];
            }
            else if (i>k)
            {
                a[i]=a[i];
            }
        }
        a[1]='.';
        printf("%se%d",a,j);
        return 0;
    }
    
    
    return 0;
}

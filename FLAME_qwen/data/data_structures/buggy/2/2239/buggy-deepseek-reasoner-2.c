#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int a[20];
char b[20];
int c[20];

int main()
{
    int i=0;
    char d;
    while (scanf("%d",&a[i])!=EOF) // @@ Input termination condition is wrong; expression ends with '=', not EOF, causing infinite loop.
    {
        scanf("%c",&d);
        while (d==' ')
        {
            scanf("%c",&d);
        }
        b[i]=d;
        c[i]=1;
        i+=1;
    }
    int s=0;
    for (int j=0;j<i;j++)
    {
        printf("%c %d\n",b[j],a[j]); // @@ Debug output not allowed; produces extra lines that fail output specification.
    }
    
    for (int j=0;j<i;j++)
    {
        if ((b[j]=='*')||(b[j]=='/'))
        {
            s+=1;
        }
        
    }
    int y=i-1-s;
    if (s!=0)
    {
        for (int j=0;j<i;j++) // @@ Loop processes all operators including '=', which should not be processed.
        {
            if (b[j]=='*')
            {
                int r=j;
                while (c[r]!=1) // @@ May decrement r below 0 if no left operand with c==1, causing out-of-bounds.
                {
                    r--;
                }
                a[r]=a[r]*a[j+1]; // @@ Potential out-of-bounds access when j is the last valid operator index.
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1) // @@ Same out-of-bounds risk as above.
                {
                    r--;
                }
                a[r]=a[r]/a[j+1]; // @@ Potential out-of-bounds access.
                c[j+1]=0;
            }
        }
    }
    if (y!=0)
    {
        for (int j=0;j<i;j++)
        {
            if (b[j]=='+')
            {
                int r=j;
                while (c[r]!=1) // @@ Same out-of-bounds risk.
                {
                    r--;
                }
                while (c[j+1]!=1) // @@ Modifies loop variable j, causing incorrect iteration and potential out-of-bounds.
                {
                    j++;
                }
                a[r]=a[r]+a[j+1]; // @@ j may have been incremented beyond array bounds.
                c[j+1]=0;
            }
            else if (b[j]=='-')
            {
                int r=j;
                while (c[r]!=1) // @@ Same out-of-bounds risk.
                {
                    r--;
                }
                while (c[j+1]!=1) // @@ Same loop variable modification issue.
                {
                    j++;
                }
                a[r]=a[r]-a[j+1]; // @@ Potential out-of-bounds access.
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]);
    return 0;
    
}
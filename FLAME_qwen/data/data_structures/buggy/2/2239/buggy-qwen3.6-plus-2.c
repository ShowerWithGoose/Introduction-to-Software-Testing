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
    while (scanf("%d",&a[i])!=EOF) // @@ Incorrect loop termination condition. scanf("%d") returns 0 when encountering '=', which is != EOF, causing an infinite loop. The loop should terminate when '=' is read.
    {
        scanf("%c",&d);
        while (d==' ')
        {
            scanf("%c",&d);
        }
        b[i]=d; // @@ Missing termination check. Should break the loop here if d == '=', otherwise it continues and causes parsing errors or infinite loops.
        c[i]=1;
        i+=1;
    }
    int s=0;
    for (int j=0;j<i;j++)
    {
        printf("%c %d\n",b[j],a[j]);
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
        for (int j=0;j<i;j++)
        {
            if (b[j]=='*')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]*a[j+1];
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]/a[j+1];
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
                while (c[r]!=1)
                {
                    r--;
                }
                while (c[j+1]!=1) // @@ Modifying the loop control variable 'j' inside the loop body leads to skipping iterations and potential out-of-bounds array access.
                {
                    j++;
                }
                a[r]=a[r]+a[j+1];
                c[j+1]=0;
            }
            else if (b[j]=='-')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                while (c[j+1]!=1) // @@ Modifying the loop control variable 'j' inside the loop body leads to skipping iterations and potential out-of-bounds array access.
                {
                    j++;
                }
                a[r]=a[r]-a[j+1];
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]);
    return 0;
    
}
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
    while (scanf("%d",&a[i])!=EOF)
    {
        scanf("%c",&d);
        while (d==' ')
        {
            scanf("%c",&d);
        }
        b[i]=d;
        c[i]=1;
        i+=1;
    } // @@ [The loop condition `scanf("%d",&a[i])!=EOF` does not stop at '='. It will fail to parse non-integer input like '=', causing undefined behavior or infinite loop. The problem requires stopping when '=' is encountered, but this code tries to read an integer even when the next token is '='.]

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
                a[r]=a[r]*a[j+1]; // @@ [If j+1 >= i, this accesses out-of-bounds array element a[j+1]. Since b[i-1] is likely '=', and operators are stored per number, the indexing logic is flawed.]
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]/a[j+1]; // @@ [Same as above: potential out-of-bounds access when j+1 >= i. Also, division by zero not handled, though problem states expression is valid.]
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
                while (c[j+1]!=1)
                {
                    j++;
                }
                a[r]=a[r]+a[j+1]; // @@ [Again, j+1 may be out of bounds. Additionally, modifying loop variable `j` inside the loop causes skipped iterations and logic errors.]
                c[j+1]=0;
            }
            else if (b[j]=='-')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                while (c[j+1]!=1)
                {
                    j++;
                }
                a[r]=a[r]-a[j+1]; // @@ [Same issues: out-of-bounds access and unsafe modification of loop counter `j`.]
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]);
    return 0;
    
}
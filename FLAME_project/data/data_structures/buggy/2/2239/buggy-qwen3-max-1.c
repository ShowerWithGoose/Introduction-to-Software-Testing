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
    } // @@ [The loop condition `scanf("%d", ...) != EOF` does not stop at '=', so it reads past the '=' and causes undefined behavior. Also, '=' is never checked to terminate input.]

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
                a[r]=a[r]/a[j+1]; // @@ [Integer division is correct per problem, but this assumes a[j+1] is always valid; however, due to incorrect input parsing (reading past '='), a[j+1] may be garbage.]
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
                while (c[j+1]!=1)
                {
                    j++;
                }
                a[r]=a[r]-a[j+1]; // @@ [Same issue: a[j+1] may be invalid due to reading beyond '='. Also, the logic for handling operator precedence and operand grouping is flawed because it doesn't correctly track which numbers are still active after * and / processing.]
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]); // @@ [Assumes result is always in a[0], but due to incorrect parsing and processing logic, a[0] may not hold the final result. For input "10 + 20 * 30 - 40 / 5 =", expected is 602, but program likely uses uninitialized/garbage values.]
    return 0;
    
}
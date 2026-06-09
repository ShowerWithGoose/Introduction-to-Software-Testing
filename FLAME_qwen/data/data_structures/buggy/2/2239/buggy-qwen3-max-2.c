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
    while (scanf("%d",&a[i])!=EOF) // @@ [The loop condition does not check for the '=' terminator; it will keep reading until EOF, but the problem specifies input ends with '=', causing infinite loop or incorrect parsing]
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
        printf("%c %d\n",b[j],a[j]); // @@ [Debug print left in final code; not required by problem and may interfere with output format]
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
                a[r]=a[r]*a[j+1]; // @@ [Accesses a[j+1] which may be out of valid range if j is last index; also logic fails to handle operator precedence correctly across full expression]
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]/a[j+1]; // @@ [Same issue: potential out-of-bounds access and flawed evaluation order]
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
                    j++; // @@ [Modifying loop variable 'j' inside loop leads to skipped iterations and undefined behavior]
                }
                a[r]=a[r]+a[j+1]; // @@ [Again, possible out-of-bounds access to a[j+1]]
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
                    j++; // @@ [Same critical error: modifying loop counter inside loop body]
                }
                a[r]=a[r]-a[j+1]; // @@ [Potential buffer overflow and incorrect operand selection]
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]);
    return 0;
    
}
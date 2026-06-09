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
    while (scanf("%d",&a[i])!=EOF) // @@ [The loop condition does not check for the '=' terminator; it only stops at EOF, but the problem specifies that input ends with '=', so this causes incorrect parsing and potential infinite loop or buffer overflow.]
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
        printf("%c %d\n",b[j],a[j]); // @@ [Debug print left in final code; not an error per se but indicates incomplete implementation. However, the real issue is logic below.]
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
                while (c[r]!=1) // @@ [This backward search assumes previous active element, but 'c' array tracks validity; however, initial setup sets all c[i]=1, so this may work initially, but logic fails when multiple operators are processed out of order.]
                {
                    r--;
                }
                a[r]=a[r]*a[j+1]; // @@ [Accesses a[j+1] without ensuring j+1 < i; if last operator is '*' and j = i-1, then j+1 is out of bounds. Also, '=' is stored in b[i-1], so a[i] was never read — leading to undefined behavior.]
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                a[r]=a[r]/a[j+1]; // @@ [Same out-of-bounds access as above; also, integer division is correct per spec, but operand may be uninitialized.]
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
                while (c[j+1]!=1) // @@ [This forward skip assumes next valid number, but if j+1 is beyond array or invalid, leads to infinite loop or out-of-bounds access. Also modifies loop variable 'j' inside loop, causing skipped iterations.]
                {
                    j++;
                }
                a[r]=a[r]+a[j+1]; // @@ [Again accesses a[j+1] which may be out of bounds; also, after incrementing j in inner loop, j+1 could exceed i-1.]
                c[j+1]=0;
            }
            else if (b[j]=='-')
            {
                int r=j;
                while (c[r]!=1)
                {
                    r--;
                }
                while (c[j+1]!=1) // @@ [Same issue: modifying loop index 'j' inside for-loop disrupts iteration logic and risks out-of-bounds access.]
                {
                    j++;
                }
                a[r]=a[r]-a[j+1]; // @@ [Out-of-bounds access likely; also, expression parsing doesn't respect operator precedence correctly due to sequential overwriting.]
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]);
    return 0;
    
}
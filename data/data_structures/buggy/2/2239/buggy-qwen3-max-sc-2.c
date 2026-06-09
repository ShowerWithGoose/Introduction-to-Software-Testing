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
    while (scanf("%d",&a[i])!=EOF) // @@ [The loop condition is incorrect. It should stop when '=' is encountered, but it continues until EOF, causing undefined behavior when reading past the '='. Also, it doesn't handle the '=' terminator as required by the problem.]
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
        printf("%c %d\n",b[j],a[j]); // @@ [Debug print statement that shouldn't be in final output; may cause mismatch with expected output format.]
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
                while (c[r]!=1) // @@ [This logic assumes previous active element is at r, but c[r] is always 1 initially and never updated correctly during multiplication/division passes, leading to wrong operand selection.]
                {
                    r--;
                }
                a[r]=a[r]*a[j+1];
                c[j+1]=0;
            }
            else if (b[j]=='/')
            {
                int r=j;
                while (c[r]!=1) // @@ [Same issue as above: incorrect tracking of active operands due to flawed use of c[] array.]
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
                while (c[r]!=1) // @@ [Again, c[r] logic is broken; this may access invalid or already-zeroed elements, leading to incorrect accumulation.]
                {
                    r--;
                }
                while (c[j+1]!=1) // @@ [This inner while modifies loop variable j, which interferes with the outer for-loop's increment, potentially skipping operators or causing out-of-bounds access.]
                {
                    j++;
                }
                a[r]=a[r]+a[j+1];
                c[j+1]=0;
            }
            else if (b[j]=='-')
            {
                int r=j;
                while (c[r]!=1) // @@ [Same flawed operand tracking.]
                {
                    r--;
                }
                while (c[j+1]!=1) // @@ [Modifying j inside the loop breaks iteration logic.]
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
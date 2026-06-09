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
    while (scanf("%d",&a[i])!=EOF) // @@ [Input loop does not stop when '=' is encountered; should break after reading '=' operator.]
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
    for (int j=0;j<i;j++) // @@ [This debug print loop outputs unnecessary information; should be removed.]
    {
        printf("%c %d\n",b[j],a[j]); // @@ [Debug output not required by the problem.]
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
                while (c[j+1]!=1) // @@ [This while loop modifies the loop variable j and can cause out-of-bounds access and skipped operators.]
                {
                    j++; // @@ [Modifying the loop variable inside the for loop is dangerous and may lead to incorrect behavior.]
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
                while (c[j+1]!=1) // @@ [Same issue as above: modifying loop variable and potential out-of-bounds.]
                {
                    j++; // @@ [Modifying j inside the for loop can cause skipping operators or index out of bounds.]
                }
                a[r]=a[r]-a[j+1];
                c[j+1]=0;
            }
        }
        
    }
    printf("%d",a[0]);
    return 0;
    
}
#include<stdio.h>
int x[100][2],y[100][2],z[10000][2],ans[10000][2];
void bubble(int n)
{
    int i,j,hold[2],flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(z[j][1]<z[j+1][1])
            {
                hold[0]=z[j][0];
                z[j][0]=z[j+1][0];
                z[j+1][0]=hold[0];
                hold[1]=z[j][1];
                z[j][1]=z[j+1][1];
                z[j+1][1]=hold[1];
                flag=1;
            }
        }
        if (0==flag)
            break;
    }
}

int main()
{
    int i,j=0,k=0,l=0,countx,county;
    char c;
    scanf("%d %d",&x[0][0],&x[0][1]);
    scanf("%c",&c);
    for(i=1;c!='\n';i++) // @@ [The loop condition checks c before it's updated in the loop body for the first iteration; also, after reading the last term of the first polynomial, the next scanf may fail or read unexpected input, leading to undefined behavior. Additionally, 'i' is used uninitialized if the first input line is empty.]
    {
        scanf("%d %d",&x[i][0],&x[i][1]);
        scanf("%c",&c);
    }
    countx=i;
    while(scanf("%d%d",&y[j][0],&y[j][1])!=EOF) // @@ [This loop will not terminate correctly because after the first polynomial input ends with '\n', the second polynomial input starts immediately; however, if the input is provided as two separate lines, the newline from the first line might interfere, and EOF may never be reached if input is from a terminal or file without proper EOF signal. Also, this assumes that the second polynomial occupies the rest of the input until EOF, which may not match the problem's input format specification.]
    {
        j++;
    }
    county=j;
    for(i=0;i<countx;i++)
    {
        for(j=0;j<county;j++)
        {
            z[k][0]=x[i][0]*y[j][0];
            z[k][1]=x[i][1]+y[j][1];
            k++;
        }
    }
    bubble(k);
    for(i=0;i<k;i++) // @@ [Accesses z[i+1] when i == k-1, which is out-of-bounds (undefined behavior).]
    {
        if(z[i+1][1]!=z[i][1])
        {
            ans[l][0]=z[i][0];
            ans[l][1]=z[i][1];
            l++;
        }
        else
        {
            ans[l][1]=z[i][1];
            for(j=i;z[j][1]==z[i][1];j++) // @@ [This loop may run past the end of array z if all remaining terms have the same exponent, causing out-of-bounds access.]
                ans[l][0]+=z[j][0];
            i=j; // @@ [After the inner loop, 'j' points to the first index where exponent differs or beyond; assigning i=j skips necessary bounds checks and may cause the outer loop to skip terms or go out of bounds. Also, ans[l][0] was never initialized to zero before accumulation, leading to garbage values.]
            l++;
        }
    }
    for(i=0;i<l;i++)
        printf("%d %d ",ans[i][0],ans[i][1]); // @@ [If any coefficient becomes zero after combining like terms, it should not be printed per problem requirements, but this code prints all terms regardless of coefficient value.]
    return 0;
}
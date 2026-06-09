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
    for(i=1;c!='\n';i++) // @@ [The loop condition checks c before it's updated in the loop body for the first iteration; also, if the first line has only one term, the loop may not run at all, leading to incorrect countx. Additionally, if input ends without newline (e.g., EOF), this causes undefined behavior.]
    {
        scanf("%d %d",&x[i][0],&x[i][1]);
        scanf("%c",&c);
    }
    countx=i;
    while(scanf("%d%d",&y[j][0],&y[j][1])!=EOF)
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
    for(i=0;i<k;i++) // @@ [Accesses z[i+1] when i == k-1, which is out of bounds (undefined behavior).]
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
            for(j=i;z[j][1]==z[i][1];j++) // @@ [If all remaining terms have same exponent, j will go beyond array bounds (no guard against j >= k).]
                ans[l][0]+=z[j][0];
            i=j; // @@ [After inner loop, j points to first index with different exponent or beyond; but then i=j skips next term incorrectly because outer loop increments i again. Also, ans[l][0] is used uninitialized if entering else branch.]
            l++;
        }
    }
    for(i=0;i<l;i++)
        printf("%d %d ",ans[i][0],ans[i][1]); // @@ [Does not skip zero-coefficient terms as required by problem statement.]
    return 0;
}
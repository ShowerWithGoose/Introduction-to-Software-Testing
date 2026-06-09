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
    for(i=1;c!='\n';i++) // @@ [The loop condition checks c before it's updated in the loop body for the first iteration; also, if input has only one term, this loop never runs but countx becomes 1 which is correct, but logic is fragile. However, the real critical error is below.]
    {
        scanf("%d %d",&x[i][0],&x[i][1]);
        scanf("%c",&c);
    }
    countx=i;
    while(scanf("%d%d",&y[j][0],&y[j][1])!=EOF) // @@ [This loop will not terminate correctly because after reading the last pair of the second polynomial, the next scanf fails (returns EOF), but j is still incremented once too many. Also, standard input may not signal EOF properly in all environments, leading to infinite loop or incorrect county.]
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
    for(i=0;i<k;i++) // @@ [In the else block, 'i=j' causes skipping of terms and potential out-of-bounds access when z[j][1] is accessed beyond array bounds. Also, ans[l][0] is used uninitialized in the else block when accumulating coefficients.]
    {
        if(z[i+1][1]!=z[i][1]) // @@ [Accesses z[i+1] when i == k-1, which is out of bounds (undefined behavior).]
        {
            ans[l][0]=z[i][0];
            ans[l][1]=z[i][1];
            l++;
        }
        else
        {
            ans[l][1]=z[i][1];
            for(j=i;z[j][1]==z[i][1];j++) // @@ [No bound check on j; if all remaining terms have same exponent, j can exceed k, causing buffer overflow. Also, ans[l][0] is not initialized before +=, leading to garbage values.]
                ans[l][0]+=z[j][0];
            i=j; // @@ [After loop, j points to first index with different exponent, but then i=j causes the outer for-loop to skip necessary indices or go out of bounds.]
            l++;
        }
    }
    for(i=0;i<l;i++)
        printf("%d %d ",ans[i][0],ans[i][1]); // @@ [If any coefficient becomes zero after combining like terms, it should not be printed, but this code prints all terms regardless.]
    return 0;
}
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
    for(i=1;c!='\n';i++) // @@ [The loop condition checks `c != '\n'` before reading the next pair, but if the first polynomial has only one term, the loop never runs and `countx` becomes 1 correctly. However, if there are multiple terms, after reading the last term, `scanf("%c", &c)` reads the newline, but the loop increments `i` one extra time because the condition is checked at the start of the loop body. This causes `countx` to be one more than the actual number of terms.]
    {
        scanf("%d %d",&x[i][0],&x[i][1]);
        scanf("%c",&c);
    }
    countx=i;
    while(scanf("%d%d",&y[j][0],&y[j][1])!=EOF) // @@ [This loop relies on EOF to terminate, but standard input may not send EOF unless explicitly signaled (e.g., Ctrl+D). In many test environments, especially with redirected input, this works, but if the second polynomial line ends with a newline and no EOF, this may hang or behave incorrectly. However, the bigger issue is that it doesn't check for newline like the first polynomial, leading to inconsistent input handling. But the primary bug is in the first polynomial reading logic.]
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
    for(i=0;i<k;i++) // @@ [When accessing `z[i+1]`, if `i == k-1`, this reads out-of-bounds (`z[k]`), which is undefined behavior. This can cause crashes or incorrect results.]
    {
        if(z[i+1][1]!=z[i][1]) // @@ [Same as above: accesses `z[i+1]` when `i` can be `k-1`.]
        {
            ans[l][0]=z[i][0];
            ans[l][1]=z[i][1];
            l++;
        }
        else
        {
            ans[l][1]=z[i][1];
            for(j=i;z[j][1]==z[i][1];j++) // @@ [This loop does not guard against `j` exceeding `k-1`. If the last group of terms extends to the end of `z`, `z[j]` will eventually access beyond valid indices, causing undefined behavior.]
                ans[l][0]+=z[j][0];
            i=j; // @@ [After the inner loop, `j` points to the first index where exponent differs (or beyond). Assigning `i = j` skips terms, but note that the outer `for` loop will then do `i++`, so it should be `i = j - 1` to compensate. As written, it skips one extra term. Also, `ans[l][0]` is used uninitialized in the `else` block, leading to garbage values being added to.]
            l++;
        }
    }
    for(i=0;i<l;i++)
        printf("%d %d ",ans[i][0],ans[i][1]); // @@ [`ans[i][0]` may contain garbage due to uninitialized use in the `else` block, and zero-coefficient terms are not filtered out, which violates the problem requirement to output only non-zero terms.]
    return 0;
}
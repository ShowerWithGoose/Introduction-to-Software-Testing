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
    for(i=1;c!='\n';i++) // @@ [The loop condition checks `c != '\n'` before reading the next term, but `c` is only updated inside the loop. If the first line has only one term, the loop never runs, and `countx = i = 1` is correct. However, if there are multiple terms, after reading the last term, `scanf("%c", &c)` reads the newline, but then `i` is incremented one extra time before checking the condition, leading to `countx` being one more than the actual number of terms.]
    {
        scanf("%d %d",&x[i][0],&x[i][1]);
        scanf("%c",&c);
    }
    countx=i;
    while(scanf("%d%d",&y[j][0],&y[j][1])!=EOF) // @@ [This loop assumes that the second polynomial input ends with EOF, but the problem states that both polynomials are provided as separate lines ending with newline. On many systems, especially when input is given interactively or via file without explicit EOF, this may hang or behave incorrectly. More critically, if the input is from a file with two lines, the second line ends with '\n', not EOF, so `scanf` may return 2 (success), not EOF, and only stop when it tries to read beyond the second line — which might work in some environments but is fragile. However, the real bug is elsewhere.]
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
    for(i=0;i<k;i++) // @@ [When `i = k-1`, `z[i+1][1]` accesses `z[k][1]`, which is out of bounds (since `z` has indices 0 to k-1). This causes undefined behavior.]
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
            for(j=i;z[j][1]==z[i][1];j++) // @@ [This inner loop does not check bounds; if all remaining terms have the same exponent, `j` can exceed `k-1`, leading to out-of-bounds access. Also, `ans[l][0]` is used uninitialized — it should be set to 0 before accumulation.]
                ans[l][0]+=z[j][0];
            i=j; // @@ [After the inner loop, `j` is one past the last matching exponent, so `i = j` will skip the next term correctly, but because the outer `for` loop also does `i++`, this leads to skipping an extra term. Moreover, if `j == k`, then `i = k`, and the loop ends, but the logic is error-prone.]
            l++;
        }
    }
    for(i=0;i<l;i++)
        printf("%d %d ",ans[i][0],ans[i][1]); // @@ [`ans[i][0]` may contain garbage if it was never initialized (e.g., in the `else` branch where `ans[l][0]` is used without initialization). Also, zero-coefficient terms should be omitted, but this code prints all terms regardless of coefficient value.]
    return 0;
}
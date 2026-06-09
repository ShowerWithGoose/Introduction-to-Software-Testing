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
    for(i=1;c!='\n';i++)
    {
        scanf("%d %d",&x[i][0],&x[i][1]);
        scanf("%c",&c);
    }
    countx=i;
    while(scanf("%d%d",&y[j][0],&y[j][1])!=EOF) // @@ The input format for the second polynomial likely ends with a newline, not EOF. Using !=EOF might cause the program to hang waiting for more input or fail to parse correctly if the input stream isn't closed immediately. However, the bigger issue is usually how the terms are merged. Let's look at the merging logic.
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
    for(i=0;i<k;i++)
    {
        if(z[i+1][1]!=z[i][1]) // @@ Accessing z[i+1] when i is k-1 leads to out-of-bounds access. Also, this logic fails to accumulate coefficients for all terms with the same exponent correctly if there are more than 2 terms with the same exponent, or if the accumulation logic is flawed.
        {
            ans[l][0]=z[i][0]; // @@ If the previous term was part of a group, this overwrites the accumulated sum instead of adding to it? No, l increments only when a new group starts. But the accumulation logic below is problematic.
            ans[l][1]=z[i][1];
            l++;
        }
        else
        {
            ans[l][1]=z[i][1]; // @@ This assumes ans[l] already exists and we are just updating the exponent (which is redundant) and adding to the coefficient. But ans[l][0] was initialized in the previous iteration? No, if i=0 and z[0]==z[1], we go to else. ans[l][0] is uninitialized garbage.
            for(j=i;z[j][1]==z[i][1];j++)
                ans[l][0]+=z[j][0]; // @@ ans[l][0] is uninitialized here if this is the first term of a group. It should be initialized to 0 or the first term's coefficient before adding.
            i=j; // @@ The loop increment i++ will happen next, skipping the term at index j. This is correct for moving past the processed group, but the initialization of ans[l][0] is the critical bug.
            l++;
        }
    }
    for(i=0;i<l;i++)
        printf("%d %d ",ans[i][0],ans[i][1]);
    return 0;
}
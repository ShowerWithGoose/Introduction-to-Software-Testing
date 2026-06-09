#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 105
int p[M][M];
int y[M][M];
int a;
int v=1;
int cmp(const void*p,const void*q) // @@ The comparison function is logically flawed for sorting or grouping segments. It attempts to check connectivity but returns 1/0 instead of -1/0/1 for qsort, and its logic doesn't establish a proper order for chaining segments. However, since qsort isn't used on the segments directly in main, this function is only used in f(). The logic inside cmp checks if endpoints match, which is relevant for connectivity, but using it as a comparator is semantically wrong. More importantly, the global variable 'v' is used incorrectly across recursive calls.
{
    int*p1=(int*)p;
    int*q1=(int*)q;
    if((*p1==*q1&&*(p1+1)==*(q1+1))||(*p1==*(q1+2)&&*(p1+1)==*(q1+3))||(*q1==*(p1+2)&&*(q1+1)==*(p1+3))||(*(p1+2)==*(q1+2)&&*(p1+3)==*(q1+3)))
    {
    return 1; 
    } 
    
    return 0;
}
void f(int ii,int aa)
{
    int jj;
    int kk=0;
    int kt=0;
    int vv=0;
        for(jj=1;jj<=a;jj++)
        {    
                if(jj==ii)
                continue;

                if(cmp(p[ii],p[jj])==1)
                {
                    for(kk=1;kk<=v;kk++)
                {
                    if(jj==y[aa][kk])
                    kt=1;
                }
                if(kt==1)
                {
                    kt=0;
                    continue;
                }
                                    
                    v++; // @@ The global variable 'v' is incremented here. Since 'v' is global and shared across all recursive calls and different starting points 'i' in main, it does not correctly track the length of the current chain being built for a specific start point 'aa'. It accumulates globally, leading to incorrect counts and array indices in y[aa].
                    y[aa][v]=jj;

                    vv++;
                    f(jj,aa);
                    y[aa][0]++; // @@ This increments the count of segments in the chain for start point 'aa'. However, because 'v' is global and messed up, the structure of y[aa] is corrupted. Also, y[aa][0] is incremented for every found neighbor, but the recursion depth and backtracking are not handled correctly to form a simple path count. The problem asks for a continuous line (a path), not just a count of connected components. The logic here tries to do a DFS but fails to maintain path state correctly due to global 'v'.
                }
                
        }
        if(vv==0)
        return;
  

}

int main()
{

    int u=0;
    scanf("%d",&a);
    int i,j,k;
    for(i=1;i<=a;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&p[i][j]);
            
        }
    }
    u=1;
    for(i=1;i<=a;i++)
    {
        y[i][0]=1;
        y[i][1]=i;
         f(i,i);
        v=1; // @@ Resetting v to 1 here attempts to mitigate the global state issue, but the damage to y[i] during the recursive calls of f(i,i) where v grew globally means y[i] contains garbage or incorrect indices from previous iterations or deep recursion. The logic for building the chain in y[i] is fundamentally broken because 'v' is not local to the chain construction.
    }
    int max=y[1][0];
    int t=1;
    for(i=2;i<a;i++) // @@ Loop condition should be i<=a to include the last segment. Currently, it skips the last segment when checking for the maximum.
    {
        if(y[i][0]>max)
        {
            max=y[i][0];
            t=i;

        }
    }
    int lt1,lt2;
    int min1=p[y[t][1]][0];lt1=lt2=y[t][i];int max1=p[y[t][1]][3]; // @@ 'i' is used here but it is out of scope from the previous loop (or holds the value a if the loop finished normally, which is out of bounds for y[t]). It should likely initialize lt1 and lt2 based on the first element of the chain y[t][1]. Also, accessing y[t][i] is undefined behavior if i >= y[t][0] or i is stale.
    for(i=1;i<=y[t][0];i++)
    {
        
        if(min1>p[y[t][i]][0])
        {
            min1=p[y[t][i]][0];
            lt1=y[t][i];
        }
        if(max1>p[y[t][i]][2])
        {
            max1=p[y[t][i]][2];
            lt2=y[t][i];
        }

    }
    printf("%d %d %d",y[t][0],min1,p[lt1][1]); // @@ The output format requires the number of segments, then the x and y coordinates of the starting point. The starting point of the continuous line is the endpoint with the smallest x-coordinate. The code finds min1 (smallest x) and prints p[lt1][1] which is the y-coordinate of that segment's start point. However, the problem states each segment has x1 < x2. The "starting point" of the *continuous* line is the one with the global minimum x. If lt1 is the index of the segment with the global min x, p[lt1][0] is that x. p[lt1][1] is the y of the start of that segment. But we need to ensure we pick the correct endpoint of that segment. Since x1 < x2, the start of the segment is (x1, y1). So p[lt1][1] is correct for y IF lt1 corresponds to the segment containing the global start. However, the logic to find the true start point of the chained line is flawed because the chain construction itself is broken. The primary error leading to the wrong answer in the test case is the incorrect identification of the start point coordinates due to broken chain logic and potentially incorrect index usage. In the specific test case, the expected start is (12, 12). The buggy output is (12, 13). This suggests lt1 picked the segment starting at 12, but grabbed the wrong y, or picked the wrong segment. Given input: Seg 1: (12,12)-(13,13), Seg 2: (13,13)-(50,76). Start is (12,12). p[1] is {12,12,13,13}. p[2] is {13,13,50,76}. If chain is correct, y[t] should contain 1 and 2. min x is 12 from seg 1. p[1][1] is 12. Why did it print 13? Likely because the chain construction failed or lt1 was assigned incorrectly. The line `lt1=lt2=y[t][i]` uses uninitialized/stale `i`. If `i` happened to be 2, y[t][2] might be 2. p[2][1] is 13. This matches the bug. So the initialization of lt1/lt2 is the direct cause of the wrong Y coordinate.
    
    

    

    
}
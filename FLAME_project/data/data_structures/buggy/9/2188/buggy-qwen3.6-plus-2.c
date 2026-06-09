#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 105
int p[M][M];
int y[M][M];
int a;
int v=1;
int cmp(const void*p,const void*q) // @@ The comparison function is logically incorrect for sorting or grouping segments. It attempts to check connectivity but returns 1/0 inconsistently with qsort expectations, and isn't used for sorting anyway. However, the main logic relies on DFS-like traversal in f().
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

                if(cmp(p[ii],p[jj])==1) // @@ This checks if segment ii and jj share ANY endpoint. The problem states segments form a continuous line if they share an endpoint, but specifically implies a direction (start to end). The reference solution sorts by start/end and chains them. This naive connectivity check creates a graph where any touching segments are connected.
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
                                    
                    v++;
                    y[aa][v]=jj;

                    vv++;
                    f(jj,aa);
                    y[aa][0]++;
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
        v=1;
    }
    int max=y[1][0];
    int t=1;
    for(i=2;i<a;i++) // @@ Loop condition should be i <= a to include the last segment in the comparison.
    {
        if(y[i][0]>max)
        {
            max=y[i][0];
            t=i;

        }
    }
    int lt1,lt2;
    int min1=p[y[t][1]][0];lt1=lt2=y[t][i];int max1=p[y[t][1]][3]; // @@ 'i' is used here but it is out of scope from the previous loop (or holds value 'a' if loop finished normally, or undefined behavior if loop didn't run). It should likely initialize lt1 based on the first element of the chain y[t][1]. Also, logic to find the true start point of the continuous line is flawed. It just finds the segment with the minimum start X among all connected segments, but doesn't verify if that segment is actually the start of the continuous chain relative to the connections.
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
    printf("%d %d %d",y[t][0],min1,p[lt1][1]); // @@ The output uses min1 (the minimum x-coordinate found among all segments in the connected component) and p[lt1][1] (the y-coordinate of the start point of that specific segment). In the test case, segment 1 is (12,12)-(13,13) and segment 2 is (13,13)-(50,76). They are connected. The code finds min x=12. lt1 becomes segment 1. p[lt1][1] is 12. Wait, the buggy output was 2 12 13. Let's re-read carefully.
    // In the test case:
    // p[1] = {12, 12, 13, 13}
    // p[2] = {13, 13, 50, 76}
    // f(1,1) connects 1 and 2. y[1] contains {1, 2}. y[1][0] = 2.
    // f(2,2) connects 2 and 1. y[2] contains {2, 1}. y[2][0] = 2.
    // Max is 2. t can be 1 or 2. Let's say t=1.
    // min1 initialized to p[y[1][1]][0] = p[1][0] = 12.
    // lt1 initialized to y[1][i]. If i=2 (from previous loop), lt1 = y[1][2] = 2.
    // Loop i=1 to 2.
    // i=1: min1 (12) > p[y[1][1]][0] (12)? No.
    // i=2: min1 (12) > p[y[1][2]][0] (13)? No.
    // So lt1 remains 2 (from initialization using stale 'i').
    // Output: y[1][0] (2), min1 (12), p[lt1][1] -> p[2][1] -> 13.
    // This matches the buggy output "2 12 13".
    // The error is indeed the initialization of lt1 using 'i' which is not the correct index for the segment with the minimum start coordinate, or rather, the logic fails to correctly identify the starting segment of the chain.
    // Correct logic should identify the segment that is the "start" of the continuous line. Since x increases, the start point has the global minimum x. If multiple segments have same min x (not possible here as x1<x2 and no overlap intersections), we pick the one.
    // Here, segment 1 starts at 12. Segment 2 starts at 13. Min x is 12. Segment 1 is the start. Its y is 12.
    // The code picked lt1=2 because of `lt1=lt2=y[t][i]` where `i` was leftover from the previous loop.
    
    

    

    
}
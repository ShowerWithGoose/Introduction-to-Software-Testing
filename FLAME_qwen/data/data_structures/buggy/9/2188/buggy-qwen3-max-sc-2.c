#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 105
int p[M][M];
int y[M][M];
int a;
int v=1;
int cmp(const void*p,const void*q)
{
    int*p1=(int*)p;
    int*q1=(int*)q;
    if((*p1==*q1&&*(p1+1)==*(q1+1))||(*p1==*(q1+2)&&*(p1+1)==*(q1+3))||(*q1==*(p1+2)&&*(q1+1)==*(p1+3))||(*(p1+2)==*(q1+2)&&*(p1+3)==*(q1+3)))
    {
    return 1; 
    } 
    
    return 0; // @@ [The cmp function for qsort must return negative, zero, or positive (not just 0/1). Returning 1 for "equal" and 0 otherwise breaks sorting logic. Also, this function is never used with qsort, so its design is flawed for the intended purpose.]
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
                                    
                    v++;
                    y[aa][v]=jj;

                    vv++;
                    f(jj,aa);
                    y[aa][0]++; // @@ [This increments the count after recursive call, but should increment before or during connection establishment. Also, y[aa][0] is used as segment count, but it's incremented multiple times per path due to recursion unwinding, leading to overcounting.]
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
        v=1; // @@ [Resetting v=1 after each f(i,i) call is correct, but the global variable 'v' makes the recursion stateful and error-prone. Using a global counter in recursive DFS is unsafe and causes incorrect tracking of current path length.]
    }
    int max=y[1][0];
    int t=1;
    for(i=2;i<a;i++) // @@ [Loop condition should be i<=a, not i<a. This skips the last segment (index a), possibly missing the longest chain.]
    {
        if(y[i][0]>max)
        {
            max=y[i][0];
            t=i;

        }
    }
    int lt1,lt2;
    int min1=p[y[t][1]][0];lt1=lt2=y[t][i];int max1=p[y[t][1]][3]; // @@ [Here, 'i' is uninitialized (loop variable from previous loop ended with i=a or i=a+1). Using y[t][i] accesses garbage memory. Also, lt2 is unused later, and the logic to find starting point is flawed.]
    for(i=1;i<=y[t][0];i++)
    {
        
        if(min1>p[y[t][i]][0])
        {
            min1=p[y[t][i]][0];
            lt1=y[t][i];
        }
        if(max1>p[y[t][i]][2]) // @@ [This condition is backwards: to find the rightmost endpoint, we should check if p[y[t][i]][2] > max1, not the other way. But more critically, the starting point of the continuous segment is the one with smallest x, which is already tracked by min1, but the y-coordinate must come from the same segment that has x=min1. However, the final printf uses p[lt1][1], which is correct only if lt1 was properly set. The earlier line lt1=lt2=y[t][i] with undefined 'i' corrupts lt1 initially.]
        {
            max1=p[y[t][i]][2];
            lt2=y[t][i];
        }

    }
    printf("%d %d %d",y[t][0],min1,p[lt1][1]); // @@ [If lt1 was corrupted by the earlier undefined 'i', p[lt1][1] may access invalid memory or wrong y-coordinate. Also, the algorithm does not correctly build continuous chains because cmp() checks all endpoint matches (including both directions), but the problem requires directional chaining (end of one = start of next, with x increasing). The cmp function allows matching any endpoints, violating the x1 < x2 ordering constraint for continuity.]
    
    
    
}
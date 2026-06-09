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
    
    return 0; // @@ [The cmp function for qsort should return negative, zero, or positive (typically -1, 0, 1), but this returns only 0 or 1. However, the bigger issue is that this cmp function is never used with qsort and its logic is flawed for segment comparison. But the immediate compilation error is not here.]
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
                    y[aa][0]++; // @@ [This line increments the count after the recursive call, which may lead to incorrect counting. The count should be updated before or as part of tracking the path, not after recursion unwinds.]
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
    for(i=2;i<a;i++) // @@ [Loop condition should be i<=a, not i<a, because segments are indexed from 1 to a inclusive. This skips the last segment when comparing for maximum length.]
    {
        if(y[i][0]>max)
        {
            max=y[i][0];
            t=i;

        }
    }
    int lt1,lt2;
    int min1=p[y[t][1]][0];lt1=lt2=y[t][i];int max1=p[y[t][1]][3]; // @@ [Variable 'i' is uninitialized here (it went out of scope after previous loop) and using it leads to undefined behavior. Also, lt2 assignment is meaningless and max1 initialization is incorrect for finding rightmost endpoint.]
    for(i=1;i<=y[t][0];i++)
    {
        
        if(min1>p[y[t][i]][0])
        {
            min1=p[y[t][i]][0];
            lt1=y[t][i];
        }
        if(max1>p[y[t][i]][2]) // @@ [Should be '<' instead of '>' to find the maximum x-coordinate endpoint, but actually this whole block is flawed because the continuous segment must be ordered by x, and starting point is the one with smallest x, which is already being tracked by min1. However, the use of uninitialized 'i' above is a critical error.]
        {
            max1=p[y[t][i]][2];
            lt2=y[t][i];
        }

    }
    printf("%d %d %d",y[t][0],min1,p[lt1][1]); // @@ [This prints the correct starting point's x and y if lt1 is correctly set, but due to earlier errors (uninitialized i, wrong loop bounds, flawed DFS counting), lt1 may be incorrect.]
    
    
    
}
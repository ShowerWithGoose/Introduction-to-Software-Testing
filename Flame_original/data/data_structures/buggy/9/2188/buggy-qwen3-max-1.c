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
    
    return 0; // @@ [The cmp function for qsort must return negative, zero, or positive (not just 0/1). Returning only 0 or 1 breaks sorting logic and causes undefined behavior.]
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
                    y[aa][0]++; // @@ [This increments the count after recursion, but it should be set before or managed differently; also, y[aa][0] is used as segment count but is incremented multiple times incorrectly.]
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
    for(i=2;i<a;i++) // @@ [Loop condition should be i<=a, not i<a; this skips the last segment when comparing for maximum length.]
    {
        if(y[i][0]>max)
        {
            max=y[i][0];
            t=i;

        }
    }
    int lt1,lt2;
    int min1=p[y[t][1]][0];lt1=lt2=y[t][i];int max1=p[y[t][1]][3]; // @@ [Variable 'i' is uninitialized here (loop above ended), leading to undefined behavior when accessing y[t][i]. Also, lt2 assignment is meaningless.]
    for(i=1;i<=y[t][0];i++)
    {
        
        if(min1>p[y[t][i]][0])
        {
            min1=p[y[t][i]][0];
            lt1=y[t][i];
        }
        if(max1>p[y[t][i]][2]) // @@ [This comparison is backwards: to find the rightmost endpoint, we should check if p[y[t][i]][2] > max1, not the other way around. But more critically, this block is unnecessary since start point is determined by smallest x, but logic is flawed due to incorrect traversal.]
        {
            max1=p[y[t][i]][2];
            lt2=y[t][i];
        }

    }
    printf("%d %d %d",y[t][0],min1,p[lt1][1]); // @@ [This assumes the starting point of the entire chain is the segment with smallest x among selected segments, but the chain may not be sorted; the actual start must be the leftmost endpoint of the continuous path, which requires checking connectivity order, not just min x across all segments in the group.]
    
    
    
}
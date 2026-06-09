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
    
    return 0; // @@ [The comparison function for qsort must return negative, zero, or positive (not just 0/1). Returning only 0 or 1 breaks sorting logic and may cause undefined behavior.]
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
                    y[aa][0]++; // @@ [This increments the count after recursive call, but it should be incremented before or as part of adding the segment. Also, y[aa][0] is used to store length, but it's being incremented multiple times incorrectly during recursion.]
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
    for(i=2;i<a;i++) // @@ [Loop condition should be i<=a, not i<a, because valid indices go up to 'a'. This skips checking the last chain.]
    {
        if(y[i][0]>max)
        {
            max=y[i][0];
            t=i;

        }
    }
    int lt1,lt2;
    int min1=p[y[t][1]][0];lt1=lt2=y[t][i];int max1=p[y[t][1]][3]; // @@ [Variable 'i' is uninitialized here (leftover from previous loop), leading to undefined behavior when accessing y[t][i]. Should initialize lt1 properly.]
    for(i=1;i<=y[t][0];i++)
    {
        
        if(min1>p[y[t][i]][0])
        {
            min1=p[y[t][i]][0];
            lt1=y[t][i];
        }
        if(max1>p[y[t][i]][2]) // @@ [This condition is backwards: to find the maximum x-coordinate endpoint, it should be if(max1 < p[y[t][i]][2]). Also, this logic is unnecessary since we only need the starting point.]
        {
            max1=p[y[t][i]][2];
            lt2=y[t][i];
        }

    }
    printf("%d %d %d",y[t][0],min1,p[lt1][1]); // @@ [Correctly prints count and starting point, but relies on prior flawed logic for y[t][0] and min1.]
    
    
    
}
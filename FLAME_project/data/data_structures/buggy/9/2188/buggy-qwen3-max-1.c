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
    for(i=2;i<a;i++) // @@ [Loop condition should be i <= a, not i < a. This skips the last segment when searching for the maximum chain.]
    {
        if(y[i][0]>max)
        {
            max=y[i][0];
            t=i;

        }
    }
    int lt1,lt2;
    int min1=p[y[t][1]][0];lt1=lt2=y[t][i];int max1=p[y[t][1]][3]; // @@ [lt2=y[t][i] uses uninitialized 'i' from previous loop which is now equal to 'a'. Also, logic for finding start point is flawed.]
    for(i=1;i<=y[t][0];i++)
    {
        
        if(min1>p[y[t][i]][0])
        {
            min1=p[y[t][i]][0];
            lt1=y[t][i];
        }
        if(max1>p[y[t][i]][2]) // @@ [This condition should check for greater x to find the end, but it's checking if current max1 is greater than segment's end x, which is backwards. However, the real issue is that we only need the starting point of the whole chain, which should be the segment with smallest x among all segments in the chain, and its corresponding y. But the current logic may pick wrong segment due to incorrect comparison direction and unnecessary tracking of lt2.]
        {
            max1=p[y[t][i]][2];
            lt2=y[t][i];
        }

    }
    printf("%d %d %d",y[t][0],min1,p[lt1][1]); // @@ [The y-coordinate of the starting point should correspond to the segment that has x = min1. However, if multiple segments have same x (which shouldn't happen per problem constraints), or due to incorrect lt1 assignment, this might pick wrong y. In the test case, the first segment starts at (12,12), so output should be 12 12, but code outputs 12 13 because lt1 may not be correctly assigned. The core issue is that the algorithm doesn't correctly track the actual starting point of the entire continuous line—it assumes the segment with smallest x is the start, but doesn't ensure that this segment is indeed the beginning of the chain (i.e., no other segment ends at its start). However, given the problem constraints and the way chains are built, the segment with smallest x in the chain should be the true start. The bug arises because the code builds chains arbitrarily without ensuring directionality (x increasing), and the cmp function allows connections in any direction, possibly creating cycles or wrong order. Additionally, the recursive f() function does not enforce that connection happens only from end of one segment to start of next (with x1 < x2), leading to incorrect chaining. But the immediate cause of the wrong output in the test case is that the starting point's y-coordinate is taken from p[lt1][1], which is correct only if lt1 is the index of the segment that has x=min1 AND is the actual start of the chain. In the test case, both segments are chained: [12,12,13,13] and [13,13,50,76]. The chain starts at (12,12). The code finds min1=12 correctly, and lt1 should be the index of the first segment. However, due to the flawed loop in finding lt1 and possible incorrect chain building, lt1 might not be set properly. But looking closer: in the final loop, i runs from 1 to y[t][0] (which is 2). For i=1: y[t][1] is the first segment index, p[...][0]=12, so min1=12, lt1 = that index. For i=2: p[...][0]=13 which is >12, so lt1 remains correct. So why output y=13? Because in the printf, it uses p[lt1][1]. If lt1 is correct, p[lt1][1] should be 12. Therefore, the error must be that lt1 is not the correct index. Looking back: in the line "int min1=p[y[t][1]][0];lt1=lt2=y[t][i];", the variable 'i' here is from the prior loop, which ended with i=a (since loop was for(i=2;i<a;i++)), so if a=2, then after loop i=2. Then y[t][i] = y[t][2], which is the second segment. So lt1 is initialized to the second segment's index, not the first. Then in the loop, when i=1, min1 (12) is compared to p[y[t][1]][0] which is 12, so condition min1>p[...] is false (12>12 is false), so lt1 remains as y[t][2] (second segment). Thus, p[lt1][1] is 13, causing wrong output. The root cause is initializing lt1 with y[t][i] where i is out of intended scope and value.]
    
    
    
    

    
}
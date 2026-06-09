#include<stdio.h>
#include<stdlib.h>

struct Line
{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    
};
struct Line line[100];
int old[100]; // @@ [The 'old' array is not initialized to zero, leading to undefined behavior when checking !old[j]. This may cause incorrect chaining of segments or missed chains.]

int main()
{
    int n,i,j,k;
    int max_count=0,now_count;
    int start1=0,start2=0;
    int current;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&line[i].start_x,&line[i].start_y,&line[i].end_x,&line[i].end_y);
    }
    
    for(i=0;i<n;i++){
        now_count=1;
        current=i;
        for(j=0;j<n;j++){
            if(!old[j]&&line[current].end_x==line[j].start_x&&line[current].end_y==line[j].start_y){
                now_count++;
                current=j;
                old[j]=1; // @@ [Marking old[j]=1 modifies global state, which affects subsequent iterations of the outer loop (for different starting points). This prevents reusing segments in different chains, but the problem does not forbid reuse across different candidate chains. However, more critically, since 'old' is uninitialized, this logic is broken from the start.]
                j=-1; // @@ [Resetting j to -1 causes the inner loop to restart from j=0 after increment, but because 'old' is shared across all chains and not reset per outer loop iteration, once a segment is marked as used, it cannot be part of any other chain—even if a longer chain might start elsewhere. The algorithm should not use a global 'used' marker across different starting points.]
            }    
        }
        if(max_count<now_count){
            max_count=now_count;
            start1=line[i].start_x;
            start2=line[i].start_y;
        }
    }
    
    
    printf("%d ",max_count);
    printf("%d %d\n",start1,start2);
    
    return 0;
}
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
int old[100];

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
                old[j]=1;
                j=-1;
            }    
        }
        if(max_count<now_count){
            max_count=now_count;
            start1=line[i].start_x;
            start2=line[i].start_y;
        }
    } // @@ [The 'old' array is never reset between different starting segments (i), so once a segment is marked as used (old[j]=1), it cannot be reused in other chains. However, the problem allows each segment to be part of only one continuous line, but the algorithm must consider all possible starting points independently. Since 'old' persists across i-loops, later chains are incorrectly blocked from using segments that were used in earlier (possibly shorter) chains. Also, the 'old' array is uninitialized, leading to undefined behavior.]

    
    
    printf("%d ",max_count);
    printf("%d %d\n",start1,start2);
    
    return 0;
}
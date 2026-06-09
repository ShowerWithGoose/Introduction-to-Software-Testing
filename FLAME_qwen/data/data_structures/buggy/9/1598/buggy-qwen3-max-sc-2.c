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
int old[100]; // @@ [The array 'old' is not initialized to zero, leading to undefined behavior when checking !old[j]. This may cause incorrect chaining of segments or missed connections.]

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
                old[j]=1; // @@ [Marking 'old[j]=1' prevents reusing segment j in other chains, but the problem does not state that segments can't be part of multiple potential chains during search. However, more critically, 'old' is never reset between different starting points i, so once a segment is used in one chain, it's excluded from all subsequent chains — this breaks correctness.]
                j=-1; // @@ [Resetting j to -1 causes the loop to restart from j=0 after increment, which is intended to allow chaining beyond immediate next segment. However, combined with the unreset 'old' array, this leads to incorrect exclusion of segments in later iterations.]
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
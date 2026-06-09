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
int old[100]; // @@ [The 'old' array is not initialized to zero, leading to undefined behavior when checking !old[j]. This may cause incorrect traversal or missed connections.]

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
                old[j]=1; // @@ [Marking old[j]=1 prevents reusing segment j in other chains, but this global marking breaks the ability to test different starting points independently. The 'old' array should not persist across different i iterations.]
                j=-1; // @@ [Resetting j to -1 causes the loop to restart from j=0 after increment, but combined with the persistent 'old' array, it leads to incorrect chain building and potential infinite loops or missed segments.]
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
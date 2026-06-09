#include<stdio.h>
#include<stdlib.h>
struct data{
    int x1;
    int y1;
    int x2;
    int y2;
}spot[1024];
int cmp(const void *p1,const void *p2);
int main(){
    int n;
    scanf("%d",&n);
    int ans=1,temp=1;
    int ansx=0,ansy=0;
    int pos=0; 
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&spot[i].x1,&spot[i].y1,&spot[i].x2,&spot[i].y2);
    }
    qsort(spot,n,sizeof(struct data),cmp);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;j++){
            if(j!=i&&((spot[j].x1!=0)||(spot[j].y1!=0)||(spot[j].x2!=0)||(spot[j].y2!=0))){
                if((spot[j].x1==spot[i].x2)&&(spot[j].y1==spot[i].y2)){
                                            spot[i].x2=spot[j].x2;
                                            spot[i].y2=spot[j].y2;
                                            temp++;
                                            if(ans<=temp){
                                            ans=temp;
                                            pos=i;
                                            }
                                            spot[j].x1=0;
                                            spot[j].y1=0;
                                            spot[j].x2=0;
                                            spot[j].y2=0;
                                        }
            }
        }
        temp=0; // @@ The variable 'temp' is reset to 0 at the end of every outer loop iteration. However, 'temp' is initialized to 1 before the loops and represents the count of segments in the current chain being built. When a new chain starts (or continues from a previous segment that wasn't merged into the current 'i'), 'temp' should ideally be reset to 1 (the current segment itself) or handled differently. More critically, the logic for finding the longest path is flawed because it modifies the array in place (setting used segments to 0) while iterating, which prevents finding chains that might branch or be part of a longer sequence starting from a different node if the order isn't perfectly linear and captured by the first pass. But the specific error causing "3" instead of "2" in the test case is likely due to how `ans` and `temp` are managed. In the test case: Segment 0 (12,12->13,13) and Segment 1 (13,13->50,76). Sorted: Spot[0] is (12,12...), Spot[1] is (13,13...).
        // i=0: Inner loop j=1. Match found. Spot[0] becomes (12,12->50,76). temp becomes 2. ans becomes 2. pos=0. Spot[1] zeroed.
        // End of i=0 loop: temp set to 0.
        // i=1: Spot[1] is zeroed, so inner loop condition fails.
        // Final printf: ans+1 = 2+1 = 3. This is incorrect. The number of segments is stored in 'ans', but the code prints 'ans+1'.
    }
    printf("%d %d %d",ans+1,spot[pos].x1,spot[pos].y1); // @@ The variable 'ans' already counts the number of segments correctly (initialized to 1, incremented when a segment is added). Printing 'ans+1' adds an extra segment count, leading to wrong output. It should be just 'ans'.
    return 0;
}
int cmp(const void *p1,const void *p2){
    struct data *a=(struct data*)p1;
    struct data *b=(struct data*)p2;
    if(a->x1!=b->x1) return a->x1-b->x1;
    else return a->y1-b->y1;
}
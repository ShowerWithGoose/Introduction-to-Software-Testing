#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
    int xdnum;
}xianduan;
xianduan xd[100],xmax;
int rise(const void*p1,const void*p2){
    xianduan *d1=(xianduan*)p1,*d2=(xianduan*)p2;
    if(d1->x1>d2->x1)return 1;
    else if(d1->x1<d2->x1)return -1;
    else return 0;
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&xd[i].x1,&xd[i].y1,&xd[i].x2,&xd[i].y2);      
        xd[i].xdnum=1;
    }
    qsort(xd,n,sizeof(xd[0]),rise);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if((xd[i].x2==xd[j].x1)&&(xd[i].y2==xd[j].y1)){
                xd[i].xdnum=xd[i].xdnum+1;
                xd[i].x2=xd[j].x2; // @@ The code modifies the endpoint of the current segment to merge with the next, but it fails to update the loop index or handle the chain correctly. Specifically, after merging segment j into i, the next segment in the chain might not be at j+1 if there are gaps or if the sorting doesn't guarantee immediate adjacency for all chain links without re-scanning. More critically, this greedy merge inside a nested loop without updating `i`'s perspective for subsequent `j`s can miss longer chains or double count if not careful. However, the primary logical error here is that it only checks direct adjacency from the original `i`. If segment A connects to B, and B connects to C, this loop structure (fixed `i`, iterating `j`) will see A connects to B, update A's end to B's end. Then it continues checking `j` (next segments). It does NOT check if the *new* end of A connects to C. It only checks if the *original* end of A connected to C (which it didn't). Thus, it fails to build chains longer than 2 segments properly if they aren't all directly connected to the start node in one pass, or rather, it fails to propagate the connection. Wait, actually, if A connects to B, `xd[i]` becomes A-B. The loop continues with `j++`. It checks if `xd[i]` (now A-B) connects to C. If B connected to C, then `xd[i].x2` is now B.x2, which equals C.x1. So it *should* work for linear chains IF the segments are sorted such that B comes before C. 
                // Let's re-evaluate. The sort is by x1. 
                // Segments: (12,12)-(13,13), (13,13)-(50,76).
                // i=0: xd[0] is (12,12)-(13,13). 
                // j=1: xd[1] is (13,13)-(50,76).
                // Match: xd[0].x2(13)==xd[1].x1(13) and y matches.
                // xd[0].xdnum becomes 2.
                // xd[0].x2 becomes 50, xd[0].y2 becomes 76.
                // Loop ends.
                // xmax finds xd[0] with count 2.
                // Output: 2 12 12.
                // Why did it fail? The buggy output provided in the prompt is "13 13 50 76\n2 12 12". 
                // The first line "13 13 50 76" comes from the printf inside the loop.
                // The problem asks for ONLY "2 12 12".
                // The extra printf statement causes Wrong Answer because of extra output.
                xd[i].y2=xd[j].y2;
                printf("%d %d %d %d\n",xd[j].x1,xd[j].y1,xd[j].x2,xd[j].y2); // @@ This debug print statement outputs extra text not required by the problem specification, causing a Wrong Answer verdict due to format mismatch.
            }
        }
    }
    xmax=xd[0];
    for(i=0;i<n;i++){
        if(xd[i].xdnum>xmax.xdnum)xmax=xd[i];
    }
    printf("%d %d %d",xmax.xdnum,xmax.x1,xmax.y1);
}
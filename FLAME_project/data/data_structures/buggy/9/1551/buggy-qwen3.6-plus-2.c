//
//  main.c
//  line
//
//  Created by  on 2024/4/11.
//

#include <stdio.h>

struct line{
    int x_1;
    int y_1;
    int x_2;
    int y_2;
    struct line *next;
};

int main(int argc, const char * argv[]) {
    struct line s[102];
    struct line *p=NULL;
    struct line *max=NULL;
    
    int i=0;
    int n=0;
    int j=0;
    int cnt=0;
    int out=0;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&s[i].x_1,&s[i].y_1,&s[i].x_2,&s[i].y_2);
        s[i].next=NULL;
        for(j=0;j<i;j++){
            if(s[j].x_1==s[i].x_2&&s[j].y_1==s[i].y_2){
                s[j].next=&s[i];
            }
            else if(s[j].x_2==s[i].x_1&&s[j].y_2==s[i].y_1){
                s[i].next=&s[j]; // @@ The logic for linking segments is flawed. It creates a linked list where nodes can point backwards or form cycles incorrectly relative to the "start" definition. More importantly, it doesn't handle the chain construction correctly for finding the longest path starting from the true beginning. For example, if A->B and B->C, this loop might link C to B, but if processed in different order, it might not link A to B properly if B was already linked to something else, or it creates a fragmented structure. The primary issue is that `max` and `cnt` are updated inside the while loop based on the current node `p`, but `max` is assigned `p` (the end of the chain segment so far) instead of the start of the chain. Also, `cnt` is local to the outer for loop iteration but `out` and `max` are global state. The logic `if(cnt>out){ out=cnt; max=p; }` stores the *last* node visited in the chain as `max`, but the problem asks for the *starting* point of the continuous line.
            }
        }
    }
    
    for(i=0;i<n;i++){
        p=&s[i];
        cnt=1;
        while(p->next!=NULL){
            p=p->next;
            cnt++;
            if(cnt>out){
                out=cnt;
                max=p; // @@ This assigns the current endpoint `p` to `max`. However, the problem requires outputting the coordinates of the *starting* point of the continuous line segment. Since `p` moves forward in the chain, `max` ends up pointing to the last segment in the chain, not the first. We need to track the head of the chain that produced the maximum length.
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ Two errors here: 1. It prints `cnt` which holds the count from the *last* iteration of the loop, not `out` which holds the maximum count found. 2. It prints `max->x_1` and `max->y_1`. As noted above, `max` points to the last segment in the longest chain found, but we need the starting point of that chain. Because the linking logic is also directional and potentially messy, simply taking the start of the segment pointed to by `max` is incorrect. We need to store the head of the best chain.
    return 0;
}
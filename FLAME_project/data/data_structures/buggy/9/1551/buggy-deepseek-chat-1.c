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
                s[j].next=&s[i]; // @@ Error: This only links segments in one direction (s[j] -> s[i]) but does not handle the case where s[i] should be the start of the chain. The problem requires segments to be connected in increasing x-order, but this code does not sort segments by x_1, so the linking may create incorrect chains that don't respect the x-order constraint. Additionally, it only checks for connections where s[j]'s start equals s[i]'s end, but misses the reverse case properly.
            }
            else if(s[j].x_2==s[i].x_1&&s[j].y_2==s[i].y_1){
                s[i].next=&s[j]; // @@ Error: Similar issue as above; this links s[i] -> s[j] but doesn't ensure the chain respects the increasing x-order. Since segments are not sorted, the chain may not be in the correct order, leading to incorrect counting of the longest continuous segment.
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
                max=p; // @@ Error: max should point to the starting point of the longest chain, not the last point. The problem requires outputting the starting point coordinates, but this sets max to the last segment in the chain (p after traversal), so it outputs the wrong coordinates.
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ Error: cnt here is the count from the last iteration of the outer loop, not the maximum count (out). It should print out instead of cnt. Also, max may be NULL if no chain is found, causing undefined behavior.
    return 0;
}
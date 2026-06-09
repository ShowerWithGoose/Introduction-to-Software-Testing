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
                s[i].next=&s[j]; // @@ The logic for linking segments is flawed. It only checks if the current segment `i` can be appended to a previous segment `j` (either before or after). However, it fails to handle the case where segment `i` connects two existing chains or extends a chain in the middle properly because it modifies pointers of already processed nodes without updating the "head" tracking correctly for traversal. More critically, the traversal logic later assumes a simple linked list starting from any node, but the construction here creates a graph-like structure or broken chains. Specifically, if `s[i]` is attached to `s[j]` via `s[i].next = &s[j]`, then `s[i]` points backwards. But the problem states $x_1 < x_2$, so connections should be directional from left to right. The condition `s[j].x_2==s[i].x_1` means `j` ends where `i` starts, so `j` -> `i`. The code sets `s[i].next = &s[j]`, which is a backward pointer (right to left), whereas the traversal expects forward pointers. It should be `s[j].next = &s[i]`.
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
                max=p; // @@ This updates `max` to the *last* node in the chain, not the starting node. The problem requires the coordinates of the *starting* point of the continuous line segment.
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ `cnt` here holds the count of the last processed chain, not necessarily the maximum. It should print `out`. Also, `max` points to the end node due to the error above, so it prints the end coordinates, not the start.
    return 0;
}
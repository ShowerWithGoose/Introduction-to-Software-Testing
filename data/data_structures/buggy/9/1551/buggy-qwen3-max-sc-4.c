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
                s[i].next=&s[j]; // @@ [This links segment i to j when i's start matches j's end, but this creates a backward link. The continuous line must follow increasing x-coordinates, so only forward chaining (from earlier segment to later segment) is valid. Also, this may create cycles or incorrect direction.]
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
                max=p; // @@ [max should point to the starting segment of the longest chain, not the last segment. The output requires the starting point coordinates, but here max points to the tail.]
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ [Uses 'cnt' from the last iteration of the loop, not 'out'. Also, if no chain was found (all segments isolated), max remains NULL, causing undefined behavior. Additionally, even if max is valid, it points to the end of the chain, so max->x_1 is not the starting point of the entire continuous segment.]
    return 0;
}
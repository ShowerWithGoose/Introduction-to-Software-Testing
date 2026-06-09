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
                s[j].next=&s[i]; // @@ This only links segments in one direction (s[j] -> s[i]), but does not handle the case where s[i] should be linked to s[j] when s[i] comes before s[j] in order. Also, it does not ensure the x-coordinate ordering condition (x_i < x_{i+1}) is maintained.
            }
            else if(s[j].x_2==s[i].x_1&&s[j].y_2==s[i].y_1){
                s[i].next=&s[j]; // @@ This links s[i] -> s[j], but since s[i] is processed later, this creates a backward link (from later segment to earlier segment), violating the increasing x-order requirement. The program should only link from earlier to later segments based on x-coordinates.
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
                max=p; // @@ This sets max to the last segment in the chain, but the problem requires outputting the starting point (first segment's x_1, y_1), not the last segment's coordinates.
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ cnt here is the count from the last iteration of the outer loop, not the maximum count. Should print out instead of cnt. Also, max->x_1 and max->y_1 are the coordinates of the last segment, not the starting point.
    return 0;
}
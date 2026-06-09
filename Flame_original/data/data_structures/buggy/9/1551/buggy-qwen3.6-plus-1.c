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
                s[j].next=&s[i]; // @@ [Error: Pointer direction is reversed. Since j's start matches i's end, i should point to j, so it should be s[i].next=&s[j];]
            }
            else if(s[j].x_2==s[i].x_1&&s[j].y_2==s[i].y_1){
                s[i].next=&s[j]; // @@ [Error: Pointer direction is reversed. Since j's end matches i's start, j should point to i, so it should be s[j].next=&s[i];]
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
                max=p; // @@ [Error: max should store the starting node of the longest chain (&s[i]), not the current traversing node p.]
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ [Error: cnt holds the segment count of the last processed chain, not the maximum count. It should print out.]
    return 0;
}
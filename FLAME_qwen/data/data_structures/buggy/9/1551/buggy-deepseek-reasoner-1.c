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
            if(s[j].x_1==s[i].x_2&&s[j].y_1==s[i].y_2){ // @@ The condition and the following assignment set the pointer in the wrong direction. Should link from i (which ends at the point) to j (which starts at the point), i.e., s[i].next = &s[j].
                s[j].next=&s[i]; // @@ This assignment reverses the intended link direction.
            }
            else if(s[j].x_2==s[i].x_1&&s[j].y_2==s[i].y_1){ // @@ The condition and the following assignment set the pointer in the wrong direction. Should link from j (which ends at the point) to i (which starts at the point), i.e., s[j].next = &s[i].
                s[i].next=&s[j]; // @@ This assignment reverses the intended link direction.
            }
        }
    }
    
    for(i=0;i<n;i++){
        p=&s[i];
        cnt=1;
        while(p->next!=NULL){ // @@ The while‑loop only updates out when a chain has length ≥2. For a single‑segment chain (p->next == NULL) the test and assignment inside the loop never execute, so out remains 0 for that chain. The logic should also handle the case cnt > out when the while condition fails.
            p=p->next;
            cnt++;
            if(cnt>out){
                out=cnt;
                max=p;
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ Prints cnt (value from the last iteration) instead of out (the maximum count). Also dereferences max which may be NULL if no chain was found (e.g., all segments isolated).
    return 0;
}
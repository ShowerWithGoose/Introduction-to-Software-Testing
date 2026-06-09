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
                s[j].next=&s[i]; // @@ Incorrect link direction; segment i ends where j starts, so i should point to j (s[i].next=&s[j])
            }
            else if(s[j].x_2==s[i].x_1&&s[j].y_2==s[i].y_1){
                s[i].next=&s[j]; // @@ Incorrect link direction; segment j ends where i starts, so j should point to i (s[j].next=&s[i])
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
                max=p; // @@ max should store the starting node of the longest chain (&s[i]), not the current traversal node p
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ Should print out instead of cnt, as cnt holds the length of the last traversed chain, not the maximum
    return 0;
}
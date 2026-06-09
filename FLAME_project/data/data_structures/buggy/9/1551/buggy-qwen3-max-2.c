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
                s[i].next=&s[j]; // @@ [This links the current segment backward to a previous one, which breaks the forward-only chain assumption and may create cycles or incorrect directionality. The continuous line must follow increasing x-coordinates, so only forward linking (from earlier to later) is valid.]
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
                max=p; // @@ [max should point to the head (starting point) of the longest chain, not the tail. Here it's updated to the current (last) node in the chain, so when printing max->x_1, it prints the start of the last segment, not the start of the whole chain.]
            }
        }
    }
    printf("%d %d %d\n",cnt,max->x_1,max->y_1); // @@ [Uses 'cnt' from the last loop iteration (not the maximum count 'out'), and uses 'max' which points to the tail of some chain, not the head of the longest chain. Should print 'out' and the starting point of the longest chain.]
    return 0;
}
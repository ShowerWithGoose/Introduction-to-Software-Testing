//
//  main.c
//  连续线段
//
//  Created by  on 2022/3/24.
//

#include <stdio.h>
#include <stdlib.h>
struct node{
    int x1;
    int y1;
    int x2;
    int y2;
    struct node *ptr;
}*segment[101];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        segment[i]=(struct node*)malloc(sizeof(struct node));
        scanf("%d %d %d %d",&(segment[i]->x1),&(segment[i]->y1),&(segment[i]->x2),&(segment[i]->y2));
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(segment[i]->x1==segment[j]->x2 &&segment[i]->y1==segment[j]->y2)
                segment[j]->ptr=segment[i];
    //for(int i=0;i<n;i++)
       // printf("%s\n",segment[i]->ptr);
    
    //遍历 寻找最长的n 以及xy
    int x0=0,y0=0,maxcnt=0;
    for(int i=0;i<n;i++){
        struct node *p;
        int cnt=1;
        for(p=(segment[i]->ptr);p!=NULL;p=(p->ptr))
            cnt++;
        if(cnt>maxcnt){
            x0=segment[i]->x1;
            y0=segment[i]->y1;
            maxcnt=cnt;
        }
    }
    printf("%d %d %d",maxcnt,x0,y0);
    
    return 0;
}


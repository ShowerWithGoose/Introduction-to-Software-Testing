//
//  main.c
//  testsqure4
//
//  Created by  on 2021/9/22.
//  Copyright Â© 2021 . All rights reserved.
//
#include <stdio.h>
struct point{
    int x;
    int y;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct point t[1000][1000],v1[10000];
    for (int i = 0; i < n; i++)
    {
        
        struct point a,b;
        scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);

        t[a.x][a.y].x=b.x;
        t[a.x][a.y].y=b.y;
        v1[i].x=a.x;
        v1[i].y=a.y;
    }
    int MAX_len=0;
    struct point MAX_head;
    MAX_head=v1[0];
    for (int i = 0; i < n; i++)
    {
        int x0=v1[i].x,y0=v1[i].y;
        int len=0;
        struct point head=v1[i];
        while(t[x0][y0].x>0&&t[x0][y0].y>0){
            int k=x0;
            x0=t[x0][y0].x;
            y0=t[k][y0].y;
            len++;
        }
        if(MAX_len<len){
            MAX_len=len;
            MAX_head=head;
        }
    }
    printf("%d %d %d",MAX_len,MAX_head.x,MAX_head.y);
    return 0;
}


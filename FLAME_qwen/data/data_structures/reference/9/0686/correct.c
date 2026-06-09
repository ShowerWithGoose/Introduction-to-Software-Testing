#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int check[1000];

struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    struct line* next;
}*Line, in[1000];


struct {
    int maxn;
    int x;
    int y;
}ans;

void scan(int n){
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(in[i].x1 == in[j].x2 && in[i].y1 == in[j].y2){
                in[j].next = &in[i];
                break;
            }
        }
    }
}

void bianli(int n){
    for(int i = 0; i<n; i++){
        int cnt = 0;
        struct line *r = &in[i];
        while(r){
            cnt++;
            r = r->next;
        }
        if(cnt>ans.maxn){
            ans.maxn = cnt;
            ans.x = in[i].x1;
            ans.y = in[i].y1;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%d%d%d%d", &in[i].x1, &in[i].y1, &in[i].x2, &in[i].y2);
    }
    scan(n);
    bianli(n);
    printf("%d %d %d", ans.maxn, ans.x, ans.y);
}

#include <stdio.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};
struct line up[100], down[100], ch;
int now = 1, max = 0, maxx, maxy, n;;
int check(struct line a, int d, int x, int y);
int check(struct line a, int d, int x, int y){
    for(int i = 0; i < n; i++){
        if(up[i].x1 == x && up[i].y1 == y){
            return check(up[i], d + 1,up[i].x2, up[i].y2);
        }
        else if(up[i].x1 > x){
            return d;
        }
    }
    return d;
}
int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &up[i].x1, &up[i].y1, &up[i].x2, &up[i].y2);
        down[i] = up[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(up[j].x1 > up[j + 1].x1){
                ch = up[j];
                up[j] = up[j + 1];
                up[j + 1] = ch;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(down[j].x2 > down[j + 1].x2){
                ch = down[j];
                down[j] = down[j + 1];
                down[j + 1] = ch;
            }
        }
    }
    for(int i = 0; i < n; i++){
        now = check(down[i], 1, down[i].x2, down[i].y2);
        if(now > max){
            max = now;
            maxx = down[i].x1;
            maxy = down[i].y1;
        }
    }
    printf("%d %d %d\n", max, maxx, maxy);
    return 0;
}




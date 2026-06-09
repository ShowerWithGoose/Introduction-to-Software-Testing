#include<stdio.h>

struct Line{

    int c;
    int x0,y0,x1,y1;
}line[100];

int main(){

    int n,x,y,count = 1,tab = 0,xp,yp,temp;
    scanf("%d",&n);
    scanf("%d%d%d%d",&x,&y,&xp,&yp);
    line[0].x0 = x;
    line[0].y0 = y;
    line[0].x1 = xp;
    line[0].y1 = yp;
    for(int q = 1;q < n;q ++){
        scanf("%d%d%d%d",&x,&y,&xp,&yp);
        tab = 0;
        for(int i = 0;i < count;i ++){
            if(line[i].x1 == x && line[i].y1 == y){
                line[i].x1 = xp;
                line[i].y1 = yp;
                line[i].c ++;
                temp = i;
                tab = 1;
                break;
            }
        }
        if(tab == 0){
            line[count].x0 = x;
            line[count].y0 = y;
            line[count].x1 = xp;
            line[count].y1 = yp;
            temp = count;
            count ++;
        }
        for(int i = 0;i < count;i ++){
            if(line[i].x0 == xp && line[i].y0 == yp){
                line[i].x0 = line[temp].x0;
                line[i].y0 = line[temp].y0;
                line[i].c += (line[temp].c + 1);
                line[temp].x0 = line[temp].y0 = line[temp].x1 = line[temp].y1 = -1;
                break;
            }
        }
    }
    int max = 0,loc = 0;
    for(int i = 0;i < count;i ++){
        if(line[i].c > max){
            loc = i;
            max = line[i].c;
        }
    }
    printf("%d %d %d\n",line[loc].c + 1,line[loc].x0,line[loc].y0);
}

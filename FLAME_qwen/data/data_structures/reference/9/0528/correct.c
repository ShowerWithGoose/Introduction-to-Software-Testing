#include<stdio.h>
struct L{
    int x;
    int y;
    int xend;
    int yend;
    int num;
}line[105],line0;
int cmp(int mode,int line_num,struct L line0)
{
    int i=0;
    for(i=1;i<=line_num;i++){
        if(line[i].xend==line0.x&&line[i].yend==line0.y){
            line[i].xend=line0.xend;
            line[i].yend=line0.yend;
            line[i].num+=line0.num;
            break;
        }else if(line[i].x==line0.xend&&line[i].y==line0.yend){
            line[i].x=line0.x;
            line[i].y=line0.y;
            line[i].num+=line0.num;
            break;
        }
    }
    if(mode){
        if(i>line_num)
            line[line_num+1]=line0;
        return i;
    }
    return 0;
}
int main()
{
    int N,i,line_num=0,max=0,maxplace=0,flag;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d%d%d",&line0.x,&line0.y,&line0.xend,&line0.yend);
        line0.num=1;
        i=cmp(1,line_num,line0);
        if(i>line_num)
            line_num++;
    }
    for(i=line_num;i>=2;i--){
        cmp(0,i-1,line[i]);
    }
    for(i=1;i<=line_num;i++)
        if(line[i].num>max){
            max=line[i].num;
            maxplace=i;
        }
    printf("%d %d %d",max,line[maxplace].x,line[maxplace].y);
    return 0;
}


#include <stdio.h>
#define maxn 110

struct loc
{
    int x,y;
};
struct Line
{
    struct loc h,e;
    int num;
};

int main()
{
    struct Line line[maxn];
    int i,j,k,n,m;

    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d%d",&line[i].h.x,&line[i].h.y);
        scanf("%d%d",&line[i].e.x,&line[i].e.y);
        line[i].num = 1;
    }
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            if(line[i].e.x == line[j].h.x && line[i].e.y == line[j].h.y){
                line[i].e.x = line[j].e.x;
                line[i].e.y = line[j].e.y;
                line[i].num += line[j].num;
                j = -1;
            }
        }
    }
    k = m = 0;
    for(i = 0;i < n;i++){
        if(k < line[i].num){
            k = line[i].num;
            m = i;
        }
    }
    printf("%d %d %d\n",k,line[m].h.x,line[m].h.y);

    return 0;
}


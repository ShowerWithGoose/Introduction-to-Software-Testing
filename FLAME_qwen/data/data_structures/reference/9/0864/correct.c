#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define ull unsigned long long
//先排序
struct where
{
    int x1;
    int y1;
    int x2;
    int y2;
};

int cmp(const void*p,const void*q){
    struct where *a=(struct where*)p;
    struct where*b=(struct where*)q;
    if(a->x1!=b->x1)return a->x1>b->x1?1:-1;
    else return a->x2>b->x2?1:-1;
}

int count[100];

int main(){
	struct where line[105];
    int n,cnt=1;
    int max=1,max_x,max_y,temp_x,temp_y;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }

     qsort(line,n,sizeof(struct where),cmp);

    for(int i=0;(i<n);i++) //条件
    {
        temp_x=line[i].x2,temp_y=line[i].y2;
            for(int j=i+1;j<n;j++)//condition
            {
                if((line[j].x1==temp_x)&&(line[j].y1==temp_y)){
                   cnt++;
                  temp_x=line[j].x2,temp_y=line[j].y2;
                }
            }
            if(cnt>max)
            {
                max=cnt;
                max_x=line[i].x1,max_y=line[i].y1;
            }
            cnt=1;
    }

    printf("%d %d %d",max,max_x,max_y);

}



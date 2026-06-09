#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 105

typedef struct theline
{
    int x1, y1;
    int x2, y2;
    int num;
} LINE;

LINE line[MAX];

int cmp_start(const void*p1,const void*p2){
    LINE *a=(LINE*)p1,*b=(LINE*)p2;
    if(a->x1!=b->x1) return a->x1-b->x1;
    else return a->y1-b->y1;
}

int cmp_end(const void*p1,const void*p2){
    LINE *a=(LINE*)p1,*b=(LINE*)p2;
    return b->num-a->num;
}

int main()
{   
    int n;
    scanf("%d\n", &n);
    for(int i=0;i<n;i++) line[i].num=1;
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
    qsort(line,n,sizeof(LINE),cmp_start);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            else{
                if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1){
                    line[i].x2=line[j].x2;
                    line[i].y2=line[j].y2;
                    line[i].num= line[i].num+ line[j].num;
                    line[j].x1=0;line[j].x2=0;line[j].y1=0;line[j].y2=0;line[j].num=0;
                }
            }
        }
    }
    qsort(line,n,sizeof(LINE),cmp_end);
    printf("%d %d %d",line[0].num,line[0].x1,line[0].y1);
    return 0;
}

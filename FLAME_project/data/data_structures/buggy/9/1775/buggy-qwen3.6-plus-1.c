#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
}LINE;
int cmp(const void *p1,const void *p2){
    LINE *a=(LINE*)p1;
    LINE *b=(LINE*)p2;
    return a->num-b->num;
}
int cmp2(const void *p1,const void *p2){
    LINE *a=(LINE*)p1;
    LINE *b=(LINE*)p2;
    if(a->x1!=b->x1) // @@ [The sorting key should be a->x1 vs b->x1 to sort by start point. Comparing a->x1 with b->x2 is logically incorrect for establishing a sequence based on start coordinates.]
        return a->x1-b->x1;
    else 
        return a->y1-b->y1;    
}
int main(){
    LINE line[2000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
        line[i].num=1;
    }
    qsort(line,n,sizeof(LINE),cmp2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i)
                continue;
            else{
                if(line[j].x1==line[i].x2&&line[j].y1==line[i].y2){
                    line[i].x2=line[j].x2;
                    line[i].y2=line[j].y2;
                    line[i].num+=line[j].num;
                    line[j].num=0,line[j].x1=0,line[j].x2=0,line[j].y1=0,line[j].y2=0;
                }
            }    
        }
    }
    qsort(line,n,sizeof(LINE),cmp);
    printf("%d %d %d\n",line[n-1].num,line[n-1].x1,line[n-1].y1);
    return 0;
}
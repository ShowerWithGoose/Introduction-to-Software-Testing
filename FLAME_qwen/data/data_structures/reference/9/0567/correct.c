#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void*,const void*);
int cmp2(const void*,const void*);

typedef struct{
    int x,y;
    int xx,yy;
    int lock;
} line;

typedef struct{
    int cnr;
    int rline;
} rec;
int main(){
    line *l = NULL;
    rec *record = NULL;
    int max = 0,n,i,j,pi = 0,temx = 0,temy = 0,cn = 0;
    scanf("%d",&n);
    l = (line*)malloc(sizeof(line)*n);
    for(i = 0;i < n;i++) l[i].lock = 0;
    record = (rec*)malloc(sizeof(rec)*n);
    for(i = 0;i < n;i++){
        scanf("%d%d%d%d",&l[i].x,&l[i].y,&l[i].xx,&l[i].yy);
    }
    i = 0;
    qsort(l,n,sizeof(line),cmp);
    //for(j = 0;j < n;j++) printf("line:%d %d %d %d\n",l[j].x,l[j].y,l[j].xx,l[j].yy);
    for(j = 0;j < n;j++){
        if(l[j].lock == 0){
            cn++;
            l[j].lock = 1;
            temx = l[j].xx;
            temy = l[j].yy;
            for(i = j;i < n;i++){
                if(l[i].lock == 0 && l[i].x == temx &&l[i].y == temy){
                    l[i].lock = 1;
                    temx = l[i].xx;
                    temy = l[i].yy;
                    cn++;
                }
            }
        }
        record[pi].cnr = cn;
        record[pi++].rline = j;
        cn = 0;
    }
    qsort(record,pi,sizeof(rec),cmp2);
    printf("%d %d %d\n",record[0].cnr,l[record[0].rline].x,l[record[0].rline].y);
    return 0;
}

int cmp(const void* p,const void* q){
    line *m = (line*)p,*n = (line*)q;
    return (m->x > n->x)?1:-1;
}

int cmp2(const void *p,const void *q){
    rec *m = (rec*)p,*n = (rec*)q;
    return (m->cnr > n->cnr)?-1:1;
}




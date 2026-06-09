#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct num{
    int an;
    int xn;
};
struct line{
    int n;
    struct num x[100];
};
int cmp(const void *a, const void *b) {
    struct num* p = (struct num*)a, *q = (struct num*)b;
    if (p->xn>q->xn)
        return -1;
    return 1;
}
int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    int i,j,k;
    char ch;
    struct line l[3];
    for(i=0;i<3;i++)l[i].n=0;
    do{
        scanf("%d %d",&l[0].x[l[0].n].an,&l[0].x[l[0].n].xn);
        (l[0].n)++;
    }while((ch=getchar())!='\n');
//    for(i=0;i<l[0].n;i++)printf("%d %d\n",l[0].x[i].an,l[0].x[i].xn);
    while(~scanf("%d %d",&l[1].x[l[1].n].an,&l[1].x[l[1].n].xn)){
        (l[1].n)++;
    }
//    for(i=0;i<l[1].n;i++)printf("%d %d\n",l[1].x[i].an,l[1].x[i].xn);
    int temp_an,temp_xn;
    for(i=0;i<l[0].n;i++){
        for(j=0;j<l[1].n;j++){
            temp_an=(l[0].x[i].an)*(l[1].x[j].an);
            temp_xn=(l[0].x[i].xn)+(l[1].x[j].xn);
            int flag=0;
            for(k=0;k<l[2].n;k++){
                if(temp_xn==l[2].x[k].xn){
                    l[2].x[k].an+=temp_an;
                    flag=1;
                }
            }
            if(flag==0){
                l[2].x[k].xn=temp_xn;
                l[2].x[k].an=temp_an;
                (l[2].n)++;
            }
        }
    }
    qsort(l[2].x,l[2].n,sizeof(l[2].x[0]),cmp);
    for(i=0;i<l[2].n;i++){
        printf("%d %d ",l[2].x[i].an,l[2].x[i].xn);
    }
    return 0;
}



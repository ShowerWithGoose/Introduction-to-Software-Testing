#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct mult{
    int xi;
    int zhi;
};
struct mult fir[2000],mid[2000],end[2000]; 
int cmp(const void*p1,const void*p2);
int main()
{    
    int i,j,k=0;
    int n=0,nn=0;
    char ch;
    do{
        scanf("%d%d%c",&fir[n].xi,&fir[n].zhi,&ch);
        n++;
    }while(ch!='\n');
    do{
        scanf("%d%d%c",&mid[nn].xi,&mid[nn].zhi,&ch);
        nn++;
    }while(ch!='\n');
    for(i=0;i<n;i++){
        for(j=0;j<nn;j++){
            end[k].xi=fir[i].xi*mid[j].xi;
            end[k].zhi=fir[i].zhi+mid[j].zhi;
            k++;
        }
    }
    qsort(end,k,sizeof(struct mult),cmp);
    for(i=0;i<k;i++){
        if(end[i].zhi == end[i+1].zhi && end[i].zhi!=0){
            end[i+1].xi+=end[i].xi;
            end[i].xi=0;
        }
    }
    qsort(end,k,sizeof(struct mult),cmp);
    for(i=0;i<k;i++){
        if(end[i].xi==0)
            continue;
        else
            printf("%d %d ",end[i].xi,end[i].zhi); 
    }
    return 0;
}
int cmp(const void*p1,const void*p2){
    struct mult *a=(struct mult*)p1;
    struct mult *b=(struct mult*)p2;
    return b->zhi-a->zhi;
}


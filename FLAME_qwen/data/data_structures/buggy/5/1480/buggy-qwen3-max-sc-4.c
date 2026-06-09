#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct xiang{
    int xi;
    int zhi;
};
int cmp(const void *a,const void *b){
    int sml=((struct xiang *)a)->zhi;
    int big=((struct xiang *)b)->zhi;
    return big-sml;
}
int main()
{
struct xiang a[10000];
struct xiang b[10000];
struct xiang e[1000000];
char c,d;
int i,j,k,lena,lenb,lene;
//读取数据
for(i=0;scanf("%d",&a[i].xi)!=EOF;i++){
    scanf("%d",&a[i].zhi);
    scanf("%c",&c);
    if(c=='\n'){
        break;
    }
}
lena=i;
for(i=0;scanf("%d",&b[i].xi)!=EOF;i++){
    scanf("%d",&b[i].zhi);
    scanf("%c",&d);
    if(d=='\n'){
        break;
    }
}
lenb=i;
//相乘
for(i=0,k=0;i<=lena;i++){ // @@ [Loop condition should be i < lena, not i <= lena. This causes out-of-bounds access to a[lena], which is uninitialized.]
    for(j=0;j<=lenb;j++,k++){ // @@ [Loop condition should be j < lenb, not j <= lenb. This causes out-of-bounds access to b[lenb], which is uninitialized.]
        e[k].xi=a[i].xi*b[j].xi;
        e[k].zhi=a[i].zhi+b[j].zhi;
    }
}
lene=k;
for(k=1;k<lene;k++){
    for(i=0;i<k;i++){
        if(e[i].zhi==e[k].zhi){
            e[i].xi+=e[k].xi;
            e[k].xi=-1;//相同的删除赋值-1
        }
    }
}
//排序
qsort(e,lene-1,sizeof(e[0]),cmp); // @@ [Should sort lene elements, not lene-1. Also, elements marked with xi=-1 are still included in sorting and output logic may be inconsistent.]
//输出
for(k=0;k<lene;k++){
    if(e[k].xi!=-1){
        printf("%d %d ",e[k].xi,e[k].zhi);
    }
}
return 0;
}
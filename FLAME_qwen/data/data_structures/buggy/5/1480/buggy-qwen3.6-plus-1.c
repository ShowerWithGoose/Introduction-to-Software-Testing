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
for(i=0,k=0;i<=lena;i++){ // @@ Off-by-one error: 'lena' stores the count of terms, so valid indices are 0 to lena-1. Using '<=' accesses uninitialized memory at a[lena]. Should be 'i < lena'.
    for(j=0;j<=lenb;j++,k++){ // @@ Off-by-one error: 'lenb' stores the count of terms, valid indices are 0 to lenb-1. Using '<=' accesses uninitialized memory at b[lenb]. Should be 'j < lenb'.
        e[k].xi=a[i].xi*b[j].xi;
        e[k].zhi=a[i].zhi+b[j].zhi;
    }
}
lene=k;
for(k=1;k<lene;k++){
    for(i=0;i<k;i++){
        if(e[i].zhi==e[k].zhi){
            e[i].xi+=e[k].xi;
            e[k].xi=-1;//相同的删除赋值-1 // @@ Logical error: using -1 as a deletion marker is unsafe because a valid polynomial coefficient could legitimately be -1, causing it to be incorrectly skipped during output.
        }
    }
}
//排序
qsort(e,lene-1,sizeof(e[0]),cmp); // @@ Incorrect element count for qsort: should sort 'lene' elements, not 'lene-1'. Also causes undefined behavior if lene is 0 due to unsigned integer wrap-around.
//输出
for(k=0;k<lene;k++){
    if(e[k].xi!=-1){ // @@ Corresponds to the marker issue: valid terms with coefficient -1 will be incorrectly omitted from the output.
        printf("%d %d ",e[k].xi,e[k].zhi);
    }
}
return 0;
}
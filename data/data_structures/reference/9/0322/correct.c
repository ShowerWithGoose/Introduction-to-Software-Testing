#include<stdio.h>
#include<stdlib.h>
int v[100][4];//四列分别v1x,v1y,v2x,v2y
int cmp(const void *e1, const void *e2){
    int *a = (int *)e1;
    int *b = (int *)e2;
    return *a - *b;//按二维数组第一列从小到大的顺序进行排序
}
int main(){
    int n,i,j,k=0;
    int len=0 , maxlen=0;
    int savex=0,savey=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&v[i][0]);
        scanf("%d",&v[i][1]);
        scanf("%d",&v[i][2]);
        scanf("%d",&v[i][3]);
    }
    qsort(v,n,sizeof(v[0]),cmp);//所有线段按v1x升序排序
    for(k=0;k<n;k++){//从左选某点，每轮后右移一个
        for(i=k+1,j=k;i<n;i++){//从某点向右检查一轮
            if((v[i][0]==v[j][2])&&(v[i][1]==v[j][3])){
                len++;
                j=i;
            }
        }
        if(len>maxlen){
            maxlen=len;
            savex=v[k][0];
            savey=v[k][1];
        }
        len=0;
    }
    maxlen++;
    printf("%d %d %d",maxlen,savex,savey);
}

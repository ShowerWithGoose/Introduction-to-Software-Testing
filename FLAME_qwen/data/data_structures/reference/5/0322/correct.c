#include<stdio.h>
#include<stdlib.h>
struct dxs{
    int xishu;
    int zhishu;
};
struct dxs a[1000],b[1000],c[1000];
int cmp(const void *a,const void *b){
    struct dxs *aa=(struct dxs *)a;
    struct dxs *bb=(struct dxs *)b;
    return -(aa->zhishu - bb->zhishu);//指数降序排列。a>b，则不换
}
int main(){
    int num1=0,num2=0;//a b的项数
    int i,j,k=0;
    char let;
    do{
        scanf("%d%d%c",&a[num1].xishu,&a[num1].zhishu,&let);
        num1++;
    }while(let!='\n');
    do{
        scanf("%d%d%c",&b[num2].xishu,&b[num2].zhishu,&let);
        num2++;
    }while(let!='\n');
    for(i=0;i<num1;i++){
        for(j=0;j<num2;j++){
            c[k].xishu=a[i].xishu*b[j].xishu;
            c[k].zhishu=a[i].zhishu+b[j].zhishu;
            k++;
        }
    }
    qsort(c,k,sizeof(c[0]),cmp);//按指数降序排列
    /*for(i=0;i<k;i++){
        if(c[i].xishu!=0)
            printf("%d %d ",c[i].xishu,c[i].zhishu);
    }
    printf("\n");*/
    for(i=0;i<k;i++){
        /*
        if(c[i].zhishu==c[i+1].zhishu && c[i].zhishu!=0){
            c[i].xishu=c[i].xishu+c[i+1].xishu;
            for(j=i+1;j<k-1;j++){
                c[j]=c[j+1];
                c[j+1].xishu=0;c[j+1].zhishu=0;
            }
            k--;
        }
        */
        if(c[i].zhishu==c[i+1].zhishu && c[i].zhishu!=0){
            c[i+1].xishu=c[i].xishu+c[i+1].xishu;
            c[i].xishu=0;
        }
    }
    for(i=0;i<k;i++){
        if(c[i].xishu!=0)
        printf("%d %d ",c[i].xishu,c[i].zhishu);
    }
    return 0;
}

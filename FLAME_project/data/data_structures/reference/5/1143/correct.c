#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


typedef struct{
    int index;
    int coe;
}Node;
int Comp(const void *,const void *);

int main(int argc, char *argv[]){
    Node a1[100],a2[100],rz[100];
    int n=0,m=0,i,j,k=0,i2,coe,index,flag;
    char br;
    do{
        scanf("%d %d%c",&a1[n].coe,&a1[n].index,&br);
        n++;
    }while(br!='\n');
    do{
        scanf("%d %d%c",&a2[m].coe,&a2[m].index,&br);
        m++;
    }while(br!='\n');
    for(i=0;i<n;i++){
        for(j=0,flag=0;j<m;j++){
            coe=a1[i].coe*a2[j].coe;
            index=a1[i].index+a2[j].index;
            for(i2=0;i2<k;i2++,flag=0){
                if(index==rz[i2].index){
                    rz[i2].coe=rz[i2].coe+coe;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                rz[k].coe=coe;
                rz[k].index=index;
                k++;
            }
        }
    }
    qsort(rz,k,sizeof(rz[0]),Comp);
    for(i=0;i<k;i++){
        printf("%d %d ",rz[i].coe,rz[i].index);
    }
    return 0;
}

int Comp(const void *p,const void *q){
    if((*(Node*)p).index-(*(Node*)q).index>0)return -1;
    else return 1;
}

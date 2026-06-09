#include <stdio.h>
#include <stdlib.h>
struct num{
    int m;
    int k;
}a[10000],b[10000],c[10000];
int num1(int key,int n ){
    int r=-1;
    for(int i=0;i<n;i++){
        if(key==c[i].k){
            r=i;
            break;
        }
    }
    return r;
}
int main()
{
    int i,j,x,y,z,n=0,max=1,max1,r=-1;
    i=0;
    char q;
    while(1){
        scanf("%d%d",&a[i].m,&a[i].k);
        i++;
        scanf("%c",&q);
        if(q=='\n')
            break;
    }
    x=i;
    /*printf("%d\n",x);
    for(i=0;i<x;i++)
        printf("%d",a[i].m);*/
    i=0;
    while(1){
        scanf("%d%d",&b[i].m,&b[i].k);
        i++;
        scanf("%c",&q);
        if(q=='\n')
            break;
    }
    y=i;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            r=num1(a[i].k+b[j].k,n);
            if(r==-1){
                c[n].k=a[i].k+b[j].k;
                c[n++].m=a[i].m*b[j].m;
            }
            else{
                c[r].m+=a[i].m*b[j].m;
            }
        }
    }
    z=n;
    //printf("%d\n",z);
    /*for(i=0;i<z;i++){
        printf("%d\n",a[i].m);
    }*/
    for(i=0;i<z;i++){
        max=-1;
        for(j=0;j<z;j++){
            if(c[j].k>max){
                max1=j;
                max=c[j].k;
            }
        }
        printf("%d ",c[max1].m);
        printf("%d ",c[max1].k);
        c[max1].k=-1;
    }
    return 0;
}


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct line{
    int a[2];
    int b[2];
}line[105],tmp;
int main(){
    int n,o,p,m;
    int i,j,k=0,count=0,flag=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&line[i].a[0],&line[i].a[1],&line[i].b[0],&line[i].b[1]);
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(line[j].a[0]<line[i].a[0]){
                tmp=line[j];
                line[j]=line[i];
                line[i]=tmp;
            }
        }
    }
    for(i=1;i<=n;i++){
            k=1;
            m=i;
        for(j=i+1;j<=n;j++){
           if(line[j].a[0]==line[m].b[0]&&line[j].a[1]==line[m].b[1]){
                k++;
                m=j;
           }
        }
        if(k>count){
            count=k;
            o=line[i].a[0];
            p=line[i].a[1];
        }
    }
    printf("%d %d %d",count,o,p);

    return 0;
}



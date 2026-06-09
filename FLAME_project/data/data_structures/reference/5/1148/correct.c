#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct xiang{
    int a;
    int x;
}b[10000005],d[10000005];
int po[10000005],num[10000005];
int main(){
    int n,m,i=0,j,k,q,w,t;
    char c;
    while(1){
        scanf("%d %d",&n,&m);
        c=getchar();
        if(c!=' '){
            b[++i].a=n;
            b[i].x=m;
            break;
        }
        b[++i].a=n;
        b[i].x=m;
    }
    q=i;
    i=0;
    while(1){
        scanf("%d %d",&n,&m);
        c=getchar();
        if(c!=' '){
            d[++i].a=n;
            d[i].x=m;
            break;
        }
        d[++i].a=n;
        d[i].x=m;
    }
    w=i;
    i=1;
    for(j=1;j<=q;j++){
        for(k=1;k<=w;k++){
            po[i]=(b[j].x+d[k].x);
            num[i]=(b[j].a*d[k].a);
            i++;
        }
    } 
    for(j=1;j<i;j++){
        for(k=j+1;k<i;k++){
            if(po[k]==po[j]){
                num[j]+=num[k];
                po[k]=0;
                num[k]=0;
            }
        }
    }
    i-=1;
    for(j=1;j<=i;j++){
        for(k=1;k<i;k++){
            if(po[k]<po[k+1]){
                t=num[k];
                num[k]=num[k+1];
                num[k+1]=t;
                t=po[k];
                po[k]=po[k+1];
                po[k+1]=t;          
            }
        }
    }   
    for(j=1;j<=i;j++){
        if(po[j]!=0)printf("%d %d ",num[j],po[j]);
        else if(po[j]==0&&num[j]!=0)printf("%d %d ",num[j],po[j]);
    }
    return 0;
}

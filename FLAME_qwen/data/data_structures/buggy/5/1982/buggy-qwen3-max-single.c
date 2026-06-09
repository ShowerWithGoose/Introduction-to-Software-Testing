#include<stdio.h>
#include<stdlib.h>
struct number{
    int xi;
    int mi;
}dot[1000];
int main(){
    int x1[105]={0},x2[105]={0},temp1,temp2;
    int m1[105]={0},m2[105]={0};
    int i=1,j=1,k,n,m=1,l;
    for(i=1;i>0;i++){
        scanf("%d%d",&x1[i],&m1[i]);
        if(m1[i]==0)
        break;
    }
    n=i; // @@ [The loop breaks when m1[i] == 0, but the problem does not guarantee that the constant term (exponent 0) is the last input. Input ends with newline, not necessarily with exponent 0. This causes incorrect reading of polynomial terms.]
        for(j=1;j>0;j++){
        scanf("%d%d",&x2[j],&m2[j]);
        if(m2[j]==0)
        break;
    }
    k=j; // @@ [Same issue as above: assumes input ends with exponent 0, but problem states input ends with newline and only non-zero terms are given. May miss terms or read incorrectly.]
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            dot[m].xi=x1[i]*x2[j];
            dot[m].mi=m1[i]+m2[j];
            m++;
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=m-i;j++){
            if(dot[j].mi>dot[j+1].mi){
                temp1=dot[j].mi;
                dot[j].mi=dot[j+1].mi;
                dot[j+1].mi=temp1;
                temp2=dot[j].xi;
                dot[j].xi=dot[j+1].xi;
                dot[j+1].xi=temp2;
            }
        }
    }
    for(i=1;i<=m;i++){
        for(j=i+1;j<=m;j++){
        if(dot[i].mi==dot[j].mi){
            dot[i].xi+=dot[j].xi;
            dot[j].xi=0;
        }    
    }
}
    for(i=1;i<=m;i++){
        if(dot[i].xi==0){
            for(j=i;j<m;j++){
                dot[j].xi=dot[j+1].xi;
                dot[j].mi=dot[j+1].mi;
            }
            i-=1;
            m--;
        }
    }
    for(i=m;i>=1;i--){
        printf("%d %d ",dot[i].xi,dot[i].mi);
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
struct number{
    int xi;
    int mi;
}dot[1000]; // @@ Potential buffer overflow if product terms exceed 1000; use larger size or dynamic allocation.
int main(){
    int x1[105]={0},x2[105]={0},temp1,temp2; // @@ Array sizes 105 may be insufficient if polynomials have more than 105 terms; could cause overflow.
    int m1[105]={0},m2[105]={0};
    int i=1,j=1,k,n,m=1,l; // @@ m is initialized to 1, causing an off‑by‑one error: after storing products, m equals total_terms + 1, leading to an extra uninitialized term in subsequent loops.
    for(i=1;i>0;i++){
        scanf("%d%d",&x1[i],&m1[i]);
        if(m1[i]==0)
        break;
    }
    n=i;
        for(j=1;j>0;j++){
        scanf("%d%d",&x2[j],&m2[j]);
        if(m2[j]==0)
        break;
    }
    k=j;
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            dot[m].xi=x1[i]*x2[j];
            dot[m].mi=m1[i]+m2[j];
            m++; // @@ After this loop, m becomes total_products + 1, so the next loops (sorting, combining, removal) will process one extra element.
        }
    }
    for(i=1;i<=m;i++){ // @@ The loop bound should be i < m to avoid processing the extra uninitialized element at index m.
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
    for(i=1;i<=m;i++){ // @@ Same off‑by‑one issue; this loop also includes the extra element.
        for(j=i+1;j<=m;j++){
        if(dot[i].mi==dot[j].mi){
            dot[i].xi+=dot[j].xi;
            dot[j].xi=0;
        }    
    }
}
    for(i=1;i<=m;i++){ // @@ This loop also iterates over the extra element, which may cause an extra removal step and incorrect final term count.
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
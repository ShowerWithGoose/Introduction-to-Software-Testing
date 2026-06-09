#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct aminosi{
    int cao;
    int sb;
};
struct aminosi c[10005];
struct aminosi n[10005];
struct aminosi m[10005];
int compare(const void*p1,const void*p2);
int main(){
    int i,j;
    int k=0;
    int n1=0,n2=0;
    char wsl;
    
    do{
        scanf("%d%d%c",&c[n1].cao,&c[n1].sb,&wsl);
        printf("%d %d ",c[n1].cao,c[n1].sb); // @@ Unnecessary debug output that violates the output format.
        n1++;
    }while(wsl!='\n');
    printf("\n"); // @@ Unnecessary debug output that violates the output format.
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb); // @@ Unnecessary debug output that violates the output format.
        n2++;
    }while(wsl!='\n');

    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            m[k].cao=c[i].cao*n[j].cao;
            m[k].sb=c[i].sb+n[j].sb;
            k++;
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){ // @@ Loop condition should be i < k - 1 to prevent out-of-bounds access on m[i+1].
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){ // @@ Accessing m[i+1] when i == k-1 causes out-of-bounds read.
            c[i+1].cao+=c[i].cao; // @@ Incorrectly modifies array c instead of m. Should be m[i+1].cao += m[i].cao.
            c[i].cao=0; // @@ Incorrectly modifies array c instead of m. Should be m[i].cao = 0.
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ Checks wrong array c and fixed index 1. Should check m[i].cao == 0.
            continue;
        }
        else{ // @@ Missing print statement to output the polynomial terms.
             // @@ Empty block, should contain printf("%d %d ", m[i].cao, m[i].sb);.
        }
    }
    
    return 0;
}
int compare(const void*p1,const void*p2)
{
    struct aminosi *c=(struct aminosi*)p1;
    struct aminosi *n=(struct aminosi*)p2;
    return n->sb-c->sb;
}
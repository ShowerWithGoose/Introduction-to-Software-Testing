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
        printf("%d %d ",c[n1].cao,c[n1].sb); // @@ Prints debug output that is not part of the expected result. Should be removed.
        n1++;
    }while(wsl!='\n');
    printf("\n"); // @@ Prints an extra newline, causing unintended output.
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb); // @@ Prints debug output that is not part of the expected result. Should be removed.
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
    
    for(i=0;i<k;i++){
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){ // @@ The condition incorrectly skips exponent 0 and may cause out-of-bounds access when i+1 == k.
            c[i+1].cao+=c[i].cao; // @@ Should modify m array instead of c array (original input). Also potential out-of-range.
            c[i].cao=0;            // @@ Should modify m array instead of c array.
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ Uses incorrect array (c instead of m) and fixed index 1. This condition is independent of the loop variable, so no terms are ever printed.
            continue;
        }
        else{
            
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
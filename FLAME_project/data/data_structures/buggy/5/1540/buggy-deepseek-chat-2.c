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
        printf("%d %d ",c[n1].cao,c[n1].sb);
        n1++;
    }while(wsl!='\n'); // @@ The condition `wsl!='\n'` may not work correctly because `wsl` is a single character and the newline detection depends on the last character read; also, the loop reads until newline but the input format ends with a newline, so this may cause an infinite loop or incorrect reading if there are spaces or multiple lines.
    printf("\n");
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb);
        n2++;
    }while(wsl!='\n'); // @@ Same issue as above; the loop condition may not correctly detect the end of input, leading to reading beyond the intended polynomial.

    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            m[k].cao=c[i].cao*n[j].cao;
            m[k].sb=c[i].sb+n[j].sb;
            k++;
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){ // @@ This line has a logical error: it accesses `m[i+1]` when `i` can be `k-1`, causing out-of-bounds access. Also, the condition `m[i].sb!=0` is incorrect because exponents can be zero and should still be combined. Additionally, the code modifies `c[i+1].cao` and `c[i].cao` instead of `m`, which is wrong.
            c[i+1].cao+=c[i].cao; // @@ This modifies the wrong array `c` instead of `m`, and the logic for combining like terms is fundamentally flawed.
            c[i].cao=0; // @@ Same issue: modifying `c` instead of `m`, and setting coefficient to zero is not the correct way to combine terms.
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare); // @@ This second sort is unnecessary and does not fix the incorrect combination logic above.
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ This condition checks `c[1].cao` (a fixed index) instead of iterating over `m` to output results; it is completely unrelated to the intended output logic.
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
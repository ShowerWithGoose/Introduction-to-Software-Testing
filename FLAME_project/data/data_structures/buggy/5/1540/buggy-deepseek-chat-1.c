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
    }while(wsl!='\n'); // @@ The condition `wsl!='\n'` may cause an infinite loop or incorrect reading because `wsl` is a single character and the newline detection may not work as expected when input is provided without trailing newline or with spaces. Also, the loop reads until newline but the input format ends with a newline, so this may read extra terms incorrectly.
    printf("\n");
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb);
        n2++;
    }while(wsl!='\n'); // @@ Same issue as above: the loop condition may not correctly terminate, and the reading logic may fail for the second polynomial.
    
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            m[k].cao=c[i].cao*n[j].cao;
            m[k].sb=c[i].sb+n[j].sb;
            k++;
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){ // @@ This line has a logical error: it compares `m[i].sb` with `m[i+1].sb` but then incorrectly modifies `c[i+1].cao` and `c[i].cao` instead of accumulating coefficients in `m` array. Also, the condition `m[i].sb!=0` is unnecessary and may skip combining terms with exponent 0. Additionally, accessing `m[i+1]` when `i=k-1` causes out-of-bounds access.
            c[i+1].cao+=c[i].cao; // @@ This modifies the wrong array `c` instead of `m`, and the logic for combining like terms is fundamentally flawed.
            c[i].cao=0; // @@ Setting coefficient to 0 does not remove the term; it should be handled by merging into a single term.
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare); // @@ This second sort is unnecessary and does not fix the incorrect combination logic above.
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ This condition is incorrect: it checks `c[1].cao` (a fixed index) instead of the current term's coefficient, and the logic inside the loop does nothing meaningful.
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
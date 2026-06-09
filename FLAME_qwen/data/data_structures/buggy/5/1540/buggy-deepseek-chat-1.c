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
        printf("%d %d ",c[n1].cao,c[n1].sb); // @@ [This printf is not in the reference program and will output debug information, which is not required by the problem. It may cause output format mismatch.]
        n1++;
    }while(wsl!='\n');
    printf("\n"); // @@ [This extra newline is not in the reference program and will cause output format mismatch.]
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb); // @@ [Same as above, unnecessary debug output.]
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
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){ // @@ [Array index out of bounds: when i = k-1, m[i+1] accesses m[k] which is out of bounds. Also, the condition m[i].sb!=0 is incorrect; it should combine coefficients regardless of exponent value.]
            c[i+1].cao+=c[i].cao; // @@ [Wrong array used: should be m[i+1].cao += m[i].cao, not c array. Also, this logic incorrectly modifies c array instead of m.]
            c[i].cao=0; // @@ [Same issue: should be m[i].cao = 0, not c array.]
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ [Wrong array and index: should check m[i].cao, not c[1].cao. This condition is always checking the same element and is incorrect.]
            continue;
        }
        else{
            // @@ [Missing output: the else block is empty, so no output is printed. Should print m[i].cao and m[i].sb.]
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
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
        printf("%d %d ",c[n1].cao,c[n1].sb); // @@ prints input values, not required; causes output format mismatch
        n1++;
    }while(wsl!='\n');
    printf("\n"); // @@ extra newline, not required
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb); // @@ prints input values, not required
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
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){ // @@ potential out-of-bounds access when i == k-1; also condition `m[i].sb!=0` incorrectly skips combining terms with exponent 0
            c[i+1].cao+=c[i].cao; // @@ should operate on m array, not c; should add to m[i+1].cao and set m[i].cao=0
            c[i].cao=0; // @@ same issue
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ uses hardcoded index 1 on c array instead of checking m[i].cao; also uses wrong array
            continue;
        }
        else{
            // missing print statement for the result terms
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
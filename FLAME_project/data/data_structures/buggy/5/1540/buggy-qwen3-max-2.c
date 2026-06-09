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
        printf("%d %d ",c[n1].cao,c[n1].sb); // @@ [Unnecessary debug print that alters output; problem requires only the final polynomial]
        n1++;
    }while(wsl!='\n');
    printf("\n"); // @@ [Unnecessary newline in output; problem does not require extra newlines]
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb); // @@ [Unnecessary debug print that alters output]
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
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){ // @@ [Incorrect logic: accesses m[i+1] when i = k-1 (out-of-bounds); also skips combining terms with exponent 0]
            c[i+1].cao+=c[i].cao; // @@ [Wrong array used: should be m, not c; also modifies wrong index]
            c[i].cao=0; // @@ [Wrong array used: should be m, not c]
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare); // @@ [Redundant sort; doesn't fix incorrect combination logic]
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ [Wrong condition: checks c[1] instead of current term in m; also uses wrong array]
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
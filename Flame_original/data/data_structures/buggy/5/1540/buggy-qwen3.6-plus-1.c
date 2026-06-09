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
        printf("%d %d ",c[n1].cao,c[n1].sb); // @@ Unnecessary output during input; violates the requirement to only output the final multiplication result.
        n1++;
    }while(wsl!='\n');
    printf("\n"); // @@ Unnecessary newline output; violates the specified output format.
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb); // @@ Unnecessary output during input; violates the requirement to only output the final multiplication result.
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
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){
            c[i+1].cao+=c[i].cao; // @@ Modifies the wrong array 'c' instead of 'm'; should be m[i+1].cao += m[i].cao to accumulate coefficients of like terms.
            c[i].cao=0; // @@ Modifies the wrong array 'c' instead of 'm'; should be m[i].cao = 0 to mark the merged term as zero.
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ Checks the wrong array 'c' and uses a fixed index 1 instead of the loop variable 'i'; should be if(m[i].cao == 0).
            continue;
        }
        else{ // @@ Missing printf statement to output the result; should print m[i].cao and m[i].sb.
            
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
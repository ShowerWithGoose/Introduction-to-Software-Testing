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
        printf("%d %d ",c[n1].cao,c[n1].sb); // @@ [Error: This printf statement outputs debug information that is not required by the problem specification, causing extra output that does not match expected output.]
        n1++;
    }while(wsl!='\n');
    printf("\n"); // @@ [Error: This extra newline output is not part of the required output format and will cause mismatch with expected output.]
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb); // @@ [Error: Same as above, this debug output is not required and will cause output mismatch.]
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
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){ // @@ [Error: Array index out of bounds when i = k-1, accessing m[i+1] which is beyond the array. Also, the condition m[i].sb!=0 is incorrect; should combine terms with same exponent regardless of exponent value.]
            c[i+1].cao+=c[i].cao; // @@ [Error: This modifies the wrong array (c instead of m) and uses wrong indices; should combine terms in m array.]
            c[i].cao=0; // @@ [Error: Same as above, should set m[i].cao to 0, not c[i].cao.]
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ [Error: This checks a fixed element c[1] instead of the current element m[i]; also uses wrong array.]
            continue;
        }
        else{
            // @@ [Error: Missing output statement; the program should print the result here but does nothing.]
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
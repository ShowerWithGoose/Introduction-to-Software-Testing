#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct aminosi{
    int cao; // @@ The coefficient and exponent can exceed the range of 'int' during multiplication (e.g., 10^9 * 10^9 or sum of exponents 2*10^9). Should use 'long long'.
    int sb; // @@ The exponent sum can exceed the range of 'int' (e.g., 10^9 + 10^9 = 2*10^9, which is close to INT_MAX, but coefficients product definitely overflows). Should use 'long long'.
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
        printf("%d %d ",c[n1].cao,c[n1].sb); // @@ Debug print statements should be removed for final submission as they interfere with output format.
        n1++;
    }while(wsl!='\n');
    printf("\n"); // @@ Debug print statement should be removed.
    do{
        scanf("%d%d%c",&n[n2].cao,&n[n2].sb,&wsl);
        printf("%d %d ",n[n2].cao,n[n2].sb); // @@ Debug print statement should be removed.
        n2++;
    }while(wsl!='\n');

    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            m[k].cao=c[i].cao*n[j].cao; // @@ Integer overflow occurs here if 'cao' is int. Also, result is stored in 'm', but later logic incorrectly uses 'c' for merging.
            m[k].sb=c[i].sb+n[j].sb; // @@ Integer overflow possible for exponent sum if 'sb' is int.
            k++;
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare);
    
    for(i=0;i<k;i++){
        if(m[i].sb==m[i+1].sb&&m[i].sb!=0){ // @@ Logic error: accessing m[i+1] when i=k-1 is out of bounds. Also, merging logic updates array 'c' instead of 'm', leaving 'm' unmerged. The condition m[i].sb!=0 incorrectly skips merging constant terms if they have same exponent (though exponents are unique in input, products might not be).
            c[i+1].cao+=c[i].cao; // @@ Error: Updates wrong array 'c' instead of 'm'. Should merge coefficients in 'm'.
            c[i].cao=0; // @@ Error: Updates wrong array 'c'.
        }
    }
    
    qsort(m,k,sizeof(m[0]),compare); // @@ Sorting again is unnecessary if merging was done correctly, but since merging failed, this doesn't help. Also, zeroed-out terms from 'c' are not reflected in 'm'.
    
    for(i=0;i<k;i++){
        if(c[1].cao==0){ // @@ Logic error: Checks 'c' array which was modified incorrectly. Does not print anything. Missing output logic for the result polynomial stored in 'm'.
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
    return n->sb-c->sb; // @@ Potential integer overflow in subtraction if exponents are large. Should use conditional comparison.
}
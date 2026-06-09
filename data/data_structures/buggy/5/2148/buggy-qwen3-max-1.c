#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){ // @@ [This loop reads all input into a single array `a` without distinguishing between the two polynomials; it also does not stop at newline but only at EOF, which may cause incorrect parsing when two lines are given.]
        if((i%2!=0)&&a[i]>a[i-2]){ // @@ [`a[i-2]` accesses invalid memory when i==1 (first exponent), leading to undefined behavior. Also, logic for detecting polynomial boundary is flawed.]
            t=i;
        }
        i++;
    }
    if(t==1){ // @@ [This special case assumes only one term in first polynomial, but condition `t==1` is arbitrary and doesn't correctly identify single-term cases.]
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ [Accesses a[2] and a[3] even if input has fewer than 4 elements, causing out-of-bounds read.]
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){ // @@ [Incorrectly copies part of `a` into `b`; the offset `t-1` is not validated and may lead to wrong segmentation of input into two polynomials.]
        b[j]=a[j+t-1];
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ [Loop condition `a[i]!=0` assumes coefficients are non-zero and that zero marks end, but input may contain no zero and loop may run past valid data. Also, original input doesn't guarantee a trailing zero.]
        for(j=0;b[j]!=0;j=j+2){ // @@ [Same issue: assumes `b` is null-terminated with zero, which it isn't; `b` contains raw input values, possibly non-zero throughout.]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; // @@ [May access beyond bounds of `a` or `b` if their lengths are odd or miscomputed.]
            y++;
        }
    }
    int ber=(t-1)/2,k; // @@ [`ber` attempts to compute number of terms in first polynomial, but `t` was set based on flawed logic, so `ber` is likely incorrect.]
    ber=ber*(i-t+1)/2; // @@ [`i-t+1` is not necessarily even or related to second polynomial's term count; this product does not correctly represent total product terms.]
    for( i=0;i<ber;i++){
        for( j=i+1;j<ber;){ // @@ [Inner loop lacks increment in some paths; if condition fails, `j` never increments, causing infinite loop. Also, removal logic shifts array but doesn't adjust loop bounds safely.]
            if(d[j]==d[i]&&i!=j){
                c[i]=c[j]+c[i];
                for (k=j;k<ber-1;k++) {
                    d[k]=d[k+1];
                    c[k]=c[k+1];
                }
                ber--;
            }
            else{
                j++; // @@ [Only increments `j` in else branch; if merging happens, next element moves to `j` but isn't checked against `d[i]`, possibly missing duplicates.]
            }
        }
    }
    for( i=0;i<ber-1;i++){
        for( j=0;j<ber-i-1;j++){
            if(d[j]<d[j+1]){
                hold=d[j];
                H=c[j];
                d[j]=d[j+1];
                c[j]=c[j+1];
                d[j+1]=hold;
                c[j+1]=H;
            }
        }
    }
    for( i=0;i<ber;i++){
        printf("%d %d ",c[i],d[i]); // @@ [Prints even if coefficient is zero (after combination), violating problem requirement to output only non-zero terms.]
    }
    return 0;
}
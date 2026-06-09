#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){ // @@ [This loop reads all input into a single array `a` without distinguishing between the two polynomials. It also does not stop at the first newline, so it cannot correctly separate the two input polynomials.]
        if((i%2!=0)&&a[i]>a[i-2]){ // @@ [This condition assumes at least three terms exist (i >= 2), which may not be true for small inputs, leading to out-of-bounds access (e.g., a[-2] when i=1). Also, comparing exponents this way is flawed logic for detecting polynomial boundaries.]
            t=i;
        }
        i++;
    }
    if(t==1){ // @@ [This special case assumes a very specific input format and size, which is not general. It incorrectly tries to handle a case that likely doesn't reflect actual polynomial structure.]
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ [Accesses a[2] and a[3] without ensuring they exist; leads to undefined behavior on short inputs. Also, logic is incorrect: multiplying coefficients a[0]*a[1] is wrong—should multiply terms across polynomials, not within one.]
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){ // @@ [The calculation of how many elements belong to the second polynomial is based on flawed `t`, leading to incorrect copying into `b`.]
        b[j]=a[j+t-1]; // @@ [If `t` is 0 or 1, `t-1` could be -1 or 0, causing invalid indexing or misalignment of polynomial terms.]
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ [Loop condition `a[i]!=0` assumes coefficient 0 marks end of first polynomial, but problem states only non-zero terms are input, and 0 coefficient won't appear. So this loop may run past valid data or never terminate as intended. Also, `a` contains both polynomials mixed, so this is fundamentally wrong.]
        for(j=0;b[j]!=0;j=j+2){ // @@ [Same issue: `b[j]!=0` is not a valid termination condition since input has no zero coefficients. Also, `b` may not be null-terminated, leading to reading garbage.]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; // @@ [Assumes `a[i+1]` and `b[j+1]` exist; may read beyond array bounds if `i` or `j` are at last index.]
            y++;
        }
    }
    int ber=(t-1)/2,k; // @@ [`t` is unreliable, so `ber` (number of terms in first polynomial?) is miscalculated.]
    ber=ber*(i-t+1)/2; // @@ [This attempts to compute total product terms but uses corrupted `i` and `t`, leading to wrong `ber`.]
    for( i=0;i<ber;i++){
        for( j=i+1;j<ber;){
            if(d[j]==d[i]&&i!=j){
                c[i]=c[j]+c[i];
                for (k=j;k<ber-1;k++) {
                    d[k]=d[k+1];
                    c[k]=c[k+1];
                }
                ber--; // @@ [After shifting, `j` is not incremented, but loop condition may skip checking new `d[j]` against `d[i]`, causing missed merges of like terms.]
            }
            else{
                j++;
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
        printf("%d %d ",c[i],d[i]);
    }
    return 0;
}
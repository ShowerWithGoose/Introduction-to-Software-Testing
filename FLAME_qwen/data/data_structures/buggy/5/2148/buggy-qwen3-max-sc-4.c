#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){ // @@ [This loop reads all input into a single array `a` without distinguishing between the two polynomials. It also does not stop at newline but only at EOF, which causes incorrect parsing when two lines are given.]
        if((i%2!=0)&&a[i]>a[i-2]){ // @@ [`a[i-2]` may access uninitialized memory when i==1 (first exponent), leading to undefined behavior. Also, logic for detecting polynomial boundary is flawed.]
            t=i;
        }
        i++;
    }
    if(t==1){ // @@ [This special case assumes only one term in first polynomial, but condition `t==1` is arbitrary and doesn't correctly identify single-term polynomials.]
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ [Assumes exactly 4 input values total; fails for general cases. Also accesses a[2], a[3] even if they don't exist.]
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){ // @@ [Incorrectly copies part of `a` into `b`; offset calculation `(i-t+1)` and starting index `t-1` are not based on valid parsing of second polynomial.]
        b[j]=a[j+t-1];
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ [Loop condition `a[i]!=0` assumes coefficients are non-zero and that zero marks end, but input may contain no zero and polynomials can have missing terms. Also, `a` was filled until EOF, so this may read beyond intended first polynomial.]
        for(j=0;b[j]!=0;j=j+2){ // @@ [Same issue: assumes `b` ends with zero, which it doesn't. Also, `b` was copied incorrectly above.]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; // @@ [If `i` or `j` reach last element, `a[i+1]` or `b[j+1]` may be out-of-bounds.]
            y++;
        }
    }
    int ber=(t-1)/2,k; // @@ [`t` was set based on flawed logic; `(t-1)/2` does not correctly compute number of terms in first polynomial.]
    ber=ber*(i-t+1)/2; // @@ [Expression uses `i` after previous loop modified it; value is unpredictable. Also, `(i-t+1)/2` is not valid term count for second polynomial.]
    for( i=0;i<ber;i++){
        for( j=i+1;j<ber;){ // @@ [Missing increment in inner loop when condition fails; may cause infinite loop. Also, removal logic shifts array but doesn't handle consecutive duplicates properly.]
            if(d[j]==d[i]&&i!=j){
                c[i]=c[j]+c[i];
                for (k=j;k<ber-1;k++) {
                    d[k]=d[k+1];
                    c[k]=c[k+1];
                }
                ber--;
            }
            else{
                j++; // @@ [Only increments `j` when no merge happens; but after merging, next element shifts to `j`, so should not increment to re-check. However, primary issue is overall logic complexity and fragility.]
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
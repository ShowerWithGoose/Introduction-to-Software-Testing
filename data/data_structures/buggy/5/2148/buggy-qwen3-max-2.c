#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){ // @@ [This loop reads all input into a single array `a` without distinguishing between the two polynomials. It also accesses `a[i-2]` when `i` may be less than 2, causing undefined behavior.]
        if((i%2!=0)&&a[i]>a[i-2]){ // @@ [When i==1, `a[i-2]` is `a[-1]`, which is out-of-bounds access and undefined behavior.]
            t=i;
        }
        i++;
    }
    if(t==1){ // @@ [This condition assumes a very specific input structure that does not generally hold; it only handles a trivial case incorrectly.]
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ [Accesses a[2] and a[3] even if input had fewer than 4 elements, leading to undefined behavior. Also logic is flawed: multiplying coefficients and adding exponents only works for single-term polynomials, but this branch doesn't ensure that.]
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){ // @@ [The expression `i-t+1` may result in a negative or incorrect size due to flawed logic in determining `t`. Also, copying from `a[j+t-1]` may read beyond valid input if `t` is not correctly set.]
        b[j]=a[j+t-1]; // @@ [If `t` is 0 (which can happen), then `j + t - 1` becomes `j - 1`, leading to reading from `a[-1]` on first iteration — undefined behavior.]
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ [This loop assumes that the first polynomial ends with a zero coefficient, but the problem states only non-zero terms are input. So `a[i]!=0` is not a valid termination condition and may run past actual input data.]
        for(j=0;b[j]!=0;j=j+2){ // @@ [Same issue: assumes second polynomial stored in `b` is terminated by a zero coefficient, which is not guaranteed by input format.]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; // @@ [If either loop runs too far due to incorrect termination, `a[i+1]` or `b[j+1]` may access uninitialized or out-of-bound memory.]
            y++;
        }
    }
    int ber=(t-1)/2,k; // @@ [`t` was set based on flawed comparison during input reading; `(t-1)/2` may be negative or meaningless.]
    ber=ber*(i-t+1)/2; // @@ [Uses invalid values of `t` and `i` to compute number of terms, likely resulting in wrong or negative `ber`.]
    for( i=0;i<ber;i++){ // @@ [If `ber` is negative or too large, this loop has undefined behavior.]
        for( j=i+1;j<ber;){ // @@ [Loop condition uses possibly invalid `ber`; inner logic shifts array elements but doesn't handle all duplicates correctly and may skip terms.]
            if(d[j]==d[i]&&i!=j){
                c[i]=c[j]+c[i];
                for (k=j;k<ber-1;k++) {
                    d[k]=d[k+1];
                    c[k]=c[k+1];
                }
                ber--;
            }
            else{
                j++;
            }
        }
    }
    for( i=0;i<ber-1;i++){ // @@ [If `ber <= 0`, this loop may have negative bound, but more critically, bubble sort implementation is applied only if previous steps produced correct `ber`, which they likely didn't.]
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
    for( i=0;i<ber;i++){ // @@ [Prints `ber` terms, but `ber` is computed incorrectly, and combined terms may still include zeros or unmerged duplicates. Also, output format requires descending exponents, but sorting may not have worked due to prior errors.]
        printf("%d %d ",c[i],d[i]);
    }
    return 0;
}
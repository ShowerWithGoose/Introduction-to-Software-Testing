#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){ // @@ The input format specifies two lines of input (two polynomials). Using scanf("%d") with EOF detection reads all integers from both lines into a single array 'a' without distinguishing between the two polynomials. This makes it impossible to correctly separate coefficients and exponents for polynomial A and B, leading to incorrect multiplication logic. Additionally, the problem states exponents can be up to INT_MAX, so adding them (e.g., 10^9 + 10^9) will cause integer overflow if 'int' is 32-bit, as seen in the wrong output (-589934592 instead of 2000000000).
        if((i%2!=0)&&a[i]>a[i-2]){
            t=i;
        }
        i++;
    }
    if(t==1){
        printf("%d %d",a[0]*a[1],a[2]+a[3]);
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){
        b[j]=a[j+t-1];
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ The loop condition a[i]!=0 is incorrect because coefficients can be non-zero but the loop relies on finding a zero coefficient to terminate, which is not guaranteed by the input format (input ends with newline/EOF, not necessarily a zero coefficient term). Also, since all input is in 'a', the separation logic for 'b' is flawed.
        for(j=0;b[j]!=0;j=j+2){ // @@ Similar error: relying on b[j]!=0 to terminate is incorrect. The size of polynomial B is not correctly determined due to the flawed input parsing.
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; // @@ Integer overflow occurs here when adding large exponents (e.g., 1000000000 + 1000000000 = 2000000000, which exceeds 2^31-1 if int is 32-bit signed, resulting in negative value). Should use long long for exponents or ensure int is 64-bit.
            y++;
        }
    }
    int ber=(t-1)/2,k;
    ber=ber*(i-t+1)/2;
    for( i=0;i<ber;i++){
        for( j=i+1;j<ber;){
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
        printf("%d %d ",c[i],d[i]); // @@ Prints terms even if coefficient is 0, which violates the requirement to only print non-zero terms. Also, if overflow occurred in exponent calculation, the printed exponent is wrong.
    }
    return 0;
}
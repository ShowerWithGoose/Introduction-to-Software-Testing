#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){
        if((i%2!=0)&&a[i]>a[i-2]){
            t=i;
        }
        i++;
    } // @@ [The logic to detect the end of the first polynomial is flawed. It assumes that exponents are increasing and uses a comparison with a[i-2], which fails when there's only one term or when input order isn't strictly increasing. Also, EOF detection doesn't account for newline separation as per problem spec.]
    if(t==1){
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ [This branch assumes exactly two terms total (one in each poly), but accesses a[2] and a[3] even if they don't exist. In the test case, there are only two numbers total (8 1000000000 for first poly, then 15 1000000000 for second), so a[2] and a[3] are uninitialized.]
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){
        b[j]=a[j+t-1];
    } // @@ [Incorrect splitting of input array 'a' into two polynomials. The index calculation (j+t-1) is arbitrary and doesn't correctly separate the two polynomials based on newline-delimited input.]
    for( i=0;a[i]!=0;i=i+2){ // @@ [Loop condition a[i]!=0 is unsafe: coefficients can be non-zero but the loop may run past valid input because 'a' wasn't null-terminated. Also, it assumes first polynomial starts at index 0 and ends before zeros, which isn't guaranteed.]
        for(j=0;b[j]!=0;j=j+2){ // @@ [Same issue: b[j]!=0 assumes zero marks end, but b was filled from a without guarantee of trailing zero. Also, multiplication logic uses wrong indices if splitting failed.]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; // @@ [Exponent addition is correct mathematically, but relies on correct parsing which has already failed.]
            y++;
        }
    }
    int ber=(t-1)/2,k;
    ber=ber*(i-t+1)/2; // @@ [ber calculation is based on incorrect assumptions about how many terms are in each polynomial due to faulty input parsing.]
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
                j++; // @@ [If terms are merged, j is not incremented properly in all cases, potentially causing infinite loop or missed merges. But more fundamentally, coefficient merging assumes all like terms are adjacent or will be caught, which isn't ensured without sorting first.]
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
    } // @@ [Sorting is done after merging, but merging was done on unsorted data, so like terms may not be adjacent and thus not merged correctly. This leads to missing combination of same-exponent terms.]
    for( i=0;i<ber;i++){
        printf("%d %d ",c[i],d[i]); // @@ [Does not skip zero-coefficient terms, though problem says only non-zero terms should be printed. However, in this test case, the main issue is incorrect parsing leading to wrong multiplication.]
    }
    return 0;
}
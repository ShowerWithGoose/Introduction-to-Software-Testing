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
    } // @@ [This loop assumes input ends with EOF, but problem states each polynomial ends with newline. Also, logic for detecting end of first polynomial is flawed and accesses a[-2] when i=1.]
    if(t==1){
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ [This assumes exactly two terms total (one per polynomial), but indices a[2], a[3] may be out of bounds if only two numbers were read. Also, multiplication logic is incorrect: should multiply coefficients and add exponents of corresponding terms, but here it multiplies coefficient by exponent.]
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){
        b[j]=a[j+t-1]; // @@ [Incorrectly copies from a[t-1], which may not be the start of second polynomial; also doesn't handle case where t wasn't set correctly.]
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ [Loop condition a[i]!=0 is wrong: coefficients can be non-zero but loop stops at any zero coefficient, and also reads beyond valid input if no zero exists.]
        for(j=0;b[j]!=0;j=j+2){ // @@ [Same issue: b[j]!=0 is invalid termination condition.]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; // @@ [Assumes a[i+1] and b[j+1] exist, but loop bounds are not checked properly.]
            y++;
        }
    }
    int ber=(t-1)/2,k;
    ber=ber*(i-t+1)/2; // @@ [ber calculation is based on flawed t and i values, leading to incorrect term count.]
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
                j++; // @@ [If merging terms, j is not incremented after shifting, but loop structure may skip terms or go out of bounds.]
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
        printf("%d %d ",c[i],d[i]); // @@ [Does not skip zero-coefficient terms as required by problem (though test case may not trigger this).]
    }
    return 0;
}
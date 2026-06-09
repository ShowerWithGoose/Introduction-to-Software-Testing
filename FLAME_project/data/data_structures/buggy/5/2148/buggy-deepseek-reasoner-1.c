#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){
        if((i%2!=0)&&a[i]>a[i-2]){ // @@ Error: Incorrect detection of polynomial boundary; fails for exponents equal or decreasing order.
            t=i;
        }
        i++;
    }
    if(t==1){ // @@ Error: This conditional expects t to be exactly 1, but boundary detection may not set t correctly, leading to missed handling of general case.
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ Error: This calculation only works for specific input where each polynomial has exactly one term? But even then, the exponents should be a[1] and a[3], adding them gives exponent, but for single-term polynomials, this would give correct result? For test case: a[0]=8, a[1]=1000000000, a[2]=15, a[3]=1000000000. a[0]*a[1] = 8*1000000000 = 8000000000? No, int overflow. Also a[2]+a[3] = 15+1000000000 = 1000000015, which matches the exponent in output. But coefficient overflow is wrong. So this line is erroneous due to overflow and wrong logic.
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){ // @@ Error: Loop range and indexing cause out-of-bounds access when t=0.
        b[j]=a[j+t-1]; // @@ Error: When t=0, accesses a[-1]; undefined behavior.
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ Error: Termination condition a[i]!=0 is unsafe; array may not contain zero terminator.
        for(j=0;b[j]!=0;j=j+2){ // @@ Error: Termination condition b[j]!=0 is unsafe; b not properly initialized.
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1];
            y++;
        }
    }
    int ber=(t-1)/2,k; // @@ Error: Calculation of ber is incorrect for boundary detection failure; leads to ber=0 when t=0.
    ber=ber*(i-t+1)/2; // @@ Error: Further incorrect; uses i that may be beyond valid data.
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
        printf("%d %d ",c[i],d[i]);
    }
    return 0;
}
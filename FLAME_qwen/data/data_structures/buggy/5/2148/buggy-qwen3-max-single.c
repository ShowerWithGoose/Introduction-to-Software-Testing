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
    }
    if(t==1){
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ [Accesses a[2] and a[3] without ensuring they exist; leads to undefined behavior if input has fewer than 4 elements]
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){
        b[j]=a[j+t-1]; // @@ [If t is 0 (e.g., when all exponents are non-increasing), t-1 becomes -1, leading to out-of-bounds access a[-1]]
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ [Relies on a[i] being zero to terminate loop, but input may not contain zero; also, uninitialized parts of a[] are indeterminate]
        for(j=0;b[j]!=0;j=j+2){ // @@ [Same issue: assumes b[j] will eventually be zero, which is not guaranteed]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; // @@ [May access beyond valid input if i+1 or j+1 exceeds actual number of input values]
            y++;
        }
    }
    int ber=(t-1)/2,k; // @@ [If t is 0 or 1, (t-1)/2 can be negative, leading to invalid array size logic later]
    ber=ber*(i-t+1)/2; // @@ [Uses potentially negative or incorrect ber value from previous line]
    for( i=0;i<ber;i++){ // @@ [If ber is negative or too large, this loop behaves incorrectly or accesses arrays out of bounds]
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
    for( i=0;i<ber-1;i++){ // @@ [If ber <= 0, this loop may run with negative upper bound, causing undefined behavior]
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
    for( i=0;i<ber;i++){ // @@ [If ber is negative or based on incorrect calculation, this prints garbage or nothing]
        printf("%d %d ",c[i],d[i]);
    }
    return 0;
}
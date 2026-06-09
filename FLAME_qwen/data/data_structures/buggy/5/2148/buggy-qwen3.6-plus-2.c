#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){
        if((i%2!=0)&&a[i]>a[i-2]){ // @@ Out-of-bounds access to a[-1] when i=1, and the condition incorrectly assumes the second polynomial's degree is greater than the first's to find the split point. It should detect the newline character instead.
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
    for( i=0;a[i]!=0;i=i+2){ // @@ Unsafe loop termination condition relying on uninitialized array values being zero; should be bounded by i < t to iterate only over the first polynomial's terms.
        for(j=0;b[j]!=0;j=j+2){ // @@ Unsafe loop termination condition relying on uninitialized array values; should be bounded by j < i - t to iterate only over the second polynomial's terms.
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1];
            y++;
        }
    }
    int ber=(t-1)/2,k;
    ber=ber*(i-t+1)/2; // @@ Incorrect calculation of the total number of product terms. The number of terms in the second polynomial is (i - t) / 2, so it should be ber * ((i - t) / 2).
    for( i=0;i<ber;i++){ // @@ Merging like terms before sorting the exponents in array d will fail to combine all duplicates correctly. Sorting should be done first, or a different merging strategy should be used.
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
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
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ This line incorrectly handles the case where there is only one term in each polynomial; it assumes the second polynomial starts at index 2, but the input format may vary, and it does not handle the general case of multiplication correctly.
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){
        b[j]=a[j+t-1];
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ This loop condition assumes that a[i] will be zero to terminate, but the input may contain zero coefficients or the array may not be zero-terminated, leading to incorrect iteration.
        for(j=0;b[j]!=0;j=j+2){ // @@ Same issue as above; b[j] may not be zero-terminated, causing the loop to go out of bounds or miss terms.
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1];
            y++;
        }
    }
    int ber=(t-1)/2,k;
    ber=ber*(i-t+1)/2; // @@ This calculation of ber is incorrect; it does not correctly compute the number of terms in the product, leading to incorrect array sizes and potential out-of-bounds access.
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
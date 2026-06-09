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
        printf("%d %d",a[0]*a[1],a[2]+a[3]);
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){
        b[j]=a[j+t-1];
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ The loop condition `a[i]!=0` assumes the input ends with a zero coefficient, but the input only contains non-zero terms and ends with a newline, not a zero. This may cause incorrect iteration or out-of-bounds access.
        for(j=0;b[j]!=0;j=j+2){ // @@ Same issue as above: assumes b ends with zero, but input does not guarantee a zero term.
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1];
            y++;
        }
    }
    int ber=(t-1)/2,k;
    ber=ber*(i-t+1)/2; // @@ The calculation of `ber` is incorrect. It attempts to compute the number of product terms but uses uninitialized or incorrect values of `i` and `t`, leading to wrong array sizes and potential out-of-bounds access.
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
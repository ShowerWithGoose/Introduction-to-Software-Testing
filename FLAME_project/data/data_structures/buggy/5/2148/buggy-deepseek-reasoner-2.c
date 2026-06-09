#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){
        if((i%2!=0)&&a[i]>a[i-2]){ // @@ error: Out-of-bounds array access when i=1 (a[-1]); incorrect logic for separating polynomials.
            t=i;
        }
        i++;
    }
    if(t==1){ // @@ error: Condition based on flawed detection; does not handle general input.
        printf("%d %d",a[0]*a[1],a[2]+a[3]); // @@ error: Multiplies coefficient with exponent instead of coefficient with coefficient; adds exponent and coefficient instead of exponents.
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){ // @@ error: Incorrect loop bounds; i and t are not correctly computed, causing wrong data copy.
        b[j]=a[j+t-1];
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ error: Uses a[i]!=0 as termination condition; no guarantee of 0 in array; loops over both polynomials mixed.
        for(j=0;b[j]!=0;j=j+2){ // @@ error: Same issue with b array; no 0 terminator.
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1];
            y++;
        }
    }
    int ber=(t-1)/2,k; // @@ error: Incorrect calculation of number of product terms based on incorrect t.
    ber=ber*(i-t+1)/2; // @@ error: Incorrect multiplication; i and t are not the intended counts.
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
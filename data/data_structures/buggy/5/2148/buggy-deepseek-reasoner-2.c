#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){
        if((i%2!=0)&&a[i]>a[i-2]){   // @@ Error: When i=1, a[i-2] accesses a[-1] which is out of bounds.
            t=i;
        }
        i++;
    }
    if(t==1){
        printf("%d %d",a[0]*a[1],a[2]+a[3]);   // @@ Error: This special case only handles two single-term polynomials; does not cover general case.
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){
        b[j]=a[j+t-1];   // @@ Error: If t is not set (remains 0), then a[t-1] is a[-1] which is out of bounds.
    }
    for( i=0;a[i]!=0;i=i+2){   // @@ Error: a[i] will never be 0 because input has no zero terms, causing out-of-bounds access. Should use number of terms instead.
        for(j=0;b[j]!=0;j=j+2){   // @@ Error: Same issue with b[j] never being 0.
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1];
            y++;
        }
    }
    int ber=(t-1)/2,k;
    ber=ber*(i-t+1)/2;   // @@ Error: i has been modified in the previous for loop, so it no longer represents the total number of integers. Also integer division may truncate incorrectly.
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
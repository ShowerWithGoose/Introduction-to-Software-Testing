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
        b[j]=a[j+t-1]; // @@ [If t is 0 (which can happen), this accesses a[-1], causing undefined behavior]
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ [Assumes input ends with a zero coefficient, which is not guaranteed by the problem; may read uninitialized memory or loop indefinitely]
        for(j=0;b[j]!=0;j=j+2){ // @@ [Same issue: assumes b ends with zero, but b was filled from a without null termination]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; // @@ [May access a[i+1] or b[j+1] beyond valid input if i or j are at the last element]
            y++;
        }
    }
    int ber=(t-1)/2,k;
    ber=ber*(i-t+1)/2; // @@ [Uses uninitialized or incorrect values of t and i; logic for computing number of terms is flawed]
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
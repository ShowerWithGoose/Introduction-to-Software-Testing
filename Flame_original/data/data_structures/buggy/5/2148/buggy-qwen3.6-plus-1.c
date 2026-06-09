#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){ // @@ scanf skips whitespace including newlines, so it reads both polynomials into array a continuously without stopping at the newline as required by the input format.
        if((i%2!=0)&&a[i]>a[i-2]){ // @@ The condition to detect the boundary between two polynomials is logically flawed; exponents are not guaranteed to satisfy this inequality, and the newline has already been consumed.
            t=i;
        }
        i++;
    }
    if(t==1){ // @@ Accessing a[2] and a[3] without bounds checking or initialization leads to undefined behavior; the logic for handling single-term polynomials is incorrect.
        printf("%d %d",a[0]*a[1],a[2]+a[3]);
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){ // @@ The starting index for copying the second polynomial is incorrect due to the flawed calculation of t, and may cause out-of-bounds access or incorrect data copying.
        b[j]=a[j+t-1];
    }
    for( i=0;a[i]!=0;i=i+2){ // @@ Array a is not initialized to 0, so checking a[i]!=0 may read garbage values or cause out-of-bounds access; it should use the actual term count instead.
        for(j=0;b[j]!=0;j=j+2){ // @@ Array b is not initialized to 0, leading to potential out-of-bounds access or reading garbage values during iteration.
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1];
            y++;
        }
    }
    int ber=(t-1)/2,k; // @@ The calculation of the number of terms in the first polynomial is incorrect due to off-by-one errors and reliance on the flawed index t.
    ber=ber*(i-t+1)/2; // @@ The total number of product terms is miscalculated because i and t do not correctly represent the term counts of the two polynomials.
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
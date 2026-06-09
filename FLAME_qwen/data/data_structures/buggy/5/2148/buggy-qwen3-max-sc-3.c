#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){ @@ [This loop reads all input into a single array `a` without distinguishing between the two polynomials. It assumes EOF ends the first polynomial, but the problem states that each polynomial ends with a newline, not EOF. This causes incorrect parsing when both polynomials are on separate lines.]
        if((i%2!=0)&&a[i]>a[i-2]){ @@ [This condition attempts to find the start of the second polynomial by comparing exponents, which is logically flawed. Polynomial terms may not be input in strictly descending order, and this check doesn't reliably detect line breaks.]
            t=i;
        }
        i++;
    }
    if(t==1){ @@ [This special case assumes only two terms total (one per polynomial), which is not general. Also, `a[2]` and `a[3]` may be out of bounds if input has fewer than 4 elements.]
        printf("%d %d",a[0]*a[1],a[2]+a[3]);
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){ @@ [The calculation `i-t+1` is incorrect for determining the size of the second polynomial. Moreover, if `t` was never set correctly (e.g., due to wrong exponent ordering), this copies from a wrong offset.]
        b[j]=a[j+t-1];
    }
    for( i=0;a[i]!=0;i=i+2){ @@ [This loop assumes the first polynomial ends with a zero coefficient (`a[i]!=0`), but the problem states only non-zero terms are input. There is no guarantee that `a[i]` will ever be zero; it may read beyond valid data.]
        for(j=0;b[j]!=0;j=j+2){ @@ [Same issue: assumes `b[j]` becomes zero to terminate, but `b` was filled from `a` which contains no zero coefficients. This leads to reading uninitialized or garbage values.]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; @@ [If `i+1` or `j+1` exceeds actual input size, this accesses out-of-bounds memory. No validation of array bounds.]
            y++;
        }
    }
    int ber=(t-1)/2,k; @@ [`t` may be 0 (if no "increasing exponent" found), leading to negative `ber`. Also, `(t-1)/2` is not the correct count of terms in first polynomial.]
    ber=ber*(i-t+1)/2; @@ [This formula for total product terms is based on incorrect assumptions about `t`, `i`, and polynomial sizes. May result in negative or too-large `ber`.]
    for( i=0;i<ber;i++){
        for( j=i+1;j<ber;){ @@ [Missing increment of `j` in some paths can cause infinite loop. Specifically, when `d[j]==d[i]`, `j` is not incremented after shifting elements, but `ber` decreases—this may skip elements or loop indefinitely.]
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
    for( i=0;i<ber-1;i++){ @@ [If `ber` is 0 or 1, this loop may not run or access `d[ber]` out of bounds in comparisons. Also, bubble sort implementation is inefficient but not necessarily wrong—if `ber` is computed correctly.]
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
    for( i=0;i<ber;i++){ @@ [If `ber` is negative or larger than actual number of valid terms, this prints garbage or nothing. Also, if all coefficients cancel out (sum to zero), zero-coefficient terms should be omitted—but this code doesn't check for zero coefficients before printing.]
        printf("%d %d ",c[i],d[i]);
    }
    return 0;
}
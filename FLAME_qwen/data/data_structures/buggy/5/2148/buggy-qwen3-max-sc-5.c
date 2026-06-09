#include<stdio.h>
int main(){
    int a[10000];
    int b[10000];
    int c[10000]={0};
    int d[10000]={0};
    int x=0,y=0,hold,i=0,t=0,H,j;
    while(scanf("%d",&a[i])!=EOF){ @@ [This loop reads all input into a single array `a` without distinguishing between the two polynomials. It assumes EOF ends the first polynomial, but the problem states each polynomial ends with a newline, not EOF. This causes incorrect parsing when both polynomials are on separate lines.]
        if((i%2!=0)&&a[i]>a[i-2]){ @@ [Accesses `a[i-2]` when `i` could be 1, leading to out-of-bounds read (e.g., `a[-1]`) on the first exponent. Also, logic for detecting polynomial boundary is flawed.]
            t=i;
        }
        i++;
    }
    if(t==1){ @@ [Assumes a very specific case (only one term in first poly?) and outputs based on fixed indices, which doesn't generalize. Also, if `t` was never set correctly due to earlier error, this condition may trigger incorrectly.]
        printf("%d %d",a[0]*a[1],a[2]+a[3]); @@ [Accesses `a[2]` and `a[3]` which may be beyond actual input if first polynomial has only one term (2 numbers), causing undefined behavior.]
    }
    //t-1,i;
    for( j=0;j<(i-t+1);j++){ @@ [If `t` is 0 (not set), this becomes `j < i+1`, potentially copying beyond valid data. Also, `b` is intended to hold second polynomial, but copying starts at `a[t-1]` which may be invalid if `t==0`.]
        b[j]=a[j+t-1]; @@ [When `t==0`, accesses `a[j-1]` → negative index → undefined behavior.]
    }
    for( i=0;a[i]!=0;i=i+2){ @@ [Assumes first polynomial ends with a zero coefficient, but problem states only non-zero terms are input. So `a[i]` may never be zero, leading to out-of-bounds access. Also, `i` was already used as total count; reusing it here corrupts logic.]
        for(j=0;b[j]!=0;j=j+2){ @@ [Same issue: assumes `b` ends with zero, which it doesn't. Also, `b` may contain uninitialized values beyond copied data, so `b[j]!=0` is unreliable.]
            c[x]=a[i]*b[j];
            x++;
            d[y]=a[i+1]+b[j+1]; @@ [If `i+1` or `j+1` exceeds actual input size, reads garbage. No bounds checking.]
            y++;
        }
    }
    int ber=(t-1)/2,k; @@ [If `t==0`, `(t-1)/2` is negative → `ber` negative. Then used as loop bound → undefined behavior.]
    ber=ber*(i-t+1)/2; @@ [Uses `i` after previous loop which may have gone out of bounds; also, if `ber` was negative, remains problematic.]
    for( i=0;i<ber;i++){ @@ [If `ber <= 0`, loop doesn't run, but if `ber` is based on wrong counts, merging terms fails. Also, reuses `i` again without reset, though previous loop may have left `i` large.]
        for( j=i+1;j<ber;){ @@ [Inner loop may skip terms or go out of bounds if `ber` is incorrect. Also, deletion logic shifts array but doesn't adjust outer loop, possibly missing merges.]
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
    for( i=0;i<ber-1;i++){ @@ [If `ber <= 1`, loop doesn't run. But if `ber` is wrong due to earlier errors, sorting may be incomplete. Also, bubble sort implementation is inefficient but logically okay if `ber` correct.]
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
    for( i=0;i<ber;i++){ @@ [If `ber` is negative or too large due to miscalculation, this prints garbage or crashes. Also, if no terms survive merging (e.g., all cancel), should output nothing, but may print uninitialized data.]
        printf("%d %d ",c[i],d[i]);
    }
    return 0;
}
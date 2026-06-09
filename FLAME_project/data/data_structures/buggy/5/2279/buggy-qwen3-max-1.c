#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int cs1[200],cs2[200],xs1[200],xs2[200],cs[300],xs[300];
char c1[200],c2[200],c3[200],c4[200];

void bubble(int *a,int *b,int n){
    int s1,s2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){ // @@ [The inner loop condition should be `j < n - i - 1` to avoid out-of-bounds access when comparing `*(a+j)` and `*(a+j+1)`. The current condition `j < n - i` leads to reading beyond array bounds.]
            if(*(a+j)<*(a+j+1)){
                s1=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=s1;
                s2=*(b+j);
                *(b+j)=*(b+j+1);
                *(b+j+1)=s2;
            }
        }
    }
}

int main(){
    int i1=0,i2=0,o=0;
    while(scanf("%d%c%d%c",&xs1[i1],&c1[i1],&cs1[i1],&c2[i1])!=EOF){
        if(c2[i1]=='\n'){
            break;
        }
        i1++;
    }
    while(scanf("%d%c%d%c",&xs2[i2],&c3[i2],&cs2[i2],&c4[i2])!=EOF){
        if(c4[i2]=='\n'){   
            break;
        }
        i2++;
    }
    for(int i=0;i<=i1;i++){ // @@ [Loop should run from `i = 0` to `i < i1`, not `i <= i1`, because `i1` is the count of terms, and valid indices are `0` to `i1 - 1`. Same issue in the inner loop with `j <= i2`.]
        for(int j=0;j<=i2;j++){ // @@ [Same as above: should be `j < i2` instead of `j <= i2` to avoid accessing uninitialized or out-of-bound elements.]
            cs[o]=cs1[i]+cs2[j];
            xs[o]=xs1[i]*xs2[j];
            o++;
        }
    }
    bubble(cs,xs,o);
    int cishu=0,xishu=0;
    for(int i=0;i<o;i++){
        if(cs[i]==cs[i+1]){ // @@ [When `i == o - 1`, `cs[i+1]` accesses out-of-bounds memory. Also, the logic for combining like terms is flawed—it doesn't correctly accumulate all same-degree terms and skips some terms during merging.]
            for(int j=i;j<o;j++){
                if(cs[j]!=cs[i]){
                    i=j;
                    break;
                }
                else{
                    cishu=cs[j];
                    xishu+=xs[j];
                }
            }
        }
        else{
            cishu=cs[i];
            xishu=xs[i];
        }
        printf("%d %d ",xishu,cishu);
        xishu=0;
        cishu=0;
    }
    return 0;
}
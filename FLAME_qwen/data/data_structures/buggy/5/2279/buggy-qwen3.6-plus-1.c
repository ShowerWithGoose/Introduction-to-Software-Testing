#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int cs1[200],cs2[200],xs1[200],xs2[200],cs[300],xs[300];
char c1[200],c2[200],c3[200],c4[200];

void bubble(int *a,int *b,int n){
    int s1,s2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){ // @@ [Array index out of bounds: when j=n-i-1, a[j+1] accesses a[n-i], which is out of bounds. The loop condition should be j < n-i-1.]
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
    for(int i=0;i<=i1;i++){ // @@ [Off-by-one error: i1 is the count of terms, valid indices are 0 to i1-1. Using <= accesses uninitialized memory.]
        for(int j=0;j<=i2;j++){ // @@ [Off-by-one error: i2 is the count of terms, valid indices are 0 to i2-1. Using <= accesses uninitialized memory.]
            cs[o]=cs1[i]+cs2[j];
            xs[o]=xs1[i]*xs2[j];
            o++;
        }
    }
    bubble(cs,xs,o);
    int cishu=0,xishu=0;
    for(int i=0;i<o;i++){
        if(cs[i]==cs[i+1]){ // @@ [Array index out of bounds: when i=o-1, cs[i+1] accesses cs[o]. Also, the term merging logic is flawed and may produce incorrect results or skip terms.]
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
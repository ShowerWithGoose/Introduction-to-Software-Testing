#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


int xs[2][200],xm[200],ys[200],ym[200];





int main(){
    int n,o=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){ // @@ C89/C90 standard does not allow declaring loop variables inside the for statement; declare 'i' at the beginning of main.
        scanf("%d%d%d%d",&xs[0][i],&ys[i],&xm[i],&ym[i]);
    }
    for(int i=0;i<n;i++){ // @@ C89/C90 standard does not allow declaring loop variables inside the for statement.
        for(int j=0;j<n;j++){ // @@ C89/C90 standard does not allow declaring loop variables inside the for statement.
            if(xs[0][i]==xm[j]&&ys[i]==ym[j]){
                o=1;
            }
        }
        if(o==0){
            xs[1][i]=1;
        }
        o=0;
    }
    int i=0,p=0; // @@ C89/C90 standard requires all variable declarations to precede executable statements within a block.
    while(i<n){
        if(xs[1][i]>0){
            for(int j=0;j<n;j++){ // @@ C89/C90 standard does not allow declaring loop variables inside the for statement.
                if(xs[0][j]==xm[i]&&ys[j]==ym[i]){
                    xm[i]=xm[j];
                    ym[i]=ym[j];
                    xs[1][i]++;
                    p=1;
                }
            }
            if(p==0){
                i++;
            }
            else{
                p=0;
            }
        }
        else{
            i++;
        }
    }
    for(int j=0;j<n;j++){ // @@ C89/C90 standard does not allow declaring loop variables inside the for statement.
        printf("%d %d\n",xs[1][j],xs[0][j]);
    }
    int max=0,imax=0; // @@ C89/C90 standard requires all variable declarations to precede executable statements within a block.
    for(int j=0;j<n;j++){ // @@ C89/C90 standard does not allow declaring loop variables inside the for statement.
        if(max<xs[1][j]){
            imax=j;
            max=xs[1][j];
        }            
    }
    printf("%d %d %d",max,xs[0][imax],ys[imax]);
    return 0;
}
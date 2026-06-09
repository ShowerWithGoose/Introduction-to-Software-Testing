#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define LL long long
#define ULL unsigned LL
#define UI unsigned int 
#define GC getchar()
#define PC putchar
#define F(i,l,r) for(int i=(l);i<(r);i++)
#define FD(i,l,r) for(int i=(l);i<=(r);i++)
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)

int N,a[11]={0},v[11]={0};
void pn(int n){
    if(n>N){
        for(int i=1;i<=N;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(int j=1;j<=N;j++){
        if(!v[j]){
            v[j]=1;
            a[n]=j;
            pn[n+1]; // @@ [Error: This is a function call syntax error. It should be "pn(n+1);" with parentheses, not square brackets. Square brackets are for array indexing, not function calls.]
            v[j]=0;
        }
    }
    
}
int main(){
    
    scanf("%d",&N);
    pn(1);
    return 0;
    
}
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long
#define For(a, b, c) for (int a = b; a < c;a++)
#define FOR(a, b, c) for (int a = c - 1; a >= b;a--)
#define ull unsigned long long
#define MAXN 1000000
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define swap(a,b)   do{a^=b;b^=a;a^=b;}while(0)
int A[20000];
void print(int n, int *a,int bound){
    if(bound==n){
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    else for(int i=1;i<=n;i++){
        int k=1;
        for(int j=0;j<bound;j++)
        if(a[j]==i) k=0;
        if(k){
            a[bound]=i;
            print(n,a,bound+1);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    print(n,A,0);
}

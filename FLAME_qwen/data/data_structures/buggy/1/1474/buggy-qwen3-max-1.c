#include<stdio.h>
int n;
int ma[10]={0}; // @@ [Array size is too small; for N=10, indices 1..10 are used, but array has only 10 elements (0..9), causing out-of-bounds access]
char s[11];
void math(int g);
int main(){
    scanf("%d",&n);
    math(0);
    return 0;
}
void math(int g){
    int i;
    if(g==n)
    {
        s[g]='\0';
        puts(s); // @@ [Output format is incorrect: uses puts() which prints a newline, but problem requires space-separated integers on each line without extra spaces or newlines from puts()]
        return;
    }
    for(i=1;i<=n;i++){
        if(ma[i]==0){
            ma[i]=1;
            s[g]='0'+i;
            math(g+1);
            ma[i]=0;

        }
    }
}
#include<stdio.h>
int n;
int ma[10]={0}; // @@ array size insufficient for N=10; should be int ma[11]={0}; otherwise ma[10] is out of bounds when i=10.
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
        puts(s); // @@ incorrect output format; should print each integer separated by a space, not a concatenated string without spaces.
        return;
    }
    for(i=1;i<=n;i++){
        if(ma[i]==0){
            ma[i]=1;
            s[g]='0'+i; // @@ for i >= 10, '0'+i does not produce the correct multi‑digit representation; should handle numbers up to 10.
            math(g+1);
            ma[i]=0;

        }
    }
}
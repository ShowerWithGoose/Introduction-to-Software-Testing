#include<stdio.h>
int n;
int ma[10]={0}; // @@ Array size should be at least 11 to safely access index 10 when N=10, otherwise it causes out-of-bounds access.
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
        puts(s); // @@ This prints the characters concatenated without spaces. The output format requires each integer to be separated by a space. Additionally, storing '0'+i as char fails for i=10.
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
#include<stdio.h>
int n;
int ma[10]={0};
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
        puts(s); // @@ [The output format requires space-separated integers and a newline, but puts() outputs the string as-is followed by a newline. Since s contains concatenated digits (e.g., '123'), it prints "123\n" instead of "1 2 3\n".]
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
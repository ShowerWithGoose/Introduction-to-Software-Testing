#include<stdio.h>
int n;
int ma[10]={0}; // @@ Array size too small; when n=10, index 10 is out of bounds. Should be size at least 11.
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
        puts(s); // @@ Output format error: prints permutation as a string without spaces; each integer should be separated by a space.
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
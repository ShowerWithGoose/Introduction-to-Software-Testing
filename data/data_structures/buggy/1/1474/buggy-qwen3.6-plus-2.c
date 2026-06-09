#include<stdio.h>
int n;
int ma[10]={0}; // @@ Array size is 10, but indices 1 to N are accessed. When N=10, ma[10] causes out-of-bounds access. Should be ma[11].
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
        puts(s); // @@ Output format requires space-separated integers. puts prints the string without spaces. Should iterate and print each char with a space.
        return;
    }
    for(i=1;i<=n;i++){
        if(ma[i]==0){
            ma[i]=1;
            s[g]='0'+i; // @@ Only works for single digits (1-9). If N=10, '0'+10 yields ':', which is incorrect for integer output.
            math(g+1);
            ma[i]=0;

        }
    }
}
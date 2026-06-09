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
        puts(s); // @@ [The output format requires space-separated integers, but puts() outputs the string as-is without spaces between digits. Also, for N>9, '0'+i produces non-digit characters, but since N<=10, i=10 leads to '0'+10 which is ':', not "10". This causes incorrect output for N=10 and wrong formatting (no spaces) for all cases.]
        return;
    }
    for(i=1;i<=n;i++){
        if(ma[i]==0){
            ma[i]=1;
            s[g]='0'+i; // @@ [For i=10, '0'+10 results in character ':', not the string "10". Since N can be up to 10, this fails to represent 10 correctly as two characters. Additionally, storing multi-digit numbers as single chars is invalid.]
            math(g+1);
            ma[i]=0;

        }
    }
}
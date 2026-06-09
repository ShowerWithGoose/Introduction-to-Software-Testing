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
        puts(s); // @@ [The output format is incorrect: it prints digits concatenated without spaces. The problem requires each integer in a permutation to be separated by a space.]
        return;
    }
    for(i=1;i<=n;i++){
        if(ma[i]==0){
            ma[i]=1;
            s[g]='0'+i; // @@ [This stores only the digit character of the number, which works for N<=9 but fails to produce space-separated output. Also, for N=10, '0'+10 is not a valid single digit, but since N<=10 and the array s is char, this would break for N=10. However, the immediate issue for N=2 is lack of spaces.]
            math(g+1);
            ma[i]=0;

        }
    }
}
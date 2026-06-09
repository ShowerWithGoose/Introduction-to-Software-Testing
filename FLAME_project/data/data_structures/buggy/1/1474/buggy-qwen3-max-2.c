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
        puts(s); // @@ [The output format is incorrect: it prints digits without spaces between them, e.g., "12" instead of "1 2". The problem requires each integer in a line to be separated by a space.]
        return;
    }
    for(i=1;i<=n;i++){
        if(ma[i]==0){
            ma[i]=1;
            s[g]='0'+i; // @@ [This stores only the digit character (e.g., '1', '2') into the string, but does not account for spacing. Even if spaces were added, this approach cannot handle numbers >9 (though N<=10, so 10 would break it). However, since N<=10 and includes 10, storing '0'+10 gives ':', which is wrong. But more critically for N=2, it produces "12" instead of "1 2".]
            math(g+1);
            ma[i]=0;

        }
    }
}
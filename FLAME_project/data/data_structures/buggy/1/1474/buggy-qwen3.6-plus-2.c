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
        puts(s); // @@ The output format is incorrect. The problem requires integers separated by spaces (e.g., "1 2"), but this code outputs characters without spaces (e.g., "12"). Additionally, for N > 9, '0' + i will not produce the correct character representation for two-digit numbers, though the constraint is N <= 10. The main issue here is the missing spaces between numbers.
        return;
    }
    for(i=1;i<=n;i++){
        if(ma[i]==0){
            ma[i]=1;
            s[g]='0'+i; // @@ This logic assumes single-digit numbers can be directly converted to characters and stored in a char array for string output. While valid for N<=9, it fails to handle the spacing requirement. For N=10, '0'+10 is not a valid digit character. The approach of building a string of characters is fundamentally flawed for the required output format "1 2 ... 10".
            math(g+1);
            ma[i]=0;

        }
    }
}
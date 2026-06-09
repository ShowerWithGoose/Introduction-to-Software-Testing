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
        puts(s); // @@ [The output format requires space-separated integers and a newline, but puts() outputs the string as-is without spaces between digits and adds a newline. Since each character in s is a digit character (e.g., '1', '2'), multi-digit numbers aren't possible here, but the problem expects space separation. Also, for N=10, '0'+10 gives ':', which is incorrect. However, the primary visible error for small N (like N=2) is missing spaces between numbers.]
        return;
    }
    for(i=1;i<=n;i++){
        if(ma[i]==0){
            ma[i]=1;
            s[g]='0'+i; // @@ [When i is 10, '0'+10 results in ':' (ASCII 58), not "10". This fails for N>=10 because it tries to represent two-digit numbers as single characters. The array s stores characters, so it cannot correctly hold two-digit numbers like 10. This causes incorrect output for N=10. Additionally, even for N<10, the output lacks spaces between digits because the entire permutation is printed as a contiguous string via puts().]
            math(g+1);
            ma[i]=0;

        }
    }
}
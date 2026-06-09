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
        puts(s); // @@ [The output format requires space-separated integers and a newline, but puts() outputs the string as-is without spaces between digits and appends a newline. Since each character in s is a digit character (e.g., '1', '2'), multi-digit numbers are not possible here, but the problem expects space separation between numbers. However, more critically, when N > 9, '0'+i would exceed single digit, but N<=10 so i=10 causes '0'+10 = ':' which is wrong. But since N<=10, i=10 is possible and '0'+10 is not '10' but a single char ':'. This leads to incorrect output for N=10. However, the immediate error causing mismatched output format is lack of spaces. But note: the reference program prints with spaces and newline. Here, puts(s) prints the string of digits (each a char) with no spaces, e.g., "12" instead of "1 2".]
        return;
    }
    for(i=1;i<=n;i++){
        if(ma[i]==0){
            ma[i]=1;
            s[g]='0'+i; // @@ [When i is 10, '0'+10 results in the character ':', not the string "10". Since N can be up to 10, this fails to represent 10 correctly as two characters. The array s is treated as a string of single-byte characters, so it cannot hold two-digit numbers. This causes incorrect output for N=10. Also, even for N<=9, the output lacks spaces between numbers because each position in s holds one digit character, and puts() prints them consecutively.]
            math(g+1);
            ma[i]=0;

        }
    }
}
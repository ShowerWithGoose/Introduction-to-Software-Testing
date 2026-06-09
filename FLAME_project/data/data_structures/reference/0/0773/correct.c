#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long
#define For(a, b, c) for (int a = b; a < c;a++)
#define FOR(a, b, c) for (int a = c - 1; a >= b;a--)
#define ull unsigned long long
#define MAXN 1000000
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
char str[MAXN];
int main()
{
    gets(str);
    for(int i=0,len=strlen(str);i<len;i++){
        if(str[i]=='-'&&i!=0){
            if(islower(str[i-1])&islower(str[i+1])&&str[i+1]>str[i-1]){
                for(int j=str[i-1]+1;j<str[i+1];j++)
                printf("%c",j);
                continue;
            }
            else if(isupper(str[i-1])&&isupper(str[i+1])&&str[i+1]>str[i-1]){
                for(int j=str[i-1]+1;j<str[i+1];j++)
                printf("%c",j);
                continue;
            }
            else if(isdigit(str[i-1])&&isdigit(str[i+1])&&str[i+1]>str[i-1]){
                for(int j=str[i-1]+1;j<str[i+1];j++)
                printf("%c",j);
                continue;
            }
        }
        printf("%c",str[i]);
    }
    return 0;
}

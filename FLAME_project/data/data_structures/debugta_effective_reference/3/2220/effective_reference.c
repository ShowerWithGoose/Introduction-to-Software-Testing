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
char str[20000];
int b[20000],sum=0,flag,s2[20000];
char ch[20000];
int num1=0,i=0,m;
int main()
{
    gets(str);

    int len=strlen(str);
    flag=0;
    for(int a=0;a<len;a++){
        if(str[a]=='0') continue;
        else if(str[a]=='.') m=a-1;
        else {
            if(i) continue;
            i=a+1;
            if(str[0]=='0'){
            i=a-1;
            flag=1;
            }
        }
    }
    if(flag){
        if(i>=len-3)
        printf("%c",str[i+1]);
        else printf("%c.",str[i+1]);
        for(int a=i+2;a<len;a++) printf("%c",str[a]);
        printf("e-%d",abs(i-m));
    }
    else{
        printf("%c.",str[i-1]);
        for(int a=i;a<len;a++){
            if(str[a]!='.') printf("%c",str[a]);
        }
        printf("e%d",abs(i-m-1));
    }
    
}

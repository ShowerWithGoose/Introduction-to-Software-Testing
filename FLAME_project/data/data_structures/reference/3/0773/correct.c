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
int k[20000],sum=0,flag,s2[20000];
char ch[20000];
int num1=0,num2=0,spot;
int main()
{
    gets(str);

    int len=strlen(str);
    flag=0;
    for(int i=0;i<len;i++){
        if(str[i]=='0') continue;
        else if(str[i]=='.') spot=i-1;
        else {
            if(num2) continue;
            num2=i+1;
            if(str[0]=='0'){
            num2=i-1;
            flag=1;
            }
        }
    }
    if(flag){
        if(num2>=len-3)
        printf("%c",str[num2+1]);
        else printf("%c.",str[num2+1]);
        for(int i=num2+2;i<len;i++) printf("%c",str[i]);
        printf("e-%d",abs(num2-spot));
    }
    else{
        printf("%c.",str[num2-1]);
        for(int i=num2;i<len;i++){
            if(str[i]!='.') printf("%c",str[i]);
        }
        printf("e%d",abs(num2-spot-1));
    }
    
}

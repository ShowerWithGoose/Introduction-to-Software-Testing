#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
int n,m;
char s[205];

int max(int a,int b){return a>=b ? a : b ;}
int min(int a,int b){return a<=b ? a : b ;}

int main(){
    scanf("%s",s);
    n=strlen(s);
    int i,j;
    for(i=0;i<n;i++){
        if(s[i]=='-'){
            if('0'<=s[i-1]&&s[i+1]<='9'&&s[i+1]>s[i-1])
              {for(j=s[i-1]+1;j<s[i+1];j++) putchar(j);continue;}
            if((('a'<=s[i-1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i+1]<='Z'))&&s[i+1]>s[i-1])
              {for(j=s[i-1]+1;j<s[i+1];j++) putchar(j);continue;}
        }
        putchar(s[i]);
    }
    return 0;
}

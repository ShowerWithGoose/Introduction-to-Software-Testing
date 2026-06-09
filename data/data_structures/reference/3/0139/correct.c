#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
#define maxn 105
int n,pos;
char s[maxn];

int max(int a,int b){return a>=b ? a : b ;}
int min(int a,int b){return a<=b ? a : b ;}

int main(){
    /*double st=clock();*/
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
     if(s[i]=='.') {pos=i;break;}
    if(pos==1&&s[0]=='0'){
        int i,pos1;
        for(i=pos+1;i<n&&s[i]=='0';i++) ;
        printf("%c",s[i]);
        pos1=i;
        if(i!=n-1){
            putchar('.');
            for(i=i+1;i<n;i++) putchar(s[i]);
        }
        putchar('e'),putchar('-');
        printf("%d",pos1-pos);
    }
    else {
        int i;
        putchar(s[0]),putchar('.');
        for(i=1;i<n;i++)
         if(s[i]!='.') putchar(s[i]);
        putchar('e');
        printf("%d",pos-1);
    }
    /*double ed=clock();
    printf("Time:%lf ms",ed-st);*/
    return 0;
}

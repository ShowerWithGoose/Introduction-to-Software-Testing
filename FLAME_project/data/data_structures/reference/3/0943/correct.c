#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define max 1e6
typedef long long ll;
char s[1000000];
int read();
int amount(char s[]){//计算位数
    int n=0;
    while(s[n]!='.'&&s[n]!='\0'){//处理点前面的0
        n++;
        if(s[1]=='.'&&s[0]=='0'){
            n=2;
            while(s[n]=='0'){
                n++;
            }
            return -(n-1);
        }
    } 
    return n-1;
}
int judge(char s[]){//判断小数还是整数
    int i=0;
    while(s[i++]!='\0'){
        if(s[i]=='.'){
            return 1;
        }
    }
    return 0;
}
void outputz(){//整数输出
    int len1=strlen(s)-1;
    int len=len1;
    while(s[len]=='0'){
        len--;
    }
    if(len==0){
        printf("%c",s[0]);
    } else{
        int i=1;
        printf("%c.",s[0]);
        while(i<=len){
            printf("%c",s[i]);
            i++;
        }
    }
}
void outputs(char s[]){//小数输出
    if(s[0]=='0'&&s[1]=='.'){
        int i=2;
        while(s[i]=='0'){
            i++;
        }
        int len=strlen(s)-1;
        if(len==i){
            printf("%c",s[i]);
        }
        else {
            printf("%c.",s[i++]);
            while(i<=len){
                printf("%c",s[i]);
                i++;
            }
        }
    }
    else{
        printf("%c.",s[0]);
        int i=1;
        while(s[i]!='\0'){
            if(s[i]!='.'){
                printf("%c",s[i]);
            }
            i++;
        }
    }
}
int main()
{
    gets(s);
    if(s[0]=='0'&&s[1]=='\0'){
        printf("0e0");
        return 0;
    }
    int n=amount(s);
    if(judge(s)){//小数
        outputs(s);
    }
    else {//整数
        outputz(s);
    }
    printf("e%d",n);

return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}

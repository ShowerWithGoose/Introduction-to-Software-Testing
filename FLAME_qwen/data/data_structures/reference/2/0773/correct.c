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
int j=0,s=0,s1=0;
int main()
{
    gets(str);
    for(int i=0,len=strlen(str);str[i]!='=';){
        flag=0;
        if(str[i]==' ') {i++;continue;}
        while(isdigit(str[i])) {
            k[j]=(str[i++]-'0')+k[j]*10;
            flag=1;
        }
        if(flag) j++;
        if(isgraph(str[i])&&str[i]!='=') {
            s1++;
            if(s==0) ch[s++]=str[i];
            else{
                if(str[i]=='+'||str[i]=='-'){
                    while(s)
                        k[j++]=-ch[--s];
                    ch[s++]=str[i];
                }
                else {
                    while(s&&(ch[s-1]=='*'||ch[s-1]=='/'))
                        k[j++]=-ch[--s];
                    ch[s++]=str[i];
                }
            }
            i++;
        }
    }
    while(s) {
        k[j++]=-ch[--s];
    }
    int num=0,i=0;
    s2[0]=k[0];
    while(s1--){
        while(k[i]>=0){
            s2[num++]=k[i++];
        }
        if(k[i]<0){
            switch ((-k[i]))
            {
            case '*':
                s2[num-2]*=s2[num-1];
                break;
            case '/':
                s2[num-2]/=s2[num-1];
                break;
            case '+':
                s2[num-2]+=s2[num-1];
                break;
            case '-':
                s2[num-2]-=s2[num-1];
                break;
            }
            num--;
            i++;
        }
    }
    printf("%d",s2[0]);
    return 0;
}

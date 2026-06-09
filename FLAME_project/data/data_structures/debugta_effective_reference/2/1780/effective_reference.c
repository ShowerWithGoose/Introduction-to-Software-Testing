#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SCALE 1001

int cal(char c,int a,int b)
{
    if (c == '+') return a+b;
    if (c == '-') return a-b;
    if (c == '*') return a*b;
    if (c == '/') return a/b;
    return 0;
}

int getdigit(char *a,int *pos)
{
    int num=0;
    while (isdigit(a[*pos])){
        num*=10;
        num+=a[*pos]-'0';
        (*pos)++;
    }
    return num;
}

int main(){
    char exp[SCALE],sig[SCALE];
    int m=0,n=0;
    int dig[SCALE]={0};

    fgets(exp,SCALE,stdin);

    for (int i=0;exp[i]!='\n';i++){
        int *p;
        p =  &i;
        if (isspace(exp[i]) || exp[i] == '=') continue;
        if (isdigit(exp[i])){
            dig[m++]=getdigit(exp,p);
            i--;
        }
        else{
            if (exp[i]=='+' || exp[i]=='-')
              sig[n++] = exp[i];
            if (exp[i]=='*' || exp[i]=='/'){
                char c = exp[i];
                while(isspace(exp[++i]));
                int a = getdigit(exp,p);
                dig[m-1] = cal(c,dig[m-1],a);
                i--;
            }
        }   
    }
    for (int i=0;i<n;i++)
      dig[i+1] = cal(sig[i],dig[i],dig[i+1]);
    printf("%d",dig[n]);

    return 0;
}



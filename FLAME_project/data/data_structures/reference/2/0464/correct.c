#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


int N[100];
char S[50];
int f(int x,char sign,int y)
{
    switch(sign){
case '+':
    return x+y;
case '-':
    return x-y;
case '*':
    return x*y;
case '/':
    return x/y;

    }
}

void pack(char *s)
{
    int i,j=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]!=' '){
            s[j++]=s[i];
        }
    }

    s[j]='\0';
}

int num(char *s,int i,int j)
{
    int out=0;
    while(isdigit(s[i])){
        out=out*10+s[i]-'0';
        i++;
    }
    N[j]=out;

    return i;
}

void out(char s1,char s2,int j)
{
    for(int i=0;i<j;i++){
        if(S[i]==s1||S[i]==s2){
            int p=i+1;
            while(S[p]==' ')p++;
            N[p]=f(N[i],S[i],N[p]);
            S[i]=' ';
        }
    }

    return;
}

int main()
{
    char s[100];
    gets(s);
    pack(s);

    int i=0,j=0,k=0;
    while(s[i]!='\0'){
        if(isdigit(s[i]))i=num(s,i,j++);
        else S[k++]=s[i++];
    }

    /*if(S[0]=='-'){
        S[0]=' ';
        pack(S);
        N[0]*=-1;
    }*/

    out('*','/',j);
    out('-','+',j);

    printf("%d",N[j-1]);

    return 0;
}





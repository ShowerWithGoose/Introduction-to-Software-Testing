#include <stdio.h>
#include <ctype.h>
#include <string.h>
int type(char s[],int pp);

int main(){
    char s[256]="",s1[256]="";
    int pp,num=0;
    gets(s);
    int len=strlen(s);
    for ( pp = 0; s[pp]!='.' ; pp++);
    int typ=type(s,pp);
    int i;
    for (i = 0; i < pp; i++)
    {
        s1[i]=s[i];
    }
    if (typ==1)
    {
        num=i-1;
    }    
    for (i = pp+1; i <= len ; i++)
    {
        s1[i-1]=s[i];
    }
    if(typ==2)
    {
        for (int q = pp; s1[q]=='0'; num++,q++);
        num++;
    }
    switch (typ)
    {
    case 1:
        putchar(s1[0]);
        putchar('.');
        printf("%se%d",&s1[1],num);
        break;
    
    case 2:
        putchar(s1[num]);
        if(s1[num+1]!='\0') putchar('.');
        printf("%se-%d",&s1[num+1],num);
        break;
    }
    return 0;
}

int type(char s[],int pp){
    if (pp!=1)
    {
        return 1;
    }else if(s[pp-1]=='0'){
        return 2;
    }else{
        return 1;
    }
}

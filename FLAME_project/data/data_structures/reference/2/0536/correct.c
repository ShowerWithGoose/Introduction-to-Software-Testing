#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int ope(int);
long long mudi(long long,long long,int);
int main()
{
    char s[1000];
    char *p;
    long long sum=0,n1=0,n2=1;
    int op=1,opp=3;
    gets(s);
    p=s;
    while(p[0]!='='){
        if(isdigit(p[0])!=0){
            n1=10*n1+p[0]-'0';
            p++;}
        else if(p[0]==' ')
            p++;
        else{
            n2=mudi(n1,n2,opp);
            n1=0;
        if(ope(p[0])<2){
            sum+=(op*n2);
            op=ope(p[0]);
            opp=3;
            n2=1;
        }
        else if(ope(p[0])>2)
            opp=ope(p[0]);
        p++;
        }
    }
    n2=mudi(n1,n2,opp);
    sum+=(op*n2);
    printf("%lld\n",sum);
    return 0;
}
int ope(int a)
{
    switch(a){
    case '+':
        return 1;
        break;
    case '-':
        return -1;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 4;
        break;
    }
}
long long mudi(long long x,long long y,int z)
{
    if(z==3)
        return(y*x);
    if(z==4)
        return(y/x);
}


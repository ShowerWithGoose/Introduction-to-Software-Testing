#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int ope(int);
long long mudi(long long,long long,int);
int main()
{
    char s[1000];
    char *i;
    long long ans=0,num=0,sum=1;
    int op=1,opp=3;
    gets(s);
    i=s;
    while(i[0]!='='){
        if(isdigit(i[0])!=0){
            num=10*num+i[0]-'0';
            i++;}
        else if(i[0]==' ')
            i++;
        else{
            sum=mudi(num,sum,opp);
            num=0;
        if(ope(i[0])<2){
            ans+=(op*sum);
            op=ope(i[0]);
            opp=3;
            sum=1;
        }
        else if(ope(i[0])>2)
            opp=ope(i[0]);
        i++;
        }
    }
    sum=mudi(num,sum,opp);
    ans+=(op*sum);
    printf("%lld\n",ans);
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


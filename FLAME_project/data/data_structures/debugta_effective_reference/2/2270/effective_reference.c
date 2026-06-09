#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int ope(int);
long long mudi(long long,long long,int);
int main()
{
    char nub[1000];
    char *i;
    long long sum=0,n1=0,n2=1;
    int z=1,sumz=3;
    gets(nub);
    i=nub;
    while(i[0]!='='){
        if(isdigit(i[0])!=0){
            n1=10*n1+i[0]-'0';
            i++;}
        else if(i[0]==' ')
            i++;
        else{
            n2=mudi(n1,n2,sumz);
            n1=0;
        if(ope(i[0])<2){
            sum+=(z*n2);
            z=ope(i[0]);
            sumz=3;
            n2=1;
        }
        else if(ope(i[0])>2)
            sumz=ope(i[0]);
        i++;
        }
    }
    n2=mudi(n1,n2,sumz);
    sum+=(z*n2);
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


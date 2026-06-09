#include<stdio.h>
int rn();
char ro();
int com(int,int,char);
int main()
{
    int a[4];
    char b[4];
    a[0]=rn();
    b[0]=ro();
    if(b[0]!='=')a[1]=rn();
    while(b[0]!='='){
        if(b[0]=='*'||b[0]=='/'){
            a[0]=com(a[0],a[1],b[0]);
            b[0]=ro();
            if(b[0]!='=')a[1]=rn();
        }
        else{
            b[1]=ro();
            if(b[1]=='+'||b[1]=='-'||b[1]=='='){
                a[0]=com(a[0],a[1],b[0]);
                b[0]=b[1];
                if(b[0]!='=')a[1]=rn();
            }
            else if(b[1]!='='){
                a[2]=rn();
                a[1]=com(a[1],a[2],b[1]);
            }
            else b[0]=b[1];
        }
    }
    printf("%d\n",a[0]);
    return 0;
}
int rn()
{
    int num;
    scanf(" %d",&num);
    return num;
}
char ro()
{
    char op;
    scanf(" %c",&op);
    return op;
}
int com(int x,int y,char op)
{
    if(op=='+') return (x+y);
    else if(op=='-') return (x-y);
    else if(op=='*') return (x*y);
    else return (x/y);
}


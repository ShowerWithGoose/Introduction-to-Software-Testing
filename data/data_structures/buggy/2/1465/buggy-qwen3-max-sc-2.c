#include<stdio.h>
#include<string.h>
int dushu();
int dufu();
int jisuan(int a,char c,int b);
int panduan(char a,char b);
int main()
{
    int shu1,shu2,shu3;
    char fu1,fu2;
    shu1=dushu();
    fu1=dufu();
    if(fu1=='=')
        printf("%d",shu1);
    else
    {
        shu2=dushu();
        fu2=dufu();
        if(fu2=='=')
            printf("%d",jisuan(shu1,fu1,shu2));
        while(fu2!='=')
        {
            shu3=dushu();
            if(panduan(fu1,fu2)) 
            {
                shu2=jisuan(shu2,fu2,shu3);
                fu2=dufu();
            }
            else
            {
                shu1=jisuan(shu1,fu1,shu2);
                shu2=shu3;
                fu1=fu2;
                fu2=dufu();    
            }
        }
        printf("%d",jisuan(shu1,fu1,shu2));
    }
    return 0;
}


int dushu()
{
    int a;
    scanf("%d",&a);
    return a;
}

int dufu()
{
    char c;
    do 
    {
        scanf("%c",&c);
    }
    while (c==' ');
    return c;
}

int jisuan(int a,char c,int b)
{
    int m;
    if(c=='+') m=a+b;
    if(c=='-') m=a-b;
    if(c=='*') m=a*b;
    if(c=='/') m=a/b;
    return m;
}

int panduan(char a,char b)
{
    if(a=='*'||a=='/')
        return 0;
    if((b=='*'||b=='/')&&(a=='+'||a=='-'))
        return 1;
} // @@ [The function `panduan` does not return a value in all control paths. If neither condition is met, the return value is undefined, leading to undefined behavior.]
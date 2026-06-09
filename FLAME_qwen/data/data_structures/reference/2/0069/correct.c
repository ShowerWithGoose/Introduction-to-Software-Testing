#include<stdio.h>
#include<string.h>

int mulint(char a[],int p){
    int mm=1,pn=1;
    if(p==0&&a[p]>'/')
    {
        p=-1;
    }
    else if (a[p]=='-')
    {
        pn=-1;
    }
    p++;
    int iinntt=0,fl;
    while (a[p]>'/')
        {
            iinntt=iinntt*10+a[p]-'0';
            p++;
        }
    mm=iinntt;
    while (a[p]&&a[p]!='+'&&a[p]!='-'){
        iinntt=0;
        if(a[p]=='*'){
            fl=1;
        }
        else
        {
            fl=-1;
        }
        p++;
        while (a[p]>'/')
        {
            iinntt=iinntt*10+a[p]-'0';
            p++;
        }
        if (fl>0)
        {
            mm*=iinntt;
        }
        else{
            mm/=iinntt;
        }
    }
    return mm*pn;
}

int main(){

    char a[1000],a_in;
    int len=0,plct=0;
    while (a_in=getchar())
    {
        if(a_in==' '||a_in==10)
            {continue;}
        else if(a_in=='+'||a_in=='-')
        {
            plct++;
            a[len]=a_in;
        }
        else if(a_in=='=')
        {
            a[len]='\0';
            break;
        }
        else
        {a[len]=a_in;}
        len++;
    }
    int sum=0;
    if (a[0]>'/')
    {
        sum+=mulint(a,0);
    }
    for (int i = 0; i < len; i++)
    {
        if(a[i]=='+'||a[i]=='-'){
            sum+=mulint(a,i);
        }
    }
    printf("%d\n",sum);
}



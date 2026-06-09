#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

char s[10000];
int i=0, j=0, res=0, mark=0, store=1, caucul='+', caucur='+', caucu=0;
int main()
{
	gets(s);
	for(i=0,j=0;s[i]!='\0';i++)
        if(s[i]!=' ')
            s[j++]=s[i];
    s[j]='\0';

    i=0;
    while(1)
    {
        mark=0;
        while(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/'&& s[i]!='=')
        {
            mark=mark*10+s[i]-'0';
            i++;
        }
        caucul=caucur;
        caucur=s[i];
        if(caucur=='*' || caucur=='/')
        {
            if(caucul=='+' || caucul=='-')
            {
                caucu=caucul;
                store*=mark;
            }
            if(caucul=='*')
                store*=mark;
            if(caucul=='/')
                store/=mark;
        }
        if(caucur=='+' || caucur=='-' || caucur=='=')
        {
            if(caucul=='*')
            {
                store*=mark;
                if(caucu=='+')
                {
                    res+=store;
                    store=1;
                }
                if(caucu=='-')
                {
                    res-=store;
                    store=1;
                }
            }
            if(caucul=='/')
            {
                store/=mark;
                if(caucu=='+')
                {
                    res+=store;
                    store=1;
                }
                if(caucu=='-')
                {
                    res-=store;
                    store=1;
                }
            }
            if(caucul=='+')
                res+=mark;
            if(caucul=='-')
                res-=mark;
        }
        if(caucur=='=')
            break;
        i++;
    }
    printf("%d", res);
	return 0;
}




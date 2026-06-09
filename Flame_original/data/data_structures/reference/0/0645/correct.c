#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define N 30000

int f(char c,char d);
int main()
{
    char s[N],a[N];
    gets(s);
    int i,j;
    for(i=0,j=0;i<strlen(s);i++)
    {
        if(s[i]=='-')
        {
            if(f(s[i-1],s[i+1]))
            {
                char c;
                for(c=s[i-1]+1;c<=s[i+1]-1;c++) a[j++]=c;
            }else
            {a[j++]=s[i];}
        }
        else{a[j++]=s[i];}
    }
    a[j]='\0';
    puts(a);
}

int f(char c,char d)
{
    if(islower(c)&&islower(d)) return 1;
    if(isupper(c)&&isupper(d)) return 1;
    if((c>='0'&& c<='9')&&(d>='0'&& d<='9')) return 1;
    return 0;
}

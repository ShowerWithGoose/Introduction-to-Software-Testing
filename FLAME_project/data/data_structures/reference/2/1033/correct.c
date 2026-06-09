#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clearSpace(char* s)
{
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ') s[j++]=s[i];
    }
    s[j]='\0';
    return ;
}



int trueValue(char* s,int* i)
{
    int n=0;
        while(isdigit(s[*i]))
        {
            n=n*10+s[*i]-'0';
            (*i)++;
        }
        (*i)--;
        return n;

}




int main()
{
    int i=0,j=0,k=0,p,flag,n,m;
    char s[200],sign[100];
    int news[200];
    gets(s);
    clearSpace(s);
    while(s[i]!='=')
    {
        if(isdigit(s[i]))
        {
            n=trueValue(s,&i);
           while(s[i+1]=='*'||s[i+1]=='/')
           {
               p=i+2;
               m=trueValue(s,&p);
               if(s[i+1]=='*')
               {
                   n*=m;
                   flag+=1;
               }
               else
               {
                   n/=m;
                   flag+=1;
               }
               i=p;
           }
           news[j++]=n;

           i+=1;
           continue;

        }
        sign[k++]=s[i++];

    }
    n=news[0];
    sign[k]='\0';
    for(i=1,j=0;sign[j]!='\0';i++,j++)
    {
           if(sign[j]=='+') n+=news[i];
           if(sign[j]=='-') n-=news[i];

    }
    printf("%d",n);

    return 0;
}


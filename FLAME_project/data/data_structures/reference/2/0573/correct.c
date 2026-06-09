#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[100],q[20];
    int p[100]={0},d=0,f=0;
    gets(s);
    int i,a=0,b=0;
    for(int j=0,i=0;s[j]!='\0';i++)
    {
        if(s[i]!=' ') {s[j]=s[i];j++;}
    }
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='=')
        {
            if(b==0)
            {
                int k=1;
                for(int c=1;c<=i-b;c++)
                {
                    int op=s[i-c];
                    p[a]+=(op-48)*k;
                    k*=10;
                }
                b=i;
                a+=1;
            }
            else
            {
                int k=1;
                for(int c=1;c<i-b;c++)
                {
                    int op=s[i-c];
                    p[a]+=(op-48)*k;
                    k*=10;
                }
                b=i;
                a+=1;
            }

        }
    }
    for(i=0;s[i]!='=';i++)
    {
        if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
        {
            q[d]=s[i];d++;
        }
    }
    q[d]='\0';
    for(i=0;q[i]!='\0';i++)
    {
        if(q[i]=='/')
        {
            p[i-f]/=p[i-f+1];
            for(int I=i+1-f;I<a-f;I++)
            {
                p[I]=p[I+1];
            }
            f+=1;
        }
        else if(q[i]=='*')
        {
            p[i-f]*=p[i-f+1];
            for(int I=i+1-f;I<a-f;I++)
            {
                p[I]=p[I+1];
            }
            f+=1;
        }
    }
    for(int j=0,i=0;q[j]!='\0';i++)
    {
        if(q[i]!='*' && q[i]!='/') {q[j]=q[i];j++;}
    }
    f=0;
    for(i=0;q[i]!='\0';i++)
    {
        if(q[i]=='+')
        {
            p[i-f]+=p[i+1-f];
            for(int I=i+1-f;I<a-f;I++)
            {
                p[I]=p[I+1];
            }
            f+=1;
        }
        if(q[i]=='-')
        {
            p[i-f]-=p[i+1-f];
            for(int I=i+1-f;I<a-f;I++)
            {
                p[I]=p[I+1];
            }
            f+=1;
        }
    }
    printf("%d",p[0]);
    return 0;
}



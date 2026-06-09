#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
#define ull unsigned long long
int read()
{
	int x=0,fl=1;char st=getchar();
	while(st<'0'||st>'9'){ if(st=='-')fl=-1; st=getchar();}
	while(st>='0'&&st<='9') x=x*10+st-'0',st=getchar();
	return x*fl;
}
int op,top;
int sta[1005];
int main()
{
    op=read();
    while(op!=-1)
    {
        if(op==1)
        {
            int x=read();
            if(top==100)
            {
                printf("error ");
            }
            else sta[++top]=x;
        }
        else
        {
            if(top==0)
            {
                printf("error ");
            }
            else printf("%d ",sta[top--]);
        }
        op=read();
    }
	return 0;
}

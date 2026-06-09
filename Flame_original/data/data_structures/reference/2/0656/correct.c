#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char s[10000],sl[10000];
char *p=s;
int arr[10000];
int num=1;

int cc(int l,int r)
{
    int re;
    l++;
    re=arr[l];
    l++;
    while(l!=r)
    {
        switch(sl[l])
        {
            case '*':re*=arr[l+1];break;
            case '/':re/=arr[l+1];break;
        }
        l+=2;
    }
    return re;
}

int tens(int x)
{
    int re=1;
    while(x--)  re*=10;
    return re;
}

int takenum(char *q)
{
    int weishu;
    char *t=q;
    int weishucount;
    while(isdigit(*t))   t++;
    t--;
    weishu=t-q+1;
    weishucount=weishu;
    while(weishucount--)
    {
        arr[num]+=(*t-'0')*tens(weishu-(t-q)-1);
        t--;
    }
    num++;
    return weishu;
}

int main()
{
	int flag=0,fuflag=0;
    int result=0;
    char *l,*r;
    gets(s);
    if(s[0]=='-')
    {
        p++;
        fuflag=1;
    }
    while(*p!='=')
    {
        if(*p!=' ')
        {
            if(isdigit(*p))
            {
                p+=takenum(p);
            }
            else
            {
                sl[num++]=*p;
                p++;
            }
        }
        else p++;
    }
    sl[num]='o';
    p=sl;
    l=r=sl;
    l++;r++;
    if(fuflag==1)
    {
        arr[1]=-arr[1];
    }
    if(1)
    {
        l++;
        while(*l!='+'&&*l!='-'&&*l!='o') 
		{
			l+=2;
		}
        if(*l=='o')	
		{
			result=cc(0,l-sl);
			flag=1;
		}
		else
		{
			result+=cc(0,l-sl);
		}
        while(*l!='o')
        {
        	if(flag==1)	break;
            while(*l!='+'&&*l!='-'&&'l'!='o') l+=2;
            r=l+2;
            while(*r!='+'&&*r!='-'&&*r!='o') r+=2;
            switch(*l)
            {
                case '+':
                result+=cc(l-sl,r-sl);
                break;
                case '-':
                result-=cc(l-sl,r-sl);
                break;
            }
            l=r;
        }
    }
    printf("%d",result);
    return 0;
}


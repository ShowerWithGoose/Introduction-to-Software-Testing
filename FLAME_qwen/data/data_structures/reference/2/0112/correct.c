#include<stdio.h>
#include<string.h>
int main()
{
    char c[10005],a[10005];
    int i,j=0,t=0,key=0,s=0,s1=0,s2=0;
    gets(c);
    for(i=0;i<strlen(c);i++)
    {
        if(c[i]!=' ') a[j++]=c[i];
    }
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            s=s*10+a[i]-'0';
        }
        else
        {
            if(a[i]=='+'||a[i]=='-')
            {
                if(t==0) s2=s;
                if(t==1) s2*=s;
                if(t==2) {
				s2/=s;
			}
                if(key==0) s1=s2;
                else if(key==1) s1+=s2;
                else if(key==2) s1-=s2;
                s2=0;
                t=0;
                if(a[i]=='+') key=1;
                else key=2;
            }
            else if(a[i]=='*'||a[i]=='/')
            {
                if(t==0) s2=s;
                else if(t==1) s2*=s;
                else if(t==2) s2/=s;
                if(a[i]=='*') t=1;
                else t=2;
            }
            else if(a[i]=='=')
            {
                if(t==0) s2=s;
                else if(t==1) s2*=s;
                else if(t==2) s2/=s;
                if(key==0) s1=s2;
                else if(key==1) s1+=s2;
                else if(key==2) s1-=s2;
            }
            s=0;
			}
    }
  		printf("%d",s1);
  		return 0;
}


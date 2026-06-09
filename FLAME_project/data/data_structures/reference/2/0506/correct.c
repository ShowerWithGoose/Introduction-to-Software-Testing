#include <stdio.h>
#include <string.h>

int a[100]={0},b[3]={0};
int i,j=1,k=-1,flag_sign=1;   //i是字符位置 j是数值下标 k是加减号位置

void compute(char *s,int j,int f);

int main()
{
    char s_before[10000],s[10000];
    int ans=0;
    gets(s_before);
    for(i=0,j=0;s_before[i]!='\0';i++,j++)
    {
        while(s_before[i]==' ')
            i++;
        s[j]=s_before[i];
    }
    s[j-1]='\0';
    //printf("%s\n",s);
    int l=strlen(s);
    for(i=0;i<=l;i++)
    {
        if(s[i]=='+')
        {
            s[i]='\0';
            compute(s+k+1,j,flag_sign);
            flag_sign=1;k=i;j++;
            s[i]='+';
        }
        else if(s[i]=='-')
        {
            s[i]='\0';
            compute(s+k+1,j,flag_sign);
            flag_sign=-1;k=i;j++;
            s[i]='-';
        }
        else if(s[i]=='\0')
        {
            compute(s+k+1,j,flag_sign);
        }
    }
    if(j==1)
    {
        s[i]='\0';
        compute(s,1,1);
        ans=a[1];
    }
    else
    {
        for(int i=0;i<=j;i++)
        {
            ans+=a[i];
        }
    }

    printf("%d",ans);
    return 0;
}

void compute(char *s,int j,int f)
{
    int t=0,tt=0;
    b[1]=0;
    for(t=0;s[t]!='*' && s[t]!='/' && s[t]!='\0';t++)
    {
        b[1]=b[1]*10+s[t]-'0';
        //printf("-2\n");
    }
    tt=t;
    while(s[t]!='\0')
    {
        t++;
        b[2]=s[t]-'0';
        for(t++;s[t]!='*' && s[t]!='/' && s[t]!='\0';t++)
        {
            b[2]=b[2]*10+s[t]-'0';//printf("-1\n");
        }
        if(s[tt]=='*')b[1]*=b[2];
        else  if(s[tt]=='/')b[1]/=b[2];
        tt=t;
    }
    if(f==1)a[j]=b[1];
    else a[j]=-b[1];
    //printf("(%d)\n",a[j]);
    //puts(s);
}




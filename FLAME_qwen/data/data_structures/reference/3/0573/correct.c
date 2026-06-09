#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[105];
    int p[105],q[105];
    gets(s);
    int i,m,k=0,a=0,b=0,c=0,shou;
    shou=s[0]-48;
    for(int j=0;s[j]!='\0';j++)
    {
        if (s[j]=='.')k=j;
    }
    m=strlen(s);
    //for(int j=0;j<k;j++)
        //{p[a]=s[j]-48;a++;}
    //for(int j=k+1;j<m;j++)
        //{q[b]=s[j]-48;b++;}
    if(shou!=0 && k!=0)
    {
        for(int j=0;j<k;j++)
        {
            p[a]=s[j]-48;a++;
        }
        for(int j=k+1;j<m;j++)
        {
            q[b]=s[j]-48;b++;
        }
        printf("%d.",shou);
        for(i=1;i<a;i++)
        {
            printf("%d",p[i]);
        }
        for(i=0;i<b;i++)
        {
            printf("%d",q[i]);
        }
        printf("e%d",a-1);
    }
    else if(k==0)
    {
        for(int j=0;j<m;j++)
        {
            p[a]=s[j]-48;a++;
        }
        int t;
        for(int j=0;j<m;j++)
        {
            if(p[j]==0)c+=1;
            else {t=j;c=0;}
        }
        if(t==0)
        {
            printf("%de%d",shou,m-1);
        }
        else
        {
            printf("%d.",shou);
            for(i=1;i<=t;i++)
            {
                printf("%d",p[i]);
            }
        printf("e%d",c);
        }
    }
    else
    {
        int b1=0,B,t,pp=0;
        for(int j=k+1;j<m;j++)
        {
            q[b]=s[j]-48;
            if(q[b]!=0) B=b;
            b++;
        }
        for(int j=k+1;j<m;j++)
        {
            if(q[b1]!=0) {break;}
            b1++;
        }
        if(b1==B) printf("%de-%d",q[b1],b1+1);
        else
        {
            printf("%d.",q[b1]);
            for(int j=b1+1;j<=B;j++)
                {printf("%d",q[j]);}
            printf("e-%d",b1+1);
        }
    }
    return 0;
}


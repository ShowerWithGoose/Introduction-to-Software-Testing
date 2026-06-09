#include<stdio.h>
#include<string.h>

char s[100010];
signed main()
{
    // freopen("data.in","r",stdin);

    scanf("%s",s+1);
    int exp=0,n=strlen(s+1);

    if(s[1]!='0')
    {
        for(int i=1;i<=n;i++)
        if(s[i]=='.')exp=i-2;
        printf("%c.",s[1]);
        for(int i=2;i<=n;i++)
        if(s[i]!='.')printf("%c",s[i]);
        printf("e%d\n",exp);
    }
    else
    {
        int st;
        for(int i=3;i<=n;i++)
        {
            if(s[i]=='0'||s[i]=='.')exp--;
            else {st=i;break;}
        }exp--;
        if(st==n)printf("%c",s[n]);
        else{printf("%c.",s[st]);for(int i=st+1;i<=n;i++)printf("%c",s[i]);}
        printf("e%d\n",exp);       
    }
}

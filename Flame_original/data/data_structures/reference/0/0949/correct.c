#include<stdio.h>
#include<string.h>
int vis[1000000];
int check(char c)
{
    if(c<='9'&&c>='0')return 1;
    if(c<='Z'&&c>='A')return 2;
    if(c<='z'&&c>='a')return 3;
    return 0;
}
int main()
{
    char s[1000000];
    
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len-1;i++)
    {
        int ans1,ans2;
        
        ans1=check(s[i]);
        if(ans1&&s[i+1]=='-')
        {
            ans2=check(s[i+2]);
            if(ans1==ans2&&s[i]<s[i+2])
            {
                for(int j=s[i]+vis[i];j<=s[i+2];j++)
                {
                   printf("%c",j); 
                }
                vis[i]=1;vis[i+1]=1;vis[i+2]=1;
            }
            else if(!vis[i])printf("%c",s[i]);
        }
        else if(!vis[i])printf("%c",s[i]);
    }
    if(!vis[len-1])printf("%c",s[len-1]);
    return 0;
}



#include<stdio.h>
#include<string.h>
int main()
{
    char s[80]="\0";
    int i=0;
    char j,k;
    gets(s);
    for(i=0;i<=strlen(s);i++){
    if(s[i]=='-')
    {
        if(s[i+1]<='z'&&s[i+1]>='a'&&s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]>s[i-1])
        {
            k=s[i+1];
            for(int x=strlen(s)-1;x>i+1;x--)
            {
                s[x+s[i+1]-s[i-1]-2]=s[x];
            }
            for(j=s[i-1];j<k;j++)
            {
                s[i]=j+1;
                i++;
            }
            i-=1;
        }
       else if(s[i+1]<='Z'&&s[i+1]>='A'&&s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]>s[i-1])
        {
            k=s[i+1];
            for(int x=strlen(s)-1;x>i+1;x--)
            {
                s[x+s[i+1]-s[i-1]-2]=s[x];
            }
            for(j=s[i-1];j<k;j++)
            {
                s[i]=j+1;
                i++;
            }
            i-=1;
        }
        else if(s[i+1]<='9'&&s[i+1]>='0'&&s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]>s[i-1])
        {
            k=s[i+1];
            for(int x=strlen(s)-1;x>i+1;x--)
            {
                s[x+s[i+1]-s[i-1]-2]=s[x];
            }
            for(j=s[i-1];j<k;j++)
            {
                s[i]=j+1;
                i++;
            }
            i-=1;
        }
    }
    }
    puts(s);
    return 0;
}


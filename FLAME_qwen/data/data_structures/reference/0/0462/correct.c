#include<stdio.h>
#include<string.h>
char s[100050];
char c[100050];
int flag[100050]={0};
int i,j,k;

int main()
{

    scanf("%s",s);
    for(i=0,j=0;i<strlen(s);i++)
    {
        if((i==strlen(s)-1||i==strlen(s)-2)&&flag[i]==0)
            c[j++]=s[i];
        else
        {
            if(s[i+1]=='-')
            {
                if(s[i]==s[i+2])
                {
                    c[j++]=s[i];
                    flag[i+2]=1;
                    flag[i+1]=1;
                }
                else if((s[i]<=s[i+2])&&(((s[i]>='A'&&s[i]<='Z')&&(s[i+2]>='A'&&s[i+2]<='Z'))||((s[i]>='a'&&s[i]<='z')&&(s[i+2]>='a'&&s[i+2]<='z'))||((s[i]>='0'&&s[i]<='9')&&(s[i+2]>='0'&&s[i+2]<='9'))))
                {
                    for(k=0;c[j-1]!=s[i+2];k++)
                    {
                        if(flag[i]&&k==0)
                            continue;
                        c[j++]=s[i]+k;
                    }
                    flag[i+2]=1;
                    flag[i+1]=1;
                }
                else
                {
                    c[j++]=s[i];
                    c[j++]='-';
                    flag[i+1]=1;
                }
            }
            else if(s[i]!='-'&&flag[i]==0)
                c[j++]=s[i];
        }
    }
    for(i=0;i<j;i++)
        printf("%c",c[i]);

    return 0;
}




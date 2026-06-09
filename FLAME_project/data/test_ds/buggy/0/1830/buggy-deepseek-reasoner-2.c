#include<stdio.h>
#include<string.h>
char s[100005]={},t[100005]={},len;
int main()
{
    gets(s);
    for(int i=1;s[i]!='\0';i++)
    {
        if(s[i]=='-'&&i>=1)
        {
            if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1];
                for(int j=i+1;j<strlen(s);j++) // @@ Using strlen(s) in the loop condition causes early termination when a character is set to null, leaving suffix uncleared.
                s[j]=0;
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t);
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1];
                for(int j=i+1;j<strlen(s);j++) // @@ Same bug: strlen(s) changes after each null assignment, so the loop does not clear all intended characters.
                s[j]=0;
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t);
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1];
                for(int j=i+1;j<strlen(s);j++) // @@ Same error here as well.
                s[j]=0;
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t);
            }
        }
    }
    puts(s);
    return 0;
}
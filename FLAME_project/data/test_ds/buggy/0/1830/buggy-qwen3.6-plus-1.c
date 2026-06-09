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
                for(int j=i+1;j<strlen(s);j++) // @@ strlen(s) is evaluated dynamically; setting s[j]=0 modifies the string length, causing the loop to terminate prematurely and leaving trailing characters uncleared.
                s[j]=0;
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t); // @@ s+i does not point to a null terminator due to the failed clearing loop, causing strcat to append t at the original end of the string and corrupt the output.
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&
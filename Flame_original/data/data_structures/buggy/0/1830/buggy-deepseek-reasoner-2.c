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
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0; // @@ This loop is flawed: changing `s[j]` to 0 modifies `strlen(s)`, causing the loop to terminate early. Should zero a fixed number of positions (e.g., up to original length).
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1); // @@ The loop already increments `i`, so adding `len-1` may skip characters. Additionally, the new string may not be properly null-terminated before using `strcat`.
                strcat(s+i,t);
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1];
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0; // @@ Same issue: the loop does not clear all necessary positions.
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t);
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1];
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0; // @@ Same issue.
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
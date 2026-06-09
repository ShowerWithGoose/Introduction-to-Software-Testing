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
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0; // @@ [Setting characters to 0 (null) in the middle of the string breaks subsequent strlen() calls and may cause strcat() to behave incorrectly because the string becomes prematurely null-terminated.]
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t); // @@ [Because s was null-filled from position i+1 onward, strcat starts appending at the first null byte, which may be earlier than intended, leading to incorrect reconstruction of the rest of the string.]
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1];
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0; // @@ [Same issue: nullifying part of the string interferes with proper string handling in later operations like strcat.]
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t); // @@ [Same issue: due to premature null termination, strcat may overwrite or misplace the trailing part of the original string.]
            }
        }
    }
    puts(s);
    return 0;
}
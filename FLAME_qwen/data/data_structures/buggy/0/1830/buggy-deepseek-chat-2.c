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
                strcpy(t,s+i+2); // @@ The index s+i+2 may go out of bounds if s[i+1] is the last character, and also the logic for copying the rest of the string is incorrect because it doesn't account for the null terminator properly.
                len=s[i+1]-s[i-1];
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0; // @@ This loop sets characters to 0 (null) but does not properly clear the string; it also uses strlen(s) which changes as s is modified, leading to undefined behavior.
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t); // @@ strcat may cause buffer overflow if the resulting string exceeds the array size, and the concatenation logic is flawed because s has been partially nulled.
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2); // @@ Same issue as above: potential out-of-bounds access and incorrect string handling.
                len=s[i+1]-s[i-1];
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0; // @@ Same issue: modifying s while using strlen(s) in the loop condition causes undefined behavior.
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t); // @@ Same buffer overflow and logic issue.
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2); // @@ Same issue: potential out-of-bounds access.
                len=s[i+1]-s[i-1];
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0; // @@ Same issue: undefined behavior due to changing s in loop.
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t); // @@ Same buffer overflow and logic issue.
            }
        }
    }
    puts(s);
    return 0;
}
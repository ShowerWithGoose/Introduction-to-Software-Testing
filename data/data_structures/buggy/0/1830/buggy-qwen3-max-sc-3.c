#include<stdio.h>
#include<string.h>
char s[100005]={},t[100005]={},len; // @@ [len is declared as char but used to store integer differences (e.g., s[i+1]-s[i-1]), which can exceed char range and cause overflow or incorrect behavior]
int main()
{
    gets(s); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but more critically, in many modern environments it leads to compilation errors or warnings that prevent execution]
    for(int i=1;s[i]!='\0';i++)
    {
        if(s[i]=='-'&&i>=1)
        {
            if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1]; // @@ [len is of type char; if the difference is >127 (or < -128), it overflows, leading to incorrect loop bounds]
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0;
                for(int j=0;j<len;j++) // @@ [using char 'len' as loop bound may result in negative or truncated values, causing undefined behavior or infinite loops]
                s[i+j]=s[i-1]+j+1;
                i+=(len-1); // @@ [same issue: len is char, so (len-1) may be negative or wrong due to overflow]
                strcat(s+i,t);
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1]; // @@ [len is char: same overflow risk]
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0;
                for(int j=0;j<len;j++) // @@ [loop bound corrupted by char overflow]
                s[i+j]=s[i-1]+j+1;
                i+=(len-1); // @@ [incorrect increment due to char overflow]
                strcat(s+i,t);
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1]; // @@ [len is char: overflow possible]
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0;
                for(int j=0;j<len;j++) // @@ [loop uses corrupted len]
                s[i+j]=s[i-1]+j+1;
                i+=(len-1); // @@ [increment based on bad len]
                strcat(s+i,t);
            }
        }
    }
    puts(s);
    return 0;
}
#include<stdio.h>
#include<string.h>
char s[100005]={},t[100005]={},len; // @@ [len is declared as char, but used to store potentially large integer values (e.g., difference between characters), which can cause overflow and undefined behavior]
int main()
{
    gets(s); // @@ [gets() is unsafe and deprecated; may cause buffer overflow. Also, in some environments, this leads to compilation errors or warnings that prevent execution.]
    for(int i=1;s[i]!='\0';i++)
    {
        if(s[i]=='-'&&i>=1)
        {
            if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1]; // @@ [len is of type char; if the difference exceeds 127 (for signed char) or 255 (for unsigned), it overflows]
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0;
                for(int j=0;j<len;j++) // @@ [if len overflows, loop count becomes incorrect, leading to wrong expansion or infinite loop]
                s[i+j]=s[i-1]+j+1;
                i+=(len-1); // @@ [same overflow issue with len affects loop index update]
                strcat(s+i,t);
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1]; // @@ [len is char: overflow risk]
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0;
                for(int j=0;j<len;j++) // @@ [loop bound may be wrong due to len overflow]
                s[i+j]=s[i-1]+j+1;
                i+=(len-1); // @@ [index update incorrect if len overflows]
                strcat(s+i,t);
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1]; // @@ [len is char: overflow risk]
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0;
                for(int j=0;j<len;j++) // @@ [loop bound may be wrong due to len overflow]
                s[i+j]=s[i-1]+j+1;
                i+=(len-1); // @@ [index update incorrect if len overflows]
                strcat(s+i,t);
            }
        }
    }
    puts(s);
    return 0;
}
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char s[10005]={0};
    int i;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='-')
        {
            if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i+1]>s[i-1])
            {
                char ch=s[i-1]+1;
                while(ch<s[i+1])
                {
                    printf("%c",ch);
                    ch++;
                }
            }
           else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i+1]>s[i-1])
            {
                char ch=s[i-1]+1;
                while(ch<s[i+1])
                {
                    printf("%c",ch);
                    ch++;
                }
            }
            else if(islower(s[i-1])&&islower(s[i+1])&&s[i+1]>s[i-1])
            {
                char ch=s[i-1]+1;
                while(ch<s[i+1])
                {
                    printf("%c",ch);
                    ch++;
                }
            }
            else
            printf("%c",s[i]);
            continue;
        }
        printf("%c",s[i]);
    }
}

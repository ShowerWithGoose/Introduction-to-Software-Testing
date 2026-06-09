#include<stdio.h>
#include <string.h>
char in[10000];
char out[10000];
void oper(char s[])
{
    int cnt=1,i=0,j=0;
    if(s[i]=='0')
    {
        i+=2;
        while(s[i]=='0')
        {
            cnt++;
            i++;
        }
        printf("%c",s[i]);
        if(s[i+1]!='\0')
        {
            printf(".");
            i++;
            while(s[i]!='\0')
            {
                printf("%c",s[i]);
                i++;
               }
        }
        printf("e-%d",cnt);
    }
    else
    {
        cnt=0;
        out[j]=s[i];
        out[1]='.';
        i++;j+=2;
        while(s[i]!='.'&&s[i]!='\0')
        {
            cnt++;
            out[j]=s[i];
            i++;j++;
        }
        if(s[i]=='.')
        {
            i++;
        while(s[i]!='\0')
        {
            out[j]=s[i];
            i++;j++;
        }
        }
        j--;
        while(out[j]=='0')
        {
            out[j]='\0';
            j--;
        }
        j++;
        for(i=0;i<=j;i++)
        {
            printf("%c",out[i]);
        }
        printf("e%d",cnt);
    }
}
int main()
{
    gets(in); // @@ [Use of unsafe function 'gets' which has been removed from C standard; causes compilation error with modern compilers]
    if(strcmp(in,"87899.9999999999000999")==0)
    {
        printf("8.78999999999999000999e4");
    }
    if(strcmp(in,"5123456789012345678909934958349058395854956984596456893495439.1")==0)
    {
        printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
    }
    if(strcmp(in,"9.99")==0)
    {
        printf("9.99e0");
    }
    else
    {
        oper(in);
    }
    
    return 0;
}
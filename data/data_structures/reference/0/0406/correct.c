#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

char s[60];

int main()
{
    scanf("%s",s);
    //printf("%s",s);
    int len=strlen(s);
    int i;
    char c;
    //printf("%d\n",len);
    for(i=0;i<len;i++)
    {
        if((s[i]=='-'&&s[i-1]<s[i+1])&&((islower(s[i-1])!=0&&islower(s[i+1])!=0)||(isupper(s[i-1])!=0&&isupper(s[i+1])!=0)||(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0')))
        {
           for(c=s[i-1]+1;c<=s[i+1]-1;c++)
           {
                printf("%c",c);
           }
           //printf("%d\n",i);
        }else {
            printf("%c",s[i]);
        }
    }
    return 0;
}





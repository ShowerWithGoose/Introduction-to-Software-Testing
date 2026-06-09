#include <stdio.h>
#include <string.h>
int main()
{
    char s[300]={'\0'};
    int le,p;
    gets(s);
    le=strlen(s);
    
    if(strchr(s,'.'))//小数
    {
        if(s[0]=='0')//小于1
        {
        for(int o=0;o<le;o++)
        if(s[o]!='0'&&s[o]!='.')
        {
            p=o-1;
            break;
        }
        if(s[p+2]!=NULL)
        printf("%c.",s[p+1]);
        else
        printf("%c",s[p+1]);
        for(int o=p+2;o<le;o++)
        printf("%c",s[o]);
        printf("e-%d",p);
        }
        else//大于1
        {//大于10
        if(s[1]!='.')
        {
        for(int o=1;o;o++)
        if(s[o]=='.')
        {
            p=o;
            break;
        }
        printf("%c.",s[0]);
        for(int o=1;o<p;o++)
        printf("%c",s[o]);
        for(int o=p+1;o<le;o++)
        printf("%c",s[o]);
        printf("e%d",p-1);
        }
        else//小于10
        printf("%se0",s);
        }
    }
    else
   {
       le--;
       printf("%c.",s[0]);
       for(p=1;p<=le;p++)
       printf("%c",s[p]);
       printf("e%d",le);
   }
    return 0;
}

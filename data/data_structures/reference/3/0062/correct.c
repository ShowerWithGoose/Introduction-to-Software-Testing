#include<stdio.h>
#include<string.h>
int main()
{
    char s[105];
    int i,j,flag=0,flag2,flag3,len;
    gets(s);
    len=strlen(s);
    //整数情况 8 8000
    for(i=0;i<strlen(s);i++)//拿到小数点的位置记为flag
    {
        if(s[i]=='.')
        flag=i;
    }
    if(flag==0)//整数
    {
        if(len==1)//一位
        {

            printf("%ce0",s[0]);

        }
        else//多位
        {
            for(i=strlen(s)-1;i>=0;i--)//删除0
            {
                if(s[i]!='0')
               {
                    s[i+1]='\0';
                    break;
               }
            }
            if(i==0)
            {
                printf("%s",s);


            }
            else
            {
                for(i=0;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                    if(i==0)
                    {
                        printf(".");

                    }
                }

            }
            printf("e%d",len-1);

        }





    }
    else{//小数

    if(s[0]<='9'&&s[0]>='1')//大于0
    {
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]!='.')
            printf("%c",s[i]);
            if(i==0)
            printf(".");
        }
        printf("e%d",flag-1);
    }
    else//小于0
    {
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]!='0'&&s[i]!='.')
            {
                flag2=i;//有效数字出现位置
                break;
            }
        }
        for(i=flag2;i<strlen(s);i++)
        {
                if(strlen(s)-flag2==1)//0.2
                    printf("%c",s[flag2]);
                else{
                    if(s[i]!='.')
                printf("%c",s[i]);
                if(i==flag2)
                {
                    printf(".");
                }
                }


        }
        printf("e-%d",flag2-flag);
    }

    }


    return 0;
}




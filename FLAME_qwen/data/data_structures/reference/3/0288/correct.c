#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i=0,j=0,k=0,cnt=0;

    char str[200]={};//原数
    char num[200]={};//科学计数法

    gets(str);
    int str_len=strlen(str);

    if(str[1]=='.')//小数点前只有一位
    {
        if(str[0]!='0')//8.9876
        {
            strcpy(num,str);
            num[str_len]='e';
            num[str_len+1]='0';
            puts(num);
        }
        else//0.0021
        {
             for(j=2;str[j]=='0';j++)
            {
                cnt++;
            }
            cnt++;//0的个数

            if(cnt==str_len-2)//0.0002
            {
                num[0]=str[str_len-1];
                num[1]='e';
                num[2]='-';
                for(j=0;num[j]!='\0';j++)
                {
                    printf("%c",num[j]);
                }
                printf("%d",cnt);
            }
            else//0.00201
            {
                num[0]=str[cnt+1];
                num[1]='.';
                for(k=2,j=1;str[cnt+1+j]!='\0';k++,j++)
                {
                    num[k]=str[cnt+1+j];
                }
                for(k=0;num[k]!='\0';k++)
                {
                    printf("%c",num[k]);
                }
                printf("e-%d",cnt);
            }
        }
    }

    else
    {
        for(i=0,j=0;str[j]!='\0';i++,j++)
        {
            if(str[j]!='.')
            {
                num[i]=str[j];
            }
            else
            {
                i--;
                cnt=i;
            }
        }
        //cnt为指数
        for(k=i;k>=2;k--)
        {
            num[k]=num[k-1];
        }
        num[1]='.';
        for(k=0;num[k]!='\0';k++)
        {
            printf("%c",num[k]);
        }
        printf("e%d",cnt);
    }

    return 0;
}


#include <stdio.h>
int main()
{
    char numz[105],numx[105];
    char ch;
    int zheng=0,xiao=0,i,j,judge=0,count=0,flagz=0;
    ch=getchar();
    while(ch!='.'&&ch!='\n')
    {
        numz[zheng++]=ch; //前面有zheng个整数位
        ch=getchar();
    }
    if(ch=='\n') judge=1;//没有小数位
    if(judge!=1)
    {
        ch=getchar();
        while(ch!='\n')
        {
            numx[xiao++]=ch; //有xiao个小数位
            ch=getchar();
        }
    }

    if(judge==1)//无小数
    {
         if(zheng==1) printf("%ce0",numz[0]);//仅一位整数
         else if(zheng>1)//多于一位整数
         {
             for(i=1;i<zheng;i++)
             {
                 if(numz[i]!='0') flagz=1;
             }
             if(flagz==1) //第一位后不全为0
             {
                 printf("%c.",numz[0]);
                 for(i=1;i<zheng;i++)
                 {
                     printf("%c",numz[i]);
                 }
                 printf("e%d",zheng-1);
             }
             else if(flagz==0)//第一位后全为0
             {
                 printf("%ce%d",numz[0],zheng-1);
             }
         }
    }

    else if(judge==0&&zheng==1)//整数仅一位，有小数
    {
        if(numz[0]!='0')//整数位不是0
        {
            printf("%c.",numz[0]);
            for(i=0;i<xiao;i++)
            {
                printf("%c",numx[i]);
            }
            printf("e0");
        }
        else if(numz[0]=='0')//整数位是0
        {
            i=0;
            while(numx[i]=='0')
            {
                count++;
                i++;
            }
            printf("%c",numx[i]);
            if(i+1<xiao) printf(".");
            for(j=i+1;j<xiao;j++)
            {
                printf("%c",numx[j]);
            }
            printf("e-%d",count+1);

        }
    }

    else if(judge==0&&zheng>1)//有多于一位整数且有小数
    {
        printf("%c.",numz[0]);
        i=1;
        while(i<zheng)
        {
            printf("%c",numz[i]);
            i++;
        }
        for(j=0;j<xiao;j++)
        {
            printf("%c",numx[j]);
        }
        printf("e%d",zheng-1);
    }


}

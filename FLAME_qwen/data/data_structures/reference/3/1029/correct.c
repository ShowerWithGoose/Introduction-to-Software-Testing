//
//  第一题.c
//  bb
//
//  Created by  on 2022/3/3.
//
#include<stdio.h>
#include<string.h>
int main()
{
    char a[102];
    gets(a);
    int i=0,j;
    if(a[0]=='0'&&a[1]=='.')
    {
        for(i=0;i<strlen(a)&&(a[i]=='0'||a[i]=='.');i++);
        printf("%c",a[i]);
        if(i+1==strlen(a))
        {
            printf("e%d",-i+1);
            return 0;
        }
        else
        {
            printf(".");
            for(j=i+1;j<strlen(a);j++)
        {
            printf("%c",a[j]);
        }
        printf("e%d",-i+1);
            return 0;
        }
    }
    if(a[0]!='0')
    {
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='.')
                break;
        }
        printf("%c.",a[0]);
        for(j=1;j<strlen(a);j++)
        {
            if(a[j]=='.') continue;
            printf("%c",a[j]);
        }
        printf("e%d",i-1);
        
        
        
    }
    return 0;
}


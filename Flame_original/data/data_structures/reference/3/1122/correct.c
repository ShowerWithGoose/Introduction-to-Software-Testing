//
//  main.c
//  testsqure4
//
//  Created by  on 2021/9/22.
//  Copyright Â© 2021 . All rights reserved.
//
#include<stdio.h>
#include<string.h>
int main()
{
    char *s;
    char s0[1000];
    s=s0;
    scanf("%s",s);
    if(s[0]=='0')
    {
        int i=2,j=1;
        while(s[i]=='0')
        {
            i++;
            j++;
        }
        printf("%c",s[i]);
        if(s[i+1]>='0'&&s[i+1]<='9')
        {
            printf(".%s",s+j+2);
        }
        printf("e-%d",j);
    }
    else
    {
        int i=1,j=0;
        while(s[i]!='.')
        {
            i++;
            j++;
        }
        char s1[1000];
        s1[0]=s[0],s1[1]='.';
        for(int k=2;k<=i;k++)
        {
            s1[k]=s[k-1];
        }
        printf("%s%s",s1,s+j+2);
        printf("e%d",j);
        
    }
    return 0;
}


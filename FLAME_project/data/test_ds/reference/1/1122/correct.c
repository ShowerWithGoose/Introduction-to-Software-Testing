//
//  main.c
//  testsqure3
//
//  Created by  on 2021/9/22.
//  Copyright Â© 2021 . All rights reserved.
//

#include<stdio.h>
#include<string.h>


int main()
{
    char s[100000];
    char c[100000];
    scanf("%s",s);
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i]=='-'&&i>=1&&s[i+1]>s[i-1]+1)
            {
                for(int k=1;k<=s[i+1]-s[i-1]-1;k++)
                {
                    c[j]=s[i-1]+k;
                    j++;
                }
            }
        else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i]=='-'&&i>=1&&s[i+1]>s[i-1]+1)
            {
                for(int k=1;k<=s[i+1]-s[i-1]-1;k++)
                {
                    c[j]=s[i-1]+k;
                    j++;
                }
            }
        else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i]=='-'&&i>=1&&s[i+1]>s[i-1]+1)
            {
                for(int k=1;k<=s[i+1]-s[i-1]-1;k++)
                {
                    c[j]=s[i-1]+k;
                    j++;
                }
            }
            
        
        else
        {
            c[j]=s[i];
            j++;
        }
    }
    c[j]='\0';
    printf("%s",c);
}


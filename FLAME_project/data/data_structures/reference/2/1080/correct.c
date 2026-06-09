//
//  main.c
//  text  2
//
//  Created by  on 2021/11/5.
//
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
int main(int argc, char *argv[])
{char s[10000],ans[5000];
    int i=0,a[3000]={0},k=0,j=0,p,flag,ans1;
    gets(s);
    while(s[i]!='='){
        if(s[i]==' '){i++;continue;}
        if(s[i]>='0'&&s[i]<='9')
            a[k]=a[k]*10+(s[i]-'0');
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            ans[j++]=s[i];k++;
        }
        i++;
    }
    for(i=0;i<j;i++){
        if(ans[i]=='*'||ans[i]=='/'){
            flag=i;
        while(ans[i]=='*'||ans[i]=='/'){
            if(ans[i]=='*'){
                p=a[i]*a[i+1];a[i]=p;a[i+1]=p;
            }
            if(ans[i]=='/'){
                p=a[i]/a[i+1];a[i]=p;a[i+1]=p;
            }
            a[flag]=p;i++;}}
    }
    ans1=a[0];
    for(i=0;i<j;i++){
        if(ans[i]=='+')
            ans1+=a[i+1];
        if(ans[i]=='-')
            ans1-=a[i+1];
    }
    printf("%d",ans1);
        return 0;
}



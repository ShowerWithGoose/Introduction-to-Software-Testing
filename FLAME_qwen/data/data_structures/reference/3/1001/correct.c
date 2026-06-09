#include<stdio.h>
#include<string.h>

int main()
{
    int len,len1=0,len2,n=0;
    char s[105];
    gets(s);
    len=strlen(s);
    for(int i=0;s[i]!='.';i++){
        len1++;
    }
    len2=len-len1-1;
    if(len1==1){
        if(s[0]=='0'){
            for(int i=2;s[i]=='0';i++){
                n++;
            }
            n++;
            printf("%c",s[n+1]);
            for(int i=n+2;i<len;i++){
                if(i==n+2){
                    printf(".");
                }
                printf("%c",s[i]);
            }
            printf("e-%d",n);
        }
        else{
            printf("%se0",s);
        }
    }
    else{
        printf("%c.",s[0]);
        for(int i=1;i<len;i++){
            if(i==len1)continue;
            printf("%c",s[i]);
        }
        printf("e%d",len1-1);
    }
    return 0;
}


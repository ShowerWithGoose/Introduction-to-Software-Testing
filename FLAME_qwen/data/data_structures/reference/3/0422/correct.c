#include<stdio.h>
#include<string.h>

int main()
{
    char s[101],ch[101];
    int a=0;

    gets(s);
    if(s[1]=='.'&&s[0]=='0'){
        for(int i=2,j=0,temp=1;i<strlen(s);i++){
            if(temp==0){
                ch[j++]=s[i];
            }
            else if(s[i]!='0'&&s[i]<='9'&&s[i]>'0'){
                ch[j++]=s[i];
                temp=0;
                a=1-i;
            }
        }
        printf("%c",ch[0]);
    if(ch[1]<='9'&&ch[1]>='0')
        printf(".");
    for(int i=1;i<strlen(ch)&&ch[i]<='9'&&ch[i]>='0';i++)
        printf("%c",ch[i]);
    printf("e");
    printf("%d",a);
    return 0;
    }
    else if(s[1]=='.'&&s[0]!='0'){
        for(int i=0,j=0;i<strlen(s);i++){
            if(s[i]!='.'&&s[i]<='9'&&s[i]>='0')
                ch[j++]=s[i];
        }
        printf("%c",ch[0]);
    if(strlen(ch)!=1)
        printf(".");
    for(int i=1;i<strlen(ch)&&ch[i]<='9'&&ch[i]>='0';i++){
        printf("%c",ch[i]);}
    printf("e");
    printf("%d",a);
    return 0;
    }
    else{
        for(int i=0,j=0;i<strlen(s);i++){
            if(s[i]=='.')
                a=i-1;
            else if(s[i]<='9'&&s[i]>='0')
                ch[j++]=s[i];
        }
    }
    printf("%c",ch[0]);
    if(strlen(ch)!=1)
        printf(".");
    for(int i=1;i<strlen(ch)&&ch[i]<='9'&&ch[i]>='0';i++){
        printf("%c",ch[i]);
    }

    printf("e");
    printf("%d",a);
    return 0;
}


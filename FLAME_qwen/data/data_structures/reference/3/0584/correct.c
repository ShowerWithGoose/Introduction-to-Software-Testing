#include<stdio.h>
#include<string.h>
int main(){
    int len,i,flag;
    char in[110];
    gets(in);
    len=strlen(in);
    if(in[0]=='0'){
        for(i=2;in[i]=='0';i++);
        flag=i;
        if(flag==len-1){
        for(i=flag;i<len;i++){
            printf("%c",in[i]);
        }
        printf("e-%d",flag-1);
        }
        else{
            printf("%c.",in[flag]);
            for(i=flag+1;i<len;i++){
                printf("%c",in[i]);
            }
            printf("e-%d",flag-1);
        }
    }
    else if(in[1]=='.'){
        for(i=0;i<len;i++){
            printf("%c",in[i]);
        }
        printf("e0");
    }
    else {
        for(i=1;in[i]!='.';i++);
        flag=i;
        printf("%c.",in[0]);
        for(i=1;i<flag;i++){
            printf("%c",in[i]);
        }
        for(i=flag+1;i<len;i++){
        printf("%c",in[i]);
        }
        printf("e%d",flag-1);
    }
}


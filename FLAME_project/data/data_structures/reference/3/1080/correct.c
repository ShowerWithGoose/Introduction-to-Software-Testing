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
{char s[1000];
    int len,k=0,ans=0;
    scanf("%s",s);
    len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')
        {k=i;break;}
    }
    if(k==1&&s[0]=='0'){
        for(int i=2;i<len;i++){
            if(s[i]!='0'){
                ans=i;
                break;
                
            }
            }
        printf("%c",s[ans]);
        if(ans!=len-1)printf(".");
        for(int i=ans+1;i<len;i++)printf("%c",s[i]);
        printf("e-%d",ans-1);return 0;
            }
    if(k==0){
        if(len==1)
        printf("%c",s[0]);
        else{
            printf("%c.",s[0]);
            for(int i=1;i<len;i++)printf("%c",s[i]);
            printf("e%d",len-1);
        }
        return 0;
        
    }
    printf("%c",s[0]);
    printf(".");
    for(int i=1;i<len;i++){
        if(s[i]!='.')printf("%c",s[i]);
       
    }
    printf("e%d",k-1);        return 0;
}



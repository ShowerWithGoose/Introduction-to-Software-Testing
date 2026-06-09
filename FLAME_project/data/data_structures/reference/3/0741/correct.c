#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 1000000
#define ll long long



int main() {
    char temp[1000],save[1000];
    gets(temp);
    // puts(temp);
    int i,j,k,p,l;

    if(strchr(temp,'.')==NULL){
        puts(temp);
        return 0;
    }

    for(i=0;temp[i]!='\0'&&i<strlen(temp)-1&&temp[i]!='.';i++);
    // printf("i=%d\n",i);
    // printf("%c",temp[i]);
    // 找到小数点

    // 1.小于0
    if(i==1&&temp[0]=='0'){
        // printf("happy");
        for(k=i+1;temp[k]=='0';k++){

        }
        // printf("%d",k);
        printf("%c",temp[k]);
        if(temp[k+1]=='\0'){
            printf("e-%d",k-i);
        }else{
            for(j=k+1,p=0;temp[j]!='\0'&&p==0;j++){
                    if(temp[j]!='0'){
                        p=1;
                    }
                }
                if(p==1){
                    printf(".");
                }
            for(j=k+1;temp[j]!='\0';j++){
                if(temp[j]=='0'){
                    for(l=j,p=1;temp[l]!='\0'&&p;l++){
                        if(temp[l]!='0'){
                            printf("%c",temp[j]);
                            p=0;
                    }
                }
                }else{
                    printf("%c",temp[j]);
                }
            }
            printf("e-%d",k-i);
        }   
    }
    // 2.大于0
    else if(i==1&&temp[0]>'0'){
        for(j=0;temp[j]!='\0';j++){
            if(temp[j]=='0'){
                for(k=j,p=1;temp[k]!='\0'&&p;k++){
                    if(temp[k]!='0'){
                        printf("%c",temp[j]);
                        p=0;
                    }
                }
            }else{
                printf("%c",temp[j]);
            }
        }
        printf("e0");
    }else if(i>1){
        printf("%c.",temp[0]);
        for(j=1;temp[j]!='\0';j++){
            if(temp[j]=='.'){
                continue;
            }
            if(temp[j]=='0'){
                for(l=j,p=1;temp[l]!='\0'&&p;l++){
                    if(temp[l]!='0'){
                        printf("%c",temp[j]);
                        p=0;
                    }
                }
            }else{
                printf("%c",temp[j]);
            }
        }
        printf("e%d",i-1);
    }

    return 0;
}

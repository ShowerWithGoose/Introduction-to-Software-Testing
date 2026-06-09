//
//  expand.c
//  x8x
//
//  Created by Тай on 2022/3/3.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[BUFSIZ],strexp[BUFSIZ];
int i,j,t,k;
int main(){
    scanf("%s",str);
    for (i=0,j=0; i<strlen(str); i++) {
        if (str[i]!='-') {
            strexp[j++]=str[i];
        }
        if (str[i]=='-') {
            if (islower(str[i-1])==islower(str[i+1])&&isdigit(str[i-1])==isdigit(str[i+1])) {
                if (str[i+1]>str[i-1]) {
                    t = str[i+1]-str[i-1];
                    for (int o=1; o<t; o++,j++) {
                        strexp[j]=str[i-1]+o;
                    }
                }
                else strexp[j++] =str[i];
            }
            else{
                strexp[j++] =str[i];
            }
        }
    }
    str[j]='\0';
    printf("%s",strexp);
}




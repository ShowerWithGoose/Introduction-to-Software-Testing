#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[1000];
    int i,front,e,E,c,j,h;
    long long B=0,F=0,sum=0;
    gets(a);
    front=0;
    e=0;
    E=0;
    for(i=0;i<strlen(a);i++){
        if(a[i]=='.'){
            break;
        }
    }
    j=i;
    c=a[0]-'0';
    if(j>1){


            printf("%d.",c);
            for(i=1;i<strlen(a);i++){
                if(i!=j){
                    printf("%c",a[i]);
                }
            }
            h=j-1;
            printf("e%d",h);


    }
    if(j==1&&c!=0){
        printf("%d.",c);
        for(i=2;i<strlen(a);i++){
            printf("%c",a[i]);
        }
        printf("e0");}

    if(j==1&&c==0){

        for(i=2;i<strlen(a);i++){
                if(a[i]>'0'&&a[i]<='9'){
                        h=i-1;
                    break;
                }
        }
       if(i==strlen(a)-1){
        printf("%ce-%d",a[i],h);}
       if(i!=strlen(a)-1){
        printf("%c.",a[i]);
        i++;
        for(;i<strlen(a);i++){
            printf("%c",a[i]);
        }
        printf("e-%d",h);
       }
}}


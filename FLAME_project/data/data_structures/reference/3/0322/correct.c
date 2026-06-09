#include<stdio.h>
#include<string.h>
char a[200];
int main(){
    int i,j=0,mark=0;
    gets(a);
    for(i=0;i<strlen(a);i++){
        if(a[i]=='.'){
            mark=i;
            break;
        }
    }
    if((mark==1)&&(a[0]=='0')){
        for(i=0;i<strlen(a);i++){
            if((a[i]!='0')&&(a[i]!='.')){
                for(j=i;j<strlen(a);j++){
                    if(j==i+1){
                        printf(".");
                    }
                    printf("%c",a[j]);
                }
                break;
            }
        }
        printf("e-%d",i-1);
    }
    else{
        for(j=0;j<strlen(a);j++){
            if(j==1){
                printf(".");
            }
            if(a[j]!='.'){
                printf("%c",a[j]);
            }
        }
        printf("e%d",mark-1);
    }
    return 0;
}

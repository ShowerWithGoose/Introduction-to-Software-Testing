#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    char a1,a2;
    char put;
    int i;
    int flag = 0;
    while((scanf("%c",&put))!=EOF){
       if(put != '-'){
            printf("%c",put);
            a1 = put;
        }
        else{

            scanf("%c",&a2);
            if(islower(a1)){
                if(islower(a2)){
                    flag = 1;
                }
            }
            if(isupper(a1)){
                if(isupper(a2)){
                    flag = 1;
                }
            }
            if(a1>='0'&&a1<='9'){
                if(a2>='0'&&a2<='9'){
                    flag = 1;
                }
            }
            if(flag == 1){
                for(i = a1+1;i<a2;i++){
                    printf("%c",i);
                }
                printf("%c",a2);
            }
            else{
                printf("-%c",a2);
            }
            flag = 0;
            a1 = a2;
        }
    }
    return 0;
}

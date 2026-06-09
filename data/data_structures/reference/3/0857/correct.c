#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[102];
int main(){
    gets(a);
    int i,j;
    int tex,ar,temp;
    if(a[0] == '0'){
        for(i = 2;i < strlen(a);i++){
            if(a[i] != '0'){
                tex = i;
                break;
            }
        }
        printf("%d",a[tex] - '0');
        if(tex < strlen(a) - 1){
            printf(".");
            for(i = tex + 1;i < strlen(a);i++){
                temp = a[i] - '0';
                printf("%d",temp);
            }
        }

        printf("e-");
        printf("%d",tex - 1);
    }
    else{
        printf("%c.",a[0]);
        for(i = 1;i < strlen(a);i++){
            if(a[i] == '.'){
                tex = i;
            }
            else{
                ar = a[i] - '0';
                printf("%d",ar);
            }
        }
        printf("e%d",tex - 1);
    }
    return 0;
}

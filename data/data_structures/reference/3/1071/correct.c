#include <stdio.h>
#include <string.h>
char s[105];
int main(){
    fgets(s,sizeof(s),stdin);
    int strlength = strlen(s);
    int i = 0, j = 0, flag = 0;
    for (i = 0; i < strlength; i++){
        if (s[i] == '.'){
            flag = i;
            break;
        }
    }
    if(flag == 1 && s[0] == '0'){
        for (i = 2; i < strlength; i++){
            if (s[i] == '0'){
                flag = i-1;
            }
            else {
                break;
            }
        }
        if (i == 2){
            flag -= 1;
        }
        for (i = i, j = i; i <= strlength-2; i++){
            if (i != j+1){
                printf("%c",s[i]);
            }
            else{
                printf(".");
                printf("%c",s[i]);
            }
        }
        printf("e-");
        printf("%d\n",flag+1);
    }
    else if(flag == 1 && s[0] != '0'){
        for (i = 0; i < strlength-1; i++){
                printf("%c",s[i]);
        }
        printf("e0\n");
    }
    else if (flag > 1){
        printf("%c.",s[0]);
        for (i = 1; i < strlength-1; i++){
            if (i != flag ){
                printf("%c",s[i]);
            }
        }
        printf("e%d\n",flag-1);
    }
    return 0;
}

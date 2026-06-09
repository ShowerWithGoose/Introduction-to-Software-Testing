#include<stdio.h>
#include<ctype.h>
#include<string.h>
int typejudge(char a,char b){
    if(islower(a)==islower(b)&&islower(a)>=1&&a<b)
    return 1;
    else if(isupper(a)==isupper(b)&&isupper(a)>=1&&a<b)
    return 1;
    else if(a<='9'&&a>='0'&&b<='9'&&b>='0'&&a<b)
    return 1;
    else
    return 0;
}
int main(){
    char s[10000];
    gets(s);
    int i,k;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            if(typejudge(s[i-1],s[i+1])){
                for(k=1;k<s[i+1]-s[i-1];k++){
                    printf("%c",s[i-1]+k);
                }
            }
            else
            printf("%c",'-');
        }
        else
        printf("%c",s[i]);
    }
    getchar();
}

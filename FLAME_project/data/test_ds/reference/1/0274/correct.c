#include<stdio.h>
#include<ctype.h>
void output(char a,char b){
    for(int c=1;a+c<b;c++)
        printf("%c",a+c);
}
int main(){
    char s[1000];
    int i;
    gets(s);
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='-'){
            if((isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<s[i+1])||(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1])||(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<s[i+1]))
                output(s[i-1],s[i+1]);
            else
            printf("-");
        }else
            printf("%c",s[i]);
    }
    return 0;
}



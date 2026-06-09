#include<stdio.h>
#include<string.h>
char s[100];
int jud(char x)
{
    if((x-'0'>=0)&&(x-'0'<=9))return 1;
    else if((x-'A'>=0)&&(x-'A'<=25))return 2;
    else if((x-'a'>=0)&&(x-'a'<=25))return 3;
    else return 0;
}
int main()
{
    gets(s);
    printf("%c",s[0]);
    for(int i=1;s[i]!='\0';i++){
        if(s[i]!='-')printf("%c",s[i]);
        else{
            if(jud(s[i-1])==jud(s[i+1]))
            for(int j=1;(s[i-1]+j)<s[i+1];j++){
                printf("%c",s[i-1]+j);
            }
            else printf("-");
        }
    }
    return 0;
}




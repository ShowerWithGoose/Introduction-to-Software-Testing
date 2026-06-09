#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s);

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1;
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Condition incorrectly checks s[i+2] <= 'Z' without ensuring s[i] <= 'Z'; also logic for type matching is flawed]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [s[i]+2 >= '0' is nonsensical; should check s[i] >= '0'; also fails to properly validate both ends are digits]
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [Loop condition checks i+2 < strlen(s) too late; may access out-of-bounds before this check due to earlier s[i+2] accesses]
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
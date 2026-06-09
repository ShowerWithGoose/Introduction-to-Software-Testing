#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s); // @@ [Using &s is incorrect; s is already a pointer to char array, should be scanf("%s", s);]

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1;
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Condition is malformed: s[i+2]<='Z' appears before ensuring s[i+2]>='A'; also logic for checking uppercase is broken]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [s[i]+2>='0' is wrong; should be s[i+2]>='0']
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [Condition i+2<strlen(s) should be checked BEFORE accessing s[i+2] to avoid out-of-bounds read]
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ [Loop runs one extra iteration; should be j < s[i+2]-s[i] to avoid printing one character beyond s[i+2]]
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause"); // @@ [system("pause") is non-portable and unnecessary; may cause issues in non-Windows environments or when compiling without linking required libraries]
    return 0;
}
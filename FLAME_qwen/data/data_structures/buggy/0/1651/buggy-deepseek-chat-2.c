#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s); // @@ The scanf format specifier %s expects a char* pointer, but &s is a pointer to an array. Use s instead of &s.

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1;
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ The condition is redundant and incorrectly checks s[i+2] twice. It should check s[i] and s[i+2] for uppercase range, but the logic is flawed.
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ The condition has a typo: s[i]+2 should be s[i+2]. Also the logic for checking digit range is incorrect.
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ The condition i+2<strlen(s) should be checked before accessing s[i+2] to avoid out-of-bounds access.
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
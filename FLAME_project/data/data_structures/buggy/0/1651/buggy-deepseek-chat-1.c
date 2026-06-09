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
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ The condition is incorrect: it checks s[i+2] before s[i] for uppercase, and the logic for setting 'a' is flawed. It should check both characters are uppercase letters, but the condition is redundant and the else adds 1 incorrectly, causing 'a' to never be 3 for valid expansions.
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ The condition is incorrect: s[i]+2>='0' is always true for digits, and the logic for setting 'a' is flawed. It should check both characters are digits, but the else adds 1 incorrectly, causing 'a' to never be 3 for valid expansions.
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ The condition a!=3 is wrong; it should be a==0 to indicate all three type checks passed. The current logic sets a to 3 only when all checks fail, so this condition triggers for non-matching types, causing incorrect expansions.
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
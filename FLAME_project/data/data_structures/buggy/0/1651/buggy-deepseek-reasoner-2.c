#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s);

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1; // @@ [Potential out-of-bounds access: s[i+2] may be beyond string length when i is near the end]
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Error: Condition for uppercase is incomplete: missing s[i]<='Z' and s[i+2]>='A'; also redundant checks. Incorrectly allows characters like '0' (between 'A' and 'Z')]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [Error: Condition for digits is incorrect: 's[i]+2>='0'' is nonsensical; also missing s[i]<='9' and s[i+2]>='0'; out-of-bounds access to s[i+2] unchecked]
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ [Error: Loop should be 'j < s[i+2]-s[i]' (exclusive of the endpoint) to match reference behavior; using '<=' prints the end character, which breaks consecutive expansions]
                printf("%c",put+j);
            }i+=2; // @@ [Error: Should be 'i++' to skip only the dash, so that the next character (end of expansion) is processed in the next iteration; i+=2 skips both dash and end character, missing consecutive expansions]


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
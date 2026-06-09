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
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Incorrect condition: missing lower bound for s[i+2] and redundant checks; should be (s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z')]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [Incorrect condition: s[i]+2>='0' is meaningless; should be (s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9')]
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [Potential out-of-bounds access: s[i+2] is accessed before checking i+2<strlen(s); also condition order should place length check first]
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ [Inclusive loop: should be j < s[i+2]-s[i] to exclude the last character, otherwise consecutive expansions are mishandled]
                printf("%c",put+j);
            }i+=2; // @@ [Incorrect increment: should be i+=1 to skip only the hyphen, so next iteration processes the second character; current i+=2 plus loop increment causes skipping of an extra character]


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
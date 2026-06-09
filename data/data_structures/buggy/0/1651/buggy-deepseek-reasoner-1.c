#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s); // @@ [&s is incorrect type; should be s (char*) instead of pointer to array]
    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1; // @@ [accesses s[i+2] without first checking i+2 < strlen(s); also logic incorrectly computes 'a']
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [accesses s[i+2] without bounds check; condition duplicates checks and is logically flawed]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [accesses s[i+2] without bounds check; condition s[i]+2>='0' is meaningless; entire type-checking logic is wrong]
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [bounds check i+2<strlen(s) should be placed before any access to s[i+2] or s[i+1]; condition a!=3 is always true due to flawed 'a' computation]
            
            char put=s[i];
            for(int j=0;j<=s[i+2]-s[i];j++){
                printf("%c",put+j);
            }i+=2; // @@ [should be i+=1 to match reference program; current i+=2 skips the ending character of the expansion, causing errors with consecutive expansions]


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
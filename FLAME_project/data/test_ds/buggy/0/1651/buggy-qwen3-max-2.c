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
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Condition incorrectly checks s[i+2] <= 'Z' twice and misses checking s[i] <= 'Z'; also logic for type matching is flawed]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [s[i]+2 >= '0' is nonsensical; should check s[i] >= '0'; also redundant and incorrect condition]
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [The condition a!=3 is intended to mean "at least one type matches", but due to flawed a calculation, it may trigger expansion for mixed-type ranges like 'g0-' or '0-A']
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ [This prints from s[i] to s[i+2] inclusive, but the problem requires expanding a-d to abcd (i.e., up to but not including the end character in the loop condition of reference). However, note: expected output includes 'g' in a-c-g, so actually full inclusive expansion is needed. But the real issue is that this loop runs even for invalid type combinations due to earlier logic errors.]
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
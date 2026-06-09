#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s); // @@ `&s` should be `s` to correctly pass the character array pointer to `scanf`.

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1;
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ The condition incorrectly repeats checks and misses `s[i]<='Z'` and `s[i+2]>='A'`, failing to properly validate uppercase ranges.
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ Typo `s[i]+2` should be `s[i+2]`, and it misses `s[i]<='9'` and `s[i+2]>='0'`, causing incorrect digit validation.
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ Array indices `s[i+1]` and `s[i+2]` are accessed before checking `i+2<strlen(s)`, risking out-of-bounds access; bounds check should be evaluated first.
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
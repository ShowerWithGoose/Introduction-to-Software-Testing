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
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ Missing lower bound check for s[i+2] (should be s[i+2]>='A') and redundant condition; may incorrectly treat non-uppercase characters as uppercase.
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ Typo: s[i]+2>='0' should be s[i+2]>='0'; this breaks digit type checking.
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ Out‑of‑bounds read: s[i+2] is accessed before checking i+2<strlen(s). Should reorder conditions.
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ Prints the right character inclusively and then i+=2 skips it, causing consecutive expansions to be missed. Should use j < s[i+2]-s[i] and adjust increment.
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
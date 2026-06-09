#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s); // @@ [Using &s is incorrect; s is already a pointer to char array. Should be scanf("%s", s);]

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1;
        if(s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Condition incorrectly written as s[i]>='A'&&s[i+2]<='Z' twice; should check both s[i] and s[i+2] are in [A-Z]]
        if(s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [Typo: wrote s[i]+2>='0' instead of s[i]>='0']
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [Boundary check i+2<strlen(s) should come before accessing s[i+2] to prevent out-of-bounds access]
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ [Loop runs one extra iteration; should be j < s[i+2]-s[i] to avoid printing one character beyond s[i+2]]
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause"); // @@ [system("pause") is non-portable and unnecessary; may cause issues on non-Windows systems]
    return 0;
}
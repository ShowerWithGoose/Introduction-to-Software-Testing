#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s); // @@ Using &s is incorrect; s is already a pointer to char array, should be scanf("%s", s);

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1;
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ Condition s[i]>='A' is repeated unnecessarily and logic is flawed; also missing bounds check before accessing s[i+2]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ s[i]+2>='0' is wrong; should be s[i]>='0'; also accessing s[i+2] without ensuring i+2 < strlen(s)
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ Bounds check i+2<strlen(s) should come before accessing s[i+2] to prevent out-of-bounds read
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ Loop runs one extra iteration (should be j < s[i+2]-s[i]) because it includes both endpoints already via starting at s[i]
                printf("%c",put+j);
            }i+=2;


        } else printf("%c",s[i]);

    }
    

    system("pause"); // @@ system("pause") is non-portable and unnecessary; may cause issues in non-Windows environments or when compiling without linking required libraries
    return 0;
}
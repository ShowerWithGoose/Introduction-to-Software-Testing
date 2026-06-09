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
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1;
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ Typo: s[i]+2 should be s[i] to correctly check if the starting character is a digit.
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){ // @@ Loop condition should use < instead of <= to avoid printing the end character of the range, which needs to be processed separately for chained expansions.
                printf("%c",put+j);
            }i+=2; // @@ Should be i++ instead of i+=2. Incrementing by 2 skips the character after '-', breaking the processing of chained ranges like a-c-g.


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}
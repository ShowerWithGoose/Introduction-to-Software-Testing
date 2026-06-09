#include<stdio.h>

int main()
{
    char s[101];
    int i=0,j=0;

    scanf("%s",s);
    for(;s[i]!='\0';i++){
        if(s[i]<='9'&&s[i]>='0'||s[i]<='Z'&&s[i]>='A'||s[i]<='z'&&s[i]>='a'){
            printf("%c",s[i]);
        }
        else if(s[i]=='-'){
            if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0'&&s[i-1]<s[i+1]){
                for(j=1;s[i-1]+j<s[i+1];j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a'&&s[i-1]<s[i+1]){
                for(j=1;s[i-1]+j<s[i+1];j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A'&&s[i-1]<s[i+1]){
                for(j=1;s[i-1]+j<s[i+1];j++)
                    printf("%c",s[i-1]+j);
            }
            else
                printf("%c",s[i]);
        }
    }
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[1024];
    int i,j,p;
    gets(s);
    p=strlen(s);
    for(i=0;i<p;){
        printf("%c",s[i]);
        if((s[i+1]=='-')&&((s[i]>='a'&&s[i+2]>s[i])||(s[i]>='A'&&s[i]<'Z'&&s[i+2]<='Z'&&s[i+2]>s[i])||(s[i]>='0'&&s[i]<'9'&&s[i+2]>s[i]&&s[i+2]<='9'))){
            for(j=1;j<s[i+2]-s[i];j++){
                printf("%c",s[i]+j);
            }
            i+=2;
        }
        else
            i++;
    }
    return 0;
}


#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!='-') printf("%c",s[i]);
        else {
            if(isdigit(s[i-1])&&isdigit(s[i+1])){
                for(char c=s[i-1]+1;c!=s[i+1];c++)
                    printf("%c",c);
            }
            else if(isupper(s[i-1])&&isupper(s[i+1])){
                for(char c=s[i-1]+1;c!=s[i+1];c++)
                    printf("%c",c);
            }
            else if(islower(s[i-1])&&islower(s[i+1])){
                for(char c=s[i-1]+1;c!=s[i+1];c++)
                    printf("%c",c);
            }
            else printf("-");
        }
    }
    return 0;
}

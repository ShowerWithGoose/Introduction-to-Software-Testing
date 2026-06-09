#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str);
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){ // @@ Loop condition ends too early; does not process last two characters correctly, causing '-' to be printed unnecessarily.
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2])
            { // @@ Condition does not properly verify that both characters are in the same valid range; it only checks one bound each.
                int flag=str[i+2]-str[i]; // @@ Flag should be difference+1 to include the ending character in the expansion.
                    for(int j=0;j<flag;j++){ // @@ Loop runs flag times, missing the last character (should be j<=flag).
                        printf("%c",str[i]+j);
                    }
                    i++;
            }
            else{
                printf("%c",str[i]);
                printf("-");
                i++;
            }
        }
    }
    printf("%c%c",str[leng-2],str[leng-1]); // @@ Unconditionally prints the last two characters; after an expansion ending at the end, this prints '-' and the final character incorrectly.

}
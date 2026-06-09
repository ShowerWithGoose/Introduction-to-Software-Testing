#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str);
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){ // @@ Loop condition should handle expansions correctly; currently skips printing right character and may cause duplication.
        if(str[i+1]!='-')
        printf("%c",str[i]); // @@ Printing left character here without checking if next is dash; duplicates printing inside expansion block.
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ Condition does not enforce that both characters are of same type; e.g., 'a' and 'Z' would mistakenly be treated as expansion.
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){
                        printf("%c",str[i]+j); // @@ Prints left character again and intermediate characters, but does not print right character; also duplicates left char.
                    }
                    i++; // @@ Unnecessary increment skips the character after dash, causing missing output.
            }
            else{
                printf("%c",str[i]); // @@ Prints left character again when expansion should not occur.
                printf("-");
                i++; // @@ Skips the character after dash, causing missing output.
            }
        }
    }
    printf("%c%c",str[leng-2],str[leng-1]); // @@ Prints last two characters unconditionally, which may produce extra or incorrect output in the presence of dashes.

}
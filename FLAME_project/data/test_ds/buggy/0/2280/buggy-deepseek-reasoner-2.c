#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str);
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){ // @@ The loop condition prevents processing the last two characters properly; when a '-' appears at the second-to-last position, its expansion is not handled, and the following unconditional print of the last two characters may output an extra '-'.
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ The condition for matching character types is incorrect; it only checks one bound for each character. For example, it would incorrectly treat 'a' and '9' as valid because 'a'>='A' is true and '9'<='z' is true. It should check both characters fall within the same range.
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){ // @@ The loop prints only up to flag-1, missing the last character. For example, 'B' to 'F' prints B,C,D,E but not F. Should be j<=flag.
                        printf("%c",str[i]+j);
                    }
                    i++;
            }
            else{
                printf("%c",str[i]);
                printf("-"); // @@ When a '-' is not expanded, this prints the '-' immediately, but later the final unconditional print will also print the same '-' (and possibly the following character incorrectly), leading to double printing or wrong output.
                i++;
            }
        }
    }
    printf("%c%c",str[leng-2],str[leng-1]); // @@ This unconditional print of the last two characters does not account for the possibility that they may have already been printed during expansion. It may print a stray '-' if the last '-' was expanded, or reprint characters incorrectly.
}
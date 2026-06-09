#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; also, the logic fails to handle cases where '-' appears at the end or beginning]
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){ // @@ [Loop condition stops too early; fails to process last two characters properly when no '-' is involved]
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ [Incorrect range checks: e.g., 'str[i]>='0' && str[i+2]<='9'' does not ensure both are digits; should check both ends belong to same category]
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){ // @@ [This prints from str[i] to str[i+2]-1 inclusive, but should print from str[i]+1 to str[i+2]-1; also prints the starting character again which was already printed]
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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ [Assumes string length >=2; crashes on short strings. Also duplicates printing of characters that may have already been handled in loop]
}
#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers that remove 'gets' entirely]
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ [Incorrect range checks: e.g., 'str[i]>='0' && str[i+2]<='9'' does not ensure both are digits; should check both ends belong to same category]
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){ // @@ [Loop prints from str[i] to str[i+2]-1 inclusive, but should print from str[i]+1 to str[i+2]-1; also includes the starting character again which was already printed]
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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ [Assumes string length >=2; fails for empty or single-character input. Also, last two characters are always printed without processing possible '-' at position leng-2]
}
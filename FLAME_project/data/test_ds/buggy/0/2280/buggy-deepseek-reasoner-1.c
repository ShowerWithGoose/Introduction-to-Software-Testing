#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str);
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){
        if(str[i+1]!='-')
            printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2])
            {
                int flag=str[i+2]-str[i];
                for(int j=0;j<flag;j++){ // @@ Loop condition should be j<=flag to include the last character of the expansion (e.g., 'F' in "B-F"). Currently it prints only up to str[i+2]-1, causing the last character to be missing.
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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ Unconditionally prints the last two characters, but when the last character is part of an expansion (e.g., 'F' in "B-F"), this prints an extra hyphen and possibly a duplicate character. It should only print characters that have not been printed already.
}
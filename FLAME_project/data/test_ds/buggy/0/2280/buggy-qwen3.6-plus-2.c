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
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ Incorrect range validation logic; it should verify that both str[i] and str[i+2] fall within the same specific range (e.g., both digits, both uppercase, or both lowercase) rather than mixing bounds.
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){ // @@ The loop condition j<flag excludes the end character str[i+2]; it should be j<=flag to include the full expansion range.
                        printf("%c",str[i]+j);
                    }
                    i++; // @@ Should be i+=2 to skip the '-' and the end character after expansion, preventing them from being printed again in subsequent iterations or by the trailing printf.
            }
            else{
                printf("%c",str[i]);
                printf("-");
                i++;
            }
        }
    }
    printf("%c%c",str[leng-2],str[leng-1]); // @@ Unconditionally prints the last two characters, which causes duplicate or incorrect output (like "-F") when the string ends with a valid expansion.

}
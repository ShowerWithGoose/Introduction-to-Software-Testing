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
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ Incorrect range checking logic. It should verify that both str[i] and str[i+2] are within the same specific range (e.g., both digits, both uppercase, or both lowercase). The current condition only checks a lower bound for str[i] and an upper bound for str[i+2], which can lead to false positives.
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){
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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ Unconditionally prints the last two characters, causing duplicate or incorrect output when expansion occurs at the end. The loop should handle printing all characters, or this line should be adjusted to print only the remaining unprocessed characters.

}